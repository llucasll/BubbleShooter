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

/* TODO debug
byte contar(int x, int y){
	byte cor = obter(x,y)->cor;
	int count = 0;

	Bola** vizinho = getVizinhos(x,y);

	for(int i=0; i<6; i++){
		println("ptr %d",vizinho[i]);
		if(vizinho[i]){
			println("EXISTE: %d",vizinho[i]->existe);
			if(vizinho[i]->existe){
				println("cor: %d",vizinho[i]->cor);
				println("cor ==: %d",vizinho[i]->cor ==cor);
				if(vizinho[i]->cor == cor){
					count++;
				}
			}
		}
		//printnl();
	}
	if(count>1){
		oi();
		liberaVizinhos(&vizinho);
		return 2;
	}
	else if(count==1)
		for(int i=0; i<6; i++)
			if(vizinho[i]){ if(vizinho[i]->existe){ if(vizinho[i]->cor == cor){
				Bola** vizinho2 = getVizinhos(vizinho[i]->pos.x,vizinho[i]->pos.y);
				for(int j=0; j<6; j++)
					if(vizinho2[j]){ if(vizinho2[j]->existe){ if(vizinho2[j]->cor == cor){
						oi();
						liberaVizinhos(&vizinho);
						liberaVizinhos(&vizinho2);
						return 3;
					}}}
			}}}
	return count;//
}

*/

bool contar(int x, int y){
	byte cor = obter(x,y)->cor;
	int count = 0;

	Bola** vizinho = getVizinhos(x,y);

	for(int i=0; i<6; i++){
		if(vizinho[i]) if(vizinho[i]->existe) if(vizinho[i]->cor == cor)
			count++;
		if(count>1){
			//oi();
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
						//oi();
						liberaVizinhos(&vizinho);
						liberaVizinhos(&vizinho2);
						return true;
					}
				}
				liberaVizinhos(&vizinho2);
			}
	liberaVizinhos(&vizinho);
	return false;//
}

static void move(int x1, int y1, int x2, int y2){//x1 = x2
	//println("%d,%d\t%d,%d",x1,y1,x2,y2);
	if(valido(x1,y1) && valido(x2,y2)){
		/*println("%d\t%d",matriz[y1][x1].cor, matriz[y2][x2].cor);*/
		matriz[y1][x1].cor = matriz[y2][x2].cor;
		//matriz[y1][x1].x = matriz[y2][x2].x;
		//matriz[y1][x1].y = matriz[y2][x2].y;
		//matriz[y1][x1].pos.x = matriz[y2][x2].pos.x;
		//matriz[y1][x1].pos.y = matriz[y2][x2].pos.y;
		matriz[y1][x1].morreu = matriz[y2][x2].morreu;
		matriz[y1][x1].existe = matriz[y2][x2].existe;

		//matriz[y1][x1] = matriz[y2][x2];
		/*println("%d,%d\t%d,%d",x1,y1,x2,y2);
		println("%d\t%d",matriz[y1][x1].cor, matriz[y2][x2].cor);
		printnl();*/
		//matriz[y][x] = matriz[y-1][x];
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

/*

float distancia(Bola* b, Tiro t){
	//println("%d",b);
	//oi();
	//pow(((int)b->x)-(t.x),2);
	return sqrt(pow(b->x-t.x,2)+pow(b->y-t.y,2));
}

bool colidiu(int x, int y){
	//oi();
	if(existe(x,y))
		if(distancia(obter(x,y),tiro)<tam.bola.x)
			return true;

	else return false;
}
*/
