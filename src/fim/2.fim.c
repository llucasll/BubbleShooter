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
	on.click = NULL;
	on.mouseMove = NULL;
	
	for(int i=0; i<4; i++){
		on.screenRefresh = animacao;
		usleep(500000); fflush(stdout);
		
		on.screenRefresh = partidaView;
		usleep(1500000); fflush(stdout);
	}
	
	on.screenRefresh = fimView;
	on.click = fimOnClick;
	on.mouseMove = fimOnMouseMove;
	
	on.run = NULL;
}

void fimOnClick(void){
	Coordenadas pos = getMousePos();

	if(pos.x>=257 && pos.x<=392 &&
		 pos.y>=300 && pos.y<=385){
			on.run = menu;
			return;
	}
	if(pos.x>=594 && pos.x<=648 &&
		 pos.y>=426 && pos.y<=480){
			 on.stop();
			 return;
	}
}

void fimOnMouseMove(Coordenadas pos){
	if(pos.x>=594 && pos.x<=648 && pos.y>=426 && pos.y<=480){
		//botaoExit = partidaExit1;
	}
	else if(pos.x>=535 && pos.x<=589 && pos.y>=426 && pos.y<=450){
		//botaoMenu = partidaMenu1;
	}
	else{
		//botaoExit = partidaExit0;
		//botaoMenu = partidaMenu0;
	}
	return;
}
