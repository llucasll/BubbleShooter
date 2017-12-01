#include "2.controle.h"

/*
bool iniciarSDL(void);//iu
bool carregarMidia(void);//iu
bool iniciarJogo(void);//dados
void finalizarInterface(void);//iu
*/

/*

bool iniciar(void){
	if(!carregarMidia()){
		//erro
	}
	else if(!iniciarSDL()){
		//erro
	}
	else{
		bool ok = iniciarJogo();
		iniciarInterface();
		return ok;
	}
	return false;
}

void encerrar(void){//finalizar o jogo, com a IU inclusive
}

void erro(){//erro de execução durante o jogo
	println("Desculpe, um erro grave interrompeu a execução do jogo.");
	exit(1);
}

*/

void preparar(void){

	//#include "../lib-headers/iu.c"
	//println("iniciei");
	
	printnl();
	println("Carregando...");
	printnl();
	
	//Start up SDL and create window
	if( !init() ) {
		printf( "Failed to initialize!\n" );
		exit(1);
	}
	
	//Load media
	if( !loadMedia() ) {
		printf( "Failed to load media!\n" );
		exit(2);
	}
}

int init() {

	int success = true;	//Initialization flag

	srand(time(NULL));

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else {
		//Create window
		gWindow = SDL_CreateWindow( "Bubble Shooter 0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, tela.x, tela.y, SDL_WINDOW_SHOWN );
		if( gWindow == NULL ) {
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else {
			//Initialize JPG and PNG loading
			int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				success = false;
			}
			else {

				gScreenSurface = SDL_GetWindowSurface( gWindow ); //Get window surface
			}
		}
	}

   

	return success;
}

int loadMedia() {

	int success = true; //Loading success flag
	/*uint32_t colorKey;*/
	
	//Load PNG surface
	gJPGSurface = loadSurface( "./media/circle.jpeg" );
	if( gJPGSurface == NULL ) {
		printf( "Failed to load image! SDL Error: %s\n", SDL_GetError() );
		success = false;
	} 
	return success;
}

void closing() {
	//Free loaded image
	SDL_FreeSurface( gJPGSurface );
	gJPGSurface = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface( char *path ) {
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path );
	if( loadedSurface == NULL ) {
		printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
	}
	else {
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
		if( optimizedSurface == NULL ) {
			printf( "Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}
