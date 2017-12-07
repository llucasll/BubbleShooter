#include "1.dados.h"

#include "2.menu.h"
#include "3.menu.h"

void printSurface(Surface surface, int x, int y, int tamx, int tamy);

void menuView(){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0x00, 0x00, 0x00 ) );
	switch (menuGetStatus()) {
		case 0:
			printSurface(menuOverNot,0,0,tam.tela.x,tam.tela.y);
			break;
		case 1:
			printSurface(menuOverPlay,0,0,tam.tela.x,tam.tela.y);
			break;
		case 2:
			printSurface(menuOverExit,0,0,tam.tela.x,tam.tela.y);
			break;
	}
	//80,210,170,60
	//Update the surface
	SDL_UpdateWindowSurface( janela );
}

void printSurface(Surface surfacetemp, int posx, int posy, int tamx, int tamy){
	SDL_Rect srciRect, dstiRect;
	Surface gprintSurface;

	srciRect.x = 0; srciRect.y = 0;
	srciRect.w = tamx;
	srciRect.h = tamy;
	dstiRect.x = posx;
	dstiRect.y = posy;
	gprintSurface = surfacetemp;

	if( SDL_BlitSurface( gprintSurface, &srciRect,
						 screenSurface, &dstiRect ) < 0 ) {
		logger( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
		quit = true;
	}
}
