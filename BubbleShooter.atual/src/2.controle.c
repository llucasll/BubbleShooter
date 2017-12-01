#include "1.dados.h"//apenas pelas inicializações no init

#include "2.menu.h"
#include "3.menu.h"

#include "2.partida.h"
#include "3.partida.h"

#include "2.fim.h"
#include "3.fim.h"

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

	//println("iniciei");

	controle.executar = execucao;
	controle.close = closing;
	
	printnl();
	println("\t* Carregando... *");
	printnl();

	//Start up SDL and create window	
	janela = newJanela(tam.tela.x, tam.tela.y, "Bubble Shooter 0.1");
	if( !janela ) {// TODO modularizar tratamentos de erro
		logger( "Failed to initialize!\n" );
		exit(1);
	}
	else {
		screenSurface = surfaceFrom ( janela ); //Get window surface
	}
	
	//Load media
	if( !loadMedia() ) {
		logger( "Failed to load media!\n" );
		exit(2);
	}
}

void execucao (void){
	menu();
	partida();
	fim();
}

int loadMedia() {

	int success = true; //Loading success flag
	
	/*uint32_t colorKey;*/

	/*
	
	///int quantasImgs;
	
	///FILE *pse = popen("find | grep \"png\" | wc -l","w");
	
	//fscanf(pse, "%d", &quantasImgs);
	//println("%d",quantasImgs);
	
	//char mmm[900];
	//fscanf(pse, "%s", mmm); //fgets(mmm,900,pse);
	
	char sai[900] = "merda";
	//sprintf(sai,"lucas\noi\nlucas");
	println("%soi",sai);
	
	///Surface imagens[quantasImgs];
	
	// find | grep \"png\" | wc -l

	*/	

	//Load PNG surface
	gJPGSurface = loadImage( "./media/circle.jpeg", screenSurface);
	if( gJPGSurface == NULL ) {
		logger( "Failed to load image! SDL Error: %s\n", SDL_GetError() );
		success = false;
	} 
	return success;
}

void closing() {
	println("\t* Encerrando... *");
	
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
