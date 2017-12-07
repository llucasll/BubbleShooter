#include "1.dados.h"

#include "2.menu.h"
#include "3.menu.h"

void menuView(){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0x00, 0x00, 0x00 ) );
	switch (menuGetStatus()) {
		case 0:
			printSurface(janela,menuOverNot,0,0,tam.tela.x,tam.tela.y);
			break;
		case 1:
			printSurface(janela,menuOverPlay,0,0,tam.tela.x,tam.tela.y);
			break;
		case 2:
			printSurface(janela,menuOverExit,0,0,tam.tela.x,tam.tela.y);
			break;
	}
	//80,210,170,60
	//Update the surface
	SDL_UpdateWindowSurface( janela );
}

int menuGetStatus(void){
	Coordenadas c = mousePos();

	//135,85 257,200
	//54,54 594,426

	if(c.x>=257 && c.x<=392 && c.y>=300 && c.y<=385){
		return 1;
	}
	else if(c.x>=594 && c.x<=648 && c.y>=426 && c.y<=480){
		return 2;
	}
	else{
		return 0;
	}
	return 0;
}
