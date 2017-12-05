#include "iu.h"

bool quit = false; // Semáforo global que controla o término de todo o programa

void atualizador(void){
	void init2(void);//TODO
	init2();//TODO
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
						if(on.click)
							on.click();
					}
					break;
				case SDL_KEYDOWN:
					if (e.key.keysym.sym == SDLK_ESCAPE) {
						if(on.quit) on.quit();
						else quitDefault();
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
	// TODO ENCERRAR A THREAD threads.monitor
	executar(controle.monitor);
}

Janela newJanela(int x, int y, char nome[]) {
	Janela janela;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		logger( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	else {
		//Create window
		janela = SDL_CreateWindow( nome, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_SHOWN );
		if( janela == NULL )
			logger( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		else {
			//Initialize JPG and PNG loading
			int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
				logger( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		}
	}

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
	// Inicializa a própria biblioteca com os padrões
	on.quit = quitDefault;
	controle.monitor = monitorDefault;
	
	// Chama o "main"
	init();
	
	//TODO
	extern Janela janela;
	
	threads.atualizador = executar(atualizador);
	
	//printf("%d\n",janela);
	while(!janela);
	//TODO
	
	// Roda as threads
	if(controle.principal)
		threads.principal = executar(controle.principal);
	//threads.atualizador = executar(atualizador);
	if(controle.monitor)
		threads.monitor = executar(controle.monitor);
	
	//atualizador();
	
	// Aguarda o fim do programa
	while(!quit);
	esperar(threads.atualizador);
	
	// Chama a função de finalização
	if(controle.close) controle.close();//Free resources and closing SDL

	return 0;
}
