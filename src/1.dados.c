#include "1.dados.h"

/* GLOBAIS */
Coordenadas velocidade;
Bola matriz[linhas][colunas];//Bola **matriz;
Tiro tiro;

/* Global Variables */
Janela janela = NULL; //The window we'll be rendering to
Surface screenSurface = NULL; //The surface contained by the window
Surface sprites[ncores]; //Vetor de imagens :^)

byte sortear(void){
	return rand() % tam.cores;
}

bool insere(byte b, int x, int y){

}
bool remover(int x, int y){
}

int getLinha(Bola b){
	return (int) b.x/tam.bola.x;
}

int arredonda(int dividendo, int divisor){
	int resultado = divisor?dividendo/divisor:0;
	return (int) divisor*resultado < dividendo? resultado+1 : resultado;
}

int getColuna(Bola b, int linha){
	/*int tmp = linha%2 ? b.y-(tam.bola.y*0.9)/2 : b.y;
	if(tmp / tam.bola.y){
		tmp /= (tam.bola.y*0.9);
		tmp +=1;
	}
	else
		tmp /= tam.bola.y;
	//printf("%d\t%d", tmp,linha);
	return (int) tmp;*/
	return (int) arredonda((linha%2 ? b.y-(tam.bola.y/**0.9*/)/2 : b.y), (tam.bola.y/**0.9*/));
}

struct _medidas tam = {//TODO
	{648, 480},//tela
	//{30, 10},//campo
	{37, 37},//bola
	6
};
