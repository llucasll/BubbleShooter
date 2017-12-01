//#include "../lib-headers/iu.h"
#include "iu.h"
//#include "iu.h"
/*
iuf.mouse.clicou =
({
	int __fn__ (int n) {
		return n*n;
	}
	&__fn__;
});

iuf.mouse.moveu = lambda(
	int, (int n) {
		if(n==3)
			return 1;
		//else
	}
);*/

//#include "../src/3.apresentacao.h"

bool quit = false; //Main loop flag

void atualizador(void){
	while(!quit){
		if(on.screenRefresh)
			on.screenRefresh();
		//usleep(1000000/24);
	}
}

void monitorDefault(void){
	SDL_Event e; // Event handler
	
	//podia fornecer, também, uma lista de eventos (a ser manuseada), num par ["bool teste(void)", "voidvoid comportamento"]
	
	//While application is running
	while( !quit ) {
		while( SDL_PollEvent( &e ) != 0 ) {
			switch (e.type) {
				case SDL_QUIT:
					if(on.quit) on.quit();
					else quitDefault();
					break;
				case SDL_MOUSEBUTTONDOWN:
					if(e.button.button == SDL_BUTTON_LEFT){
						if(on.mouseClick)
							on.mouseClick();
					}
					break;
				case SDL_KEYDOWN://modularizar tbm
					if (e.key.keysym.sym == SDLK_ESCAPE) {
						quit = true;
					}
					break;
			}
		}
	}
}

void quitDefault(void){
	quit = true;
}

void changeMonitor(voidvoid novo){
	controle.monitor = novo;
	// TODO TERMINAR A THREAD threads.monitor
	executar(controle.monitor);
}

Janela newJanela(int x, int y, char nome[]) {
	Janela janela;

	//int success = true;	//Initialization flag

	//srand(time(NULL));

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		logger( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		//success = false;
	}
	else {
		//Create window
		janela = SDL_CreateWindow( nome, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_SHOWN );
		if( janela == NULL ) {
			logger( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			//success = false;
		}
		else {
			//Initialize JPG and PNG loading
			int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
				logger( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				//success = false;
			}
		}
	}

   

	//return success;
	return janela;
}

Surface loadImage( char *path, Surface base ) {
	//The final optimized image
	Surface optimizedSurface = NULL;

	//Load image at specified path
	Surface loadedSurface = IMG_Load( path );
	if( loadedSurface == NULL ) {
		logger( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
	}
	else {
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, base->format, 0 );
		if( optimizedSurface == NULL ) {
			logger( "Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

int main( int argc, char* args[] ) {

	//iniciar();//controle
	//jogo();//mecanica
	//encerrar();//controle
	
	/*Coordenadas c = {3,4};
	insere(2,c);
	
	struct{
		int (*teste)(void){
			return 26;
		}
	}teste;
		
	printint(teste.teste());
	*/
	
	// inicializa a própria biblioteca com os padrões
	on.quit = quitDefault;
	controle.monitor = monitorDefault;
	
	//chama o "main"
	init();
	
	if(controle.executar)
		threads.principal = executar(controle.executar);
	threads.atualizador = executar(atualizador);
	if(controle.monitor)
		threads.monitor = executar(controle.monitor);
	
	while(!quit);
	
	esperar(threads.atualizador);
	if(controle.close) controle.close();//Free resources and closing SDL

	return 0;
}
