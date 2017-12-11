#include "3.fim.h"
#include "../3.visualizacao.h"

void vitoriaView(void){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0x00, 0x00, 0x00 ) );

	//printSurface(screenSurface,menuOver,0,0,tam.tela.x,tam.tela.y);
		
	//80,210,170,60
	//Update the surface
	SDL_UpdateWindowSurface( janela );
}

void derrotaView(void){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0x00, 0x00, 0x00 ) );

	//printSurface(screenSurface,menuOver,0,0,tam.tela.x,tam.tela.y);
		
	//80,210,170,60
	//Update the surface
	SDL_UpdateWindowSurface( janela );
}
