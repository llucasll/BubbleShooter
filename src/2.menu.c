#include "2.menu.h"
#include "3.menu.h"

#include "2.partida.h"

#include "3.debug.h"

void menu(void){
	on.screenRefresh = menuView;
	on.click = menuOnClick;
	on.mouseMove = menuMouseMove;

	menuOver = menuOverNot;

	//if(controle.principal == partida){ //se for pra começar a partida
		bgIndex = rand()%5;
	//	return;
	//}
	if(false){ //se for pra encerrar
		on.quit();
		return;
	}
	controle.principal = NULL;
}

void menuMouseMove(Coordenadas pos){
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
	//println("Clicou!");
	Coordenadas pos = getMousePos();

	if(pos.x>=257 && pos.x<=392 &&
		 pos.y>=300 && pos.y<=385){
			controle.principal = partida;
	}
	if(pos.x>=594 && pos.x<=648 &&
		 pos.y>=426 && pos.y<=480){
			 quit=true;
	}
	//printf("\n%d,%d\n",x,y);

	/*
	x -= (tam.tela.x)/2;
	y -= (tam.tela.y)-((tam.bola.y)/2);

	double d = sqrt( pow(x,2) + pow(y,2) );

	tiro.vel.x = x/d;
	tiro.vel.y = y/d;

	on.click = NULL;//TODO experimenta tirar essa linha
	*/
}
