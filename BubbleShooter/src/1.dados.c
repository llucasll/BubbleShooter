#include "1.dados.h"

/* GLOBAIS */
const Coordenadas campo = {30, 10}, npc = {61, 61}, tela = {640, 480};//tamanhos
Coordenadas velocidade;
//Bola *matriz[tam.matriz.x][tam.matriz.y];
Bola ***matriz;
Tiro tiro;
//int ***teste;
	/*
		teste = malloc(sizeof(int)*10);
		println("%d",teste[4]);
	*/

/* Global Variables */
Janela janela = NULL; //The window we'll be rendering to
Surface screenSurface = NULL; //The surface contained by the window
Surface gJPGSurface = NULL; //Current displayed PNG image

bool iniciarJogo(void){//iniciar globais; preparar jogo
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
	{640, 480},//tela
	{30, 10},//campo
	{61, 61}//bola
};

