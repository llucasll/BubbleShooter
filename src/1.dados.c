#include "1.dados.h"

/* GLOBAIS */
const Coordenadas campo = {30, 10}, npc = {61, 61}, tela = {640, 480};//tamanhos
Coordenadas velocidade;
Bola matriz[linhas][colunas];//Bola **matriz;
Tiro tiro;

/* Global Variables */
Janela janela = NULL; //The window we'll be rendering to
Surface screenSurface = NULL; //The surface contained by the window
Surface gJPGSurface = NULL; //Current displayed PNG image
Surface gcolorSurface[ncores]; //Vetor de imagens :^)

byte sortear(void){
	return rand() % tam.cores;
	//return 0;
	//return rand() % tam.cores;
}

bool insere(byte b, int x, int y){

}
bool remover(int x, int y){
}

int getLinha(Bola b){
	return (int) b.x/npc.x;
}

int getColuna(Bola b, int linha){
	return (int) (linha%2 ? b.y-npc.y/2 : b.y)/npc.y;
}

struct _medidas tam = {//TODO
	{648, 480},//tela
	//{30, 10},//campo
	{37, 37},//bola
	6
};
