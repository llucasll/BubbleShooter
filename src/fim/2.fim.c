#include "2.fim.h"
#include "3.fim.h"
#include "../3.visualizacao.h"

#include "../menu/2.menu.h"
#include "../partida/2.partida.h"

void vitoria(void){
	on.screenRefresh = vitoriaView;
	on.click = vitoriaOnClick;
	on.mouseMove = vitoriaOnMouseMove;
	
	on.run = NULL;
}

void vitoriaOnClick(void){
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

void vitoriaOnMouseMove(Coordenadas pos){
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

//

void derrota(void){
	on.screenRefresh = derrotaView;
	on.click = derrotaOnClick;
	on.mouseMove = derrotaOnMouseMove;
	
	on.run = NULL;
}

void derrotaOnClick(void){
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

void derrotaOnMouseMove(Coordenadas pos){
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
