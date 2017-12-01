/*
 * 06_moving_images.c
 * Este programa move uma imagem pela tela. Ao colidir com uma parede a imagem irá ser refletida.
 * 2016/01/26
 * @adriano cruz
 */
 
/* Using SDL, SDL_image, standard IO, and strings */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "0.all.h"

/* Global Variables */
SDL_Window* gWindow = NULL; //The window we'll be rendering to
//SDL_Surface* imagem; //The imagem character
SDL_Surface* gScreenSurface = NULL; //The surface contained by the window
SDL_Surface* gJPGSurface = NULL; //Current displayed PNG image

bool quit = false; //Main loop flag

/* Function prototypes */
SDL_Surface* loadSurface( char *path ); //Loads individual image
int init(); //Starts up SDL and creates window
int loadMedia(); //Loads media
void closing(); //Frees media and shuts down SDL
void createNPC( int x, int y, int velx, int vely); //Create NPC
void moveNPC(); //Move NPC

void preparar(void){

	//#include "../lib-headers/iu.c"
	println("iniciei");
	
	//printnl();
	println("Carregando...");
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

void execucao(void){
	SDL_Rect srcRect, dstRect;
	SDL_Event e; // Event handler

	bool pri = true; /* SÓ O PRIMEIRO CLIQUE TEM VALIDADE */
	quit = false;
	
	//Create NPC
	createNPC(
		(tela.x - npc.x)/2, 
		(tela.y - npc.y), 
		0, 
		0
	);
	
	/* SE, QUANDO O SO MANDA O PROGRAMA FECHAR (usando "terminar" ao invés de "matar") REINICIA ELE RECOMEÇA A FUNÇÃO EM EXECUÇÃO NO MOMENTO.
	static int k=0;
	printf("i'm here %%%d\n",k);
	k++;
	
	void aninhada(void){
		
		
		static int k=0;
		printf("so na funcao %%%d\n",k);
		k++;
		*/
		
	
	//While application is running
	while( !quit ) {
		while( SDL_PollEvent( &e ) != 0 ) {
			switch (e.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN:
					if(e.button.button == SDL_BUTTON_LEFT){
						if(pri){
							//println("Clicou!");
							int x = e.motion.x, y = e.motion.y;
							//printf("\n%d,%d\n",x,y);
							x -= (tela.x)/2;
							y -= (tela.y)-((npc.y)/2);
						
							//printf("\n%d%d\n",x,y);
						
							//printf("\n%d,%d,%d\n",tela.x,tela.y,npc.y);
							//printf("\n%d,%d\n",x,y);
						
							double d = sqrt( pow(x,2) + pow(y,2) );
						
							tiro.vel.x = x/d;
							tiro.vel.y = y/d;
							//printf("%f,%f\n",tiro.vel.x,tiro.vel.y);
							pri = false;
						}
						//printf("\n%d, %d\n\n",e.motion.x,e.motion.y);
						//printf("oi\n");
						//printf("\nvel.x: %lf\nvel.y: %lf\nx: %lf\ny: %lf\n",tiro.vel.x,tiro.vel.y,tiro.x,tiro.y);
					}
					break;
				case SDL_KEYDOWN:
					if (e.key.keysym.sym == SDLK_ESCAPE) {
						quit = true;
					}
					break;
			}
		}
		
		//Fill the surface white
		SDL_FillRect( gScreenSurface, NULL, 
							  SDL_MapRGB( gScreenSurface->format, 
							  0xFF, 0xFF, 0xFF ) );

		moveNPC();

		srcRect.x = 0; srcRect.y = 0;
		srcRect.w = npc.x;
		srcRect.h = npc.y;
		dstRect.x = tiro.x;
		dstRect.y = tiro.y;
		
		if( SDL_BlitSurface( gJPGSurface, &srcRect, 
									 gScreenSurface, &dstRect ) < 0 ) {
			printf( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
			quit = true;
		}
	
		//printf("%f, %f\n",tiro.x,tiro.y);
		
		//Update the surface
		SDL_UpdateWindowSurface( gWindow );
			
		//Not so good solution, depends on your computer
		SDL_Delay(5);
	}
}
//aninhada();
//}

int main( int argc, char* args[] ) {
	
	preparar();
	
	//while(!quit)
	while(true)
		execucao();
	
	//while(1);
	
	closing();//Free resources and closing SDL

	return 0;
}


void moveNPC() {
	
	//printf("%d, %d\n",tiro.vel.x,tiro.vel.y);

	tiro.x += tiro.vel.x;
	tiro.y += tiro.vel.y;
	
	if ( (tiro.x + npc.x > tela.x) ||
		 (tiro.x < 0) ) {
		tiro.vel.x = -tiro.vel.x;
		tiro.x += tiro.vel.x; 
	}
	if (tiro.y + npc.y > tela.y) {
		tiro.vel.y = -tiro.vel.y;
		tiro.y += tiro.vel.y;
	}
	
	if (tiro.y < 0) {
		/*tiro.vel.x = 0;
		tiro.vel.y = 0;*/
		//main(0, NULL);
		quit = true;
	}
}


/* Create NPC */
void createNPC( int x, int y, int velx, int vely) {
	tiro.x = x;
	tiro.y = y;
	tiro.vel.x = velx;
	tiro.vel.y = vely;	
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
	gJPGSurface = loadSurface( "./circle.jpeg" );
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
