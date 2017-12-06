#include "2.menu.h"
#include "3.menu.h"

#include "2.partida.h"

#include "3.debug.h"

void menu(void){
	on.screenRefresh = menuView;
	on.click = menuOnClick;
	
	if(false)//se for pra começar a partida
		controle.principal = partida;
	
	if(false)//se for pra encerrar
		on.quit();
		
	
}

void menuOnClick(void){
	//println("Clicou!");
	int x, y;
	
	
	SDL_GetMouseState(&x,&y);
	
	controle.principal = partida;
	
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

