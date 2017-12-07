#include "2.menu.h"
#include "3.menu.h"

#include "2.partida.h"

#include "3.debug.h"

void menu(void){
	on.screenRefresh = menuView;
	on.click = menuOnClick;

	if(controle.principal == partida){ //se for pra começar a partida
		bgIndex = rand()%5;
		return;
	}
	if(false){ //se for pra encerrar
		on.quit();
		return;
	}
}

void menuOnClick(void){
	//println("Clicou!");
	int x, y;

	SDL_GetMouseState(&x,&y);

	if(x>=257 && x<=392 &&
		 y>=300 && y<=385){
			controle.principal = partida;
	}
	if(x>=594 && x<=648 &&
		 y>=426 && y<=480){
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

int menuGetStatus(void){
	int x, y;
	SDL_GetMouseState(&x,&y);

	//135,85 257,200
	//54,54 594,426

	if(x>=257 && x<=392 && y>=300 && y<=385){
		return 1;
	}
	else if(x>=594 && x<=648 && y>=426 && y<=480){
		return 2;
	}
	else{
		return 0;
	}
	return 0;
}
