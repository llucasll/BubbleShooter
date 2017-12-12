#include "1.dados.h"

/* Global Variables */
Janela janela = NULL; //The window we'll be rendering to
Surface screenSurface = NULL; //The surface contained by the window

struct _visualizacao{
	
	struct{
		/* FUNDOS DO MENU */
		Surface overNot;
		Surface overPlay;
		Surface overExit;
	}menu;
	
	struct{
		Surface sprites[ncores]; //Vetor de imagens :^)

		Surface bg[5]; // Backgrounds
		Surface hud; // Barra inferior

		/* BOTÕES DA PARTIDA */
		Surface exit0;
		Surface exit1;
		Surface menu0;
		Surface menu1;
	}partida;
};

struct _visualizacao view;

byte bgIndex;
bool partidaExitStatus;
bool partidaMenuStatus;
bool estourando;
bool musicPlay;
TTF_Font* fonte;
SDL_Color ttfCor;
Surface msgPontos;
int score;
char scoreString[scoreDigit];

Surface menuFundo; //Fundo do menu
Mix_Music *musica = NULL;

struct _medidas tam = {//TODO
	{648, 480},//tela
	//{30, 10},//campo
	{37, 37},//bola
	6
};
