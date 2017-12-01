#include "1.dados.h"//apenas pelas inicializações no init
#include "2.partida.h"
#include "3.partida.h"

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

void init(void){

	//#include "../lib-headers/iu.c"
	//println("iniciei");
	
	controle.executar = execucao;
	on.screenRefresh = partidaView;
	on.mouseClick = jogoOnClick;
	controle.close = closing;
	
	printnl();
	println("\t* Carregando... *");
	printnl();
	
	janela = newJanela(tam.tela.x, tam.tela.y, "Bubble Shooter 0.1");
	//Start up SDL and create window
	if( !janela ) {// TODO modularizar tratamentos de erro
		printf( "Failed to initialize!\n" );
		exit(1);
	}
	else {
		screenSurface = surfaceFrom ( janela ); //Get window surface
	}
	
	//Load media
	if( !loadMedia() ) {
		printf( "Failed to load media!\n" );
		exit(2);
	}
}

int loadMedia() {

	int success = true; //Loading success flag
	/*uint32_t colorKey;*/
	
	//Load PNG surface
	gJPGSurface = loadImage( "./media/circle.jpeg", screenSurface);
	if( gJPGSurface == NULL ) {
		printf( "Failed to load image! SDL Error: %s\n", SDL_GetError() );
		success = false;
	} 
	return success;
}

void closing() {
	println("\t* Encerrando... *");
	//printnl();
	
	//Free loaded image
	SDL_FreeSurface( gJPGSurface );
	gJPGSurface = NULL;

	//Destroy window
	SDL_DestroyWindow( janela );
	janela = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
