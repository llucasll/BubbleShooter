#include "3.menu.h"

void menuView(){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0xFF, 0xFF, 0xFF ) );

	//Update the surface
	SDL_UpdateWindowSurface( janela );
}
