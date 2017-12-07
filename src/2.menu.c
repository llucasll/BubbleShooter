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
	controle.principal = NULL;
}

void menuOnClick(void){
	//println("Clicou!");
	Coordenadas c = mousePos();

	if(c.x>=257 && c.x<=392 &&
		 c.y>=300 && c.y<=385){
			controle.principal = partida;
	}
	if(c.x>=594 && c.x<=648 &&
		 c.y>=426 && c.y<=480){
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
