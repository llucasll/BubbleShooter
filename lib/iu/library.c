#include "interno.h"

Janela newJanela(int x, int y, char nome[]) {

	// A janela não existe
	_novaJanela.janela = NULL;
	//_novaJanela.thread = (Thread) NULL; //TODO aqui deveria ser guardada a thread da janela, se já houver a anterior (threads.visualizacao guarda só a primeira)

	// Setar os valores sobre a Janela
	_novaJanela.x = x;
	_novaJanela.y = y;
	_novaJanela.nome = nome;

	_novaJanela.thread = executar(_thread_visualizacao); // Guardar temporariamente
	if(!threads.visualizacao) // Se nenhuma janela foi inicializada ainda
		threads.visualizacao = _novaJanela.thread; // Guardar a thread como janela principal		

	while(!_novaJanela.janela); // Fica a cargo da Thread de visualização criar a Janela que ela mesma irá manipular

	return _novaJanela.janela;
}

void _newJanela(int x, int y, char nome[]) {
	Janela janela;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		logger( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	else {
		//Create window
		janela = SDL_CreateWindow( nome, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_BORDERLESS );
		if( janela == NULL )
			logger( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		else {
			//Initialize JPG and PNG loading
			int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
				logger( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		}
	}

	_novaJanela.janela = janela;
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
		else{
			Uint32 colorkey = SDL_MapRGBA(optimizedSurface->format, 0,0xFF, 0, 0);
			SDL_SetColorKey( optimizedSurface,1, colorkey);
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

void printSurface(Surface destino, Surface origem, int posx, int posy, int tamx, int tamy){
	SDL_Rect srciRect, dstiRect;
	Surface gprintSurface;

	srciRect.x = 0; srciRect.y = 0;
	srciRect.w = tamx;
	srciRect.h = tamy;
	dstiRect.x = posx;
	dstiRect.y = posy;

	if( SDL_BlitSurface( origem, &srciRect,
						 destino, &dstiRect ) < 0 ) {
		logger( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
		on.stop();
	}
}

Coordenadas getMousePos(void){
	Coordenadas out;
	SDL_GetMouseState(&out.x,&out.y);
	return out;
}

