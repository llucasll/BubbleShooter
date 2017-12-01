#include "1.dados.h"

/* GLOBAIS */
const Coordenadas campo = {colunas, linhas}, npc = {61, 61}, tela = {640, 480};//tamanhos
Coordenadas velocidade;
Bola *matriz[linhas][colunas];
Tiro tiro;

/* Global Variables */
Janela janela = NULL; //The window we'll be rendering to
Surface screenSurface = NULL; //The surface contained by the window
Surface gJPGSurface = NULL; //Current displayed PNG image

//bool quit = false; //Main loop flag

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

struct{
	int nada;
}nada;

struct _medidas tam = {
	{640, 480},//tela
	{},//campo
	{61, 61}//bola
};

