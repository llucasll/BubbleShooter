#include "1.mecanica.h"
#include "../3.visualizacao.h"

#include "3.debug.h"

bool habitavel(int x, int y){
	if(existe(x+1,y)||existe(x-1,y))
		return true;
	if(existe(x,y+1)||existe(x,y-1))
		return true;
	if(y%2){
		if(existe(x+1,y+1)||existe(x+1,y-1))
			return true;
	}
	else{
		if(existe(x-1,y+1)||existe(x-1,y-1))
			return true;
	}
	return false;
}

bool colisao( Bola* b, Tiro* t){
	if(sqrt(pow(b->x-t->x,2)+pow(b->y-t->y,2))<=tam.bola.x-3 && b->existe==true){
		return 1;
	}
	return 0;
}

void preencheAcheque(void){
	int i, j;
	for(i=0;i<colunas;i++){
		for(j=0;j<linhastotal;j++){
			//printf("a");
			if(existe(i,j))
				matriz[j][i].acheque=true;
		}
	}
}
bool checaAcheque(void){
	int i, j;
	for(i=0;i<colunas;i++){
		for(j=0;i<linhastotal;j++){
			if(&matriz[j][i]) if(matriz[j][i].existe) if(matriz[j][i].acheque) return 1;
		}
	}
	return 0;
}
bool checkIlha(Bola *b) {
	if(b->acheque){
		int i,j;
		Bola** vizinho = getVizinhos(b->pos.x,b->pos.y);

		b->acheque = false;

		if(!b->pos.y) return false;

		for(i=0;i<6;i++){
			if(vizinho[i]) if(vizinho[i]->existe) if(vizinho[i]->acheque){
				if(!checkIlha(vizinho[i])) return false;
			}
		}
		return true;
	}
	else return true;
}

bool contar(int x, int y){
	byte cor = obter(x,y)->cor;
	int count = 0;

	Bola** vizinho = getVizinhos(x,y);

	for(int i=0; i<6; i++){
		if(vizinho[i]) if(vizinho[i]->existe) if(vizinho[i]->cor == cor)
			count++;
		if(count>1){
			liberaVizinhos(&vizinho);
			return true;
		}
	}
	if(count==1)
		for(int i=0; i<6; i++)
			if(vizinho[i]) if(vizinho[i]->existe) if(vizinho[i]->cor == cor){
				Bola** vizinho2 = getVizinhos(vizinho[i]->pos.x,vizinho[i]->pos.y);
				int count2 = 0;
				for(int j=0; j<6; j++){
					if(vizinho2[j]) if(vizinho2[j]->existe) if(vizinho2[j]->cor == cor)
						count2++;
					if(count2>1){
						liberaVizinhos(&vizinho);
						liberaVizinhos(&vizinho2);
						return true;
					}
				}
				liberaVizinhos(&vizinho2);
			}
	liberaVizinhos(&vizinho);
	return false;
}

static void move(int x1, int y1, int x2, int y2){//x1 = x2
	if(valido(x1,y1) && valido(x2,y2)){
		matriz[y1][x1].cor = matriz[y2][x2].cor;
		//matriz[y1][x1].x = matriz[y2][x2].x;
		//matriz[y1][x1].y = matriz[y2][x2].y;
		//matriz[y1][x1].pos.x = matriz[y2][x2].pos.x;
		//matriz[y1][x1].pos.y = matriz[y2][x2].pos.y;
		matriz[y1][x1].morreu = matriz[y2][x2].morreu;
		matriz[y1][x1].existe = matriz[y2][x2].existe;
	}
	for(int x=0; x<colunas; x++)
		insere(x,0,sortear());
}

void descer(void){
	for(int y=linhastotal; y; y--)
		for(int x=0; x<colunas; x++)
			move(x,y,x,y-1);
	exibeMatriz(
		lambda(
			char*, (Bola b) {
				char* saida;
				saida = malloc(sizeof(char)*10);

				/* COORDENADAS NA TELA */
				//sprintf(saida,"%d,%d",b.x,b.y);

				/* COORDENADAS NA MATRIZ (getLinha/getColuna) */
				//if(existe(getLinha(b.y),getColuna(b.x,b.y)))
				//sprintf(saida,"%d,%d",getColuna(b.x,b.y),getLinha(b.y));

				/* COR */
				sprintf(saida,"%d",b.cor);

				/* EXISTE */
				//sprintf(saida,"%d",b.existe);

				return saida;
			}
		)
	);
}
