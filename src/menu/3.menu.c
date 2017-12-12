#include "../1.dados.h"

#include "2.menu.h"
#include "3.menu.h"
#include "../3.visualizacao.h"

Surface menuOver;

void menuView(){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0x00, 0x00, 0x00 ) );

	printSurface(screenSurface,menuOver,0,0,tam.tela.x,tam.tela.y);
	if(musicaOn)printSurface(screenSurface,sound1,0,tam.tela.y-54,54,tam.tela.y);
	else printSurface(screenSurface,sound0,0,tam.tela.y-54,54,tam.tela.y);
	if(credits) printSurface(screenSurface,menuCredits1,0,0,tam.tela.x,tam.tela.y);
	else printSurface(screenSurface,menuCredits0,0,0,tam.tela.x,tam.tela.y);

	//80,210,170,60
	SDL_UpdateWindowSurface( janela );//Update the surface
}
