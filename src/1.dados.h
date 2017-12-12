#include "0.cabecalho.h"

#ifndef GLOBAIS
	#define GLOBAIS

	/* GLOBAIS */

	struct _medidas{
		Coordenadas tela;
		//Coordenadas matriz;//TODO ainda não em uso
		Coordenadas bola;
		byte cores;
	}extern tam;

	extern int score;
	extern char scoreString[scoreDigit];

	extern Surface sprites[ncores]; //Vetor de imagens :^)
	extern Coordenadas velocidade;

	extern Surface menuOverNot;
	extern Surface menuOverExit;
	extern Surface menuOverPlay;
	extern Surface menuCredits0;
	extern Surface menuCredits1;
	extern Surface sound0;
	extern Surface sound1;
	extern Surface partidaExit0;
	extern Surface partidaExit1;
	extern Surface partidaBg[5];
	extern Surface partidaHud;
	extern Surface partidaMenu0;
	extern Surface partidaMenu1;
	extern Surface partidaGridVida;
	extern Surface partidaVida;
	extern Surface blackRect;
	extern Surface fimFundo;
	extern Surface fimOverScores0;
	extern Surface fimOverScores1;
	extern Surface fimExit0;
	extern Surface fimExit1;
	extern bool partidaMenuStatus;
	extern bool partidaExitStatus;
	extern bool estourando;
	extern bool musicPlay;
	extern byte bgIndex;

	extern Surface menuFundo;
	extern Mix_Music* musica;
	extern TTF_Font* fonte;
	extern SDL_Color ttfCor;
	extern Surface msgPontos;

#endif
