
#include "interno.h"

void eventsDefault(void){
	SDL_Event e; // Event handler

	//podia fornecer, também, uma lista de eventos (a ser manuseada), num par ["bool teste(void)", "voidvoid comportamento"]

	while( SDL_PollEvent( &e ) != 0 ) {
		switch (e.type) {
			case SDL_QUIT:
				if(on.stop) on.stop();
				else stopDefault();
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(e.button.button == SDL_BUTTON_LEFT){
					if(on.click)
						on.click();
				}
				break;
			case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					if(on.stop) on.stop();
					else stopDefault();
				}
				break;
			case SDL_MOUSEMOTION:
				if(on.mouseMove) on.mouseMove(getMousePos());
				break;
		}
	}
}

void stopDefault(void){
	quit = true;
}
