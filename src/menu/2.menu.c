#include "2.menu.h"
#include "3.menu.h"

#include "../partida/2.partida.h"
#include "../3.visualizacao.h"

void menu(void){
	on.screenRefresh = menuView;
	on.click = menuOnClick;
	on.mouseMove = menuOnMouseMove;

	menuOver = menuOverNot;

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
}

void menuOnClick(void){
	Coordenadas pos = getMousePos();

	if(pos.x>=257 && pos.x<=392 &&
		 pos.y>=300 && pos.y<=385){
			on.run = partida;
			return;
	}
	if(pos.x>=594 && pos.x<=648 &&
		 pos.y>=426 && pos.y<=480){
			 on.stop();
			 return;
	}
}
