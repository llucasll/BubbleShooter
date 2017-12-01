#include "1.dados.h"
#include "1.mecanica.h"

#include "2.partida.h"
#include "3.partida.h"

void partida(void){
	
	on.screenRefresh = partidaView;
	on.mouseClick = partidaOnClick;
	
	//Create NPC
	createNPC(
		(tam.tela.x - tam.bola.x)/2, 
		(tam.tela.y - tam.bola.y), 
		0, 
		0
	);		
	
	//While application is running
	while( !quit ) {
		moveNPC();
			
		//Not so good solution, depends on your computer
		SDL_Delay(5);
	}
}

void partidaOnClick(){
	bool pri = true; /* SÓ O PRIMEIRO CLIQUE TEM VALIDADE */
	if(pri){
		int x, y;
		SDL_GetMouseState(&x,&y);

		x -= (tam.tela.x)/2;
		y -= (tam.tela.y)-((tam.bola.y)/2);
	
		double d = sqrt( pow(x,2) + pow(y,2) );
	
		tiro.vel.x = x/d;
		tiro.vel.y = y/d;

		pri = false;
	}
}

void moveNPC() {
	
	tiro.x += tiro.vel.x;
	tiro.y += tiro.vel.y;
	
	if ( (tiro.x + tam.bola.x > tam.tela.x) ||
		 (tiro.x < 0) ) {
		tiro.vel.x = -tiro.vel.x;
		tiro.x += tiro.vel.x; 
	}
	if (tiro.y + tam.bola.y > tam.tela.y) {
		tiro.vel.y = -tiro.vel.y;
		tiro.y += tiro.vel.y;
	}
	
	if (tiro.y < 0) {
		quit = true;
	}
}

/* Create NPC */
void createNPC( int x, int y, int velx, int vely) {
	tiro.x = x;
	tiro.y = y;
	tiro.vel.x = velx;
	tiro.vel.y = vely;	
}
