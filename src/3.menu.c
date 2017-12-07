#include "1.dados.h"

#include "2.menu.h"
#include "3.menu.h"

Surface menuOver;

void menuView(){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0x00, 0x00, 0x00 ) );

	printSurface(janela,menuOver,0,0,tam.tela.x,tam.tela.y);
		
	//80,210,170,60
	//Update the surface
	SDL_UpdateWindowSurface( janela );
}
