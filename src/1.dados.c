#include "1.dados.h"

/* Global Variables */
Janela janela = NULL; //The window we'll be rendering to
Surface screenSurface = NULL; //The surface contained by the window
Surface sprites[ncores]; //Vetor de imagens :^)

Surface menuOverNot; //Fundo do menu
Surface menuOverPlay; //Fundo do menu
Surface menuOverExit; //Fundo do menu
Surface menuCredits0;
Surface menuCredits1;
Surface sound0;
Surface sound1;
Surface partidaExit0;
Surface partidaExit1;
Surface partidaBg[5];
Surface partidaHud;
Surface partidaMenu0;
Surface partidaMenu1;
Surface blackRect;
Surface fimFundo;
Surface fimOverScores0;
Surface fimOverScores1;
Surface fimExit0;
Surface fimExit1;
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
