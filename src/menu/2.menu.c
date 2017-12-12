#include "2.menu.h"
#include "3.menu.h"

#include "../partida/2.partida.h"
#include "../3.visualizacao.h"

bool credits;

void menu(void){
	on.screenRefresh = menuView;
	on.click = menuOnClick;
	on.mouseMove = menuOnMouseMove;

	menuOver = menuOverNot;
	credits = false;

	bgIndex = rand()%5;

	on.run = NULL;
}

void menuOnMouseMove(Coordenadas pos){
	//135,85 257,200
	//54,54 594,426

	if(pos.x>=257 && pos.x<=392 && pos.y>=300 && pos.y<=385){
		menuOver = menuOverPlay;
	}
	else if(pos.x>=594 && pos.x<=648 && pos.y>=426 && pos.y<=480){
		menuOver = menuOverExit;
	}
	else{
		menuOver = menuOverNot;
	}
	if(pos.x>=297 && pos.x<=351 && pos.y>=426 && pos.y<=480) credits = true;
	else credits = false;
}

void menuOnClick(void){
	Coordenadas pos = getMousePos();

	if(pos.x>=257 && pos.x<=392 &&
		 pos.y>=300 && pos.y<=385){
			on.run = partida;
			return;
	}
	else if(pos.x>=594 && pos.x<=648 &&
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
		return;
	}
}
