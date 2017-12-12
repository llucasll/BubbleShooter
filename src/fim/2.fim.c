#include "../1.dados.h"

#include "2.fim.h"
#include "3.fim.h"
#include "../3.visualizacao.h"

#include "../menu/2.menu.h"
#include "../partida/2.partida.h"
#include "../partida/3.partida.h"

static voidvoid *animacao;

void vitoria(void){
	animacao = vitoriaView;
	estourando = true;
	fim();
}

void derrota(void){
	animacao = derrotaView;
	fim();
}

void fim(void){
	exibeScores=false;

	fimExit = fimExit0;
	//botaoMenu = partidaMenu0;

	on.click = NULL;
	on.mouseMove = NULL;

	for(int i=0; i<4; i++){
		on.screenRefresh = animacao;
		usleep(400000); fflush(stdout);

		on.screenRefresh = partidaView;
		usleep(200000); fflush(stdout);
	}

	on.screenRefresh = fimView;
	on.click = fimOnClick;
	on.mouseMove = fimOnMouseMove;

	on.run = NULL;
}

void fimOnClick(void){
	Coordenadas pos = getMousePos();

	/*if(pos.x>=257 && pos.x<=392 &&
		 pos.y>=300 && pos.y<=385){
			on.run = menu;
			return;
	}*/
	if(pos.x>=594 && pos.x<=648 &&
		 pos.y>=426 && pos.y<=480){
			 on.stop();
			 return;
	}
	else if(pos.x>=0 && pos.x<=54 && pos.y>=426 && pos.y<=480){
		if(musicaOn){
			Mix_VolumeMusic(0);
			musicaOn = false;
		}
		else if(!musicaOn){
			Mix_VolumeMusic(100);
			musicaOn = true;
		}
	}
	else{
		on.run = menu;
		return;
	}
	return;
}

void fimOnMouseMove(Coordenadas pos){
	if(pos.x>=594 && pos.x<=648 && pos.y>=426 && pos.y<=480){
		fimExit = fimExit1;
	}
	//else if(pos.x>=535 && pos.x<=589 && pos.y>=426 && pos.y<=450){
	//	botaoMenu = partidaMenu1;
	//}
	else if(pos.x>=10 && pos.x<=150 && pos.y>=10 && pos.y<=50){
		exibeScores = true;
	}
	else{
		fimExit = fimExit0;
		//botaoMenu = partidaMenu0;
		exibeScores = false;
	}
	return;
}
