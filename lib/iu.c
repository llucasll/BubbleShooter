#include "iu.h"

bool quit = false; // Semáforo global que controla o término de todo o programa

/* PROTÓTIPOS */
static voidvoid visualizacao;
static voidvoid executor;
static Janela _newJanela(int x, int y, char nome[]);

int main( int argc, char* args[] ) {

	// Inicializa a própria biblioteca com os padrões
	on.quit = quitDefault;
	controle.eventos = eventosDefault;

	// Chama o "main"
	init();

	// Roda as threads

	threads.principal = executar(executor);
	if(controle.eventos)
		threads.eventos = executar(controle.eventos);

	// Aguarda o fim do programa
	while(!quit);
	esperar(threads.visualizacao);

	// Chama a função de finalização
	if(controle.close) controle.close();//Free resources and closing SDL

	return 0;
}

struct{
	Janela janela;
	int x;
	int y;
	char* nome;
	Thread thread;//TODO
}_novaJanela;

Janela newJanela(int x, int y, char nome[]) {

	// A janela não existe
	_novaJanela.janela = NULL;
	//_novaJanela.thread = NULL; //TODO aqui deveria ser guardada a thread da janela, se já houver a anterior (threads.visualizacao guarda só a primeira)

	// Setar os valores sobre a Janela
	_novaJanela.x = x;
	_novaJanela.y = y;
	_novaJanela.nome = nome;

	if(!threads.visualizacao) // Se não houver janela ainda
		threads.visualizacao = executar(visualizacao); // Guardar a thread
	else executar(visualizacao); // Senão, apenas inicia

	while(!_novaJanela.janela);

	return _novaJanela.janela;
}

static void executor(void){
	while(!quit)
		if(controle.principal)
			controle.principal();
}

static void visualizacao(void){

	//Start up SDL and create window
	_novaJanela.janela = _newJanela (_novaJanela.x, _novaJanela.y, _novaJanela.nome);

	if( !_novaJanela.janela ) {
		logger( "Failed to initialize the Window!\n" );
		exit(1);
	}


	while(!quit){
		if(on.screenRefresh)
			on.screenRefresh();
		//usleep(1000000/24);
	}
}

static Janela _newJanela(int x, int y, char nome[]) {
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
		else{
			Uint32 colorkey = SDL_MapRGBA(optimizedSurface->format, 0,0xFF, 0, 0);
			SDL_SetColorKey( optimizedSurface,1, colorkey);
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}


void eventosDefault(void){
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

void printSurface(Janela janela, Surface surfacetemp, int posx, int posy, int tamx, int tamy){
	SDL_Rect srciRect, dstiRect;
	Surface gprintSurface;

	srciRect.x = 0; srciRect.y = 0;
	srciRect.w = tamx;
	srciRect.h = tamy;
	dstiRect.x = posx;
	dstiRect.y = posy;
	gprintSurface = surfacetemp;

	if( SDL_BlitSurface( gprintSurface, &srciRect,
						 surfaceFrom(janela), &dstiRect ) < 0 ) {
		logger( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
		quit = true;
	}
}

void quitDefault(void){
	quit = true;
}

Coordenadas mousePos(void){
	Coordenadas out;
	SDL_GetMouseState(&out.x,&out.y);
	return out;
}

void changeMonitor(voidvoid novo){
	controle.eventos = novo;
	// TODO ENCERRAR A THREAD threads.eventos
	executar(controle.eventos);
}
