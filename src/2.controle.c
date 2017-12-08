#include "1.dados.h"//apenas pelas inicializações no init

#include "menu/2.menu.h"
#include "menu/3.menu.h"

#include "partida/2.partida.h"
#include "partida/3.partida.h"

#include "fim/2.fim.h"
#include "fim/3.fim.h"

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

//voidvoid bubbleShooter;

/*
void init2(void){
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
}*/

void init(void){

	//println("iniciei");

	on.run = menu;
	on.finish = closing;

	// Intializes random number generator
	time_t t;
	srand((unsigned) time(&t));

	printnl();
	println("\t* Carregando... *");
	printnl();

	janela = newJanela(tam.tela.x, tam.tela.y, "Bubble Shooter 0.1");

	screenSurface = surfaceFrom ( janela ); //Get window surface

	//Load media
	if( !loadMedia() ) {
		logger( "Failed to load media!\n" );
		exit(2);
	}

	//init2();
}

/*
void bubbleShooter (void){

	menu();
	partida();
	fim();
}
*/

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
	//TODO fazer a verificação.
	/*gJPGSurface = loadImage( "./media/circle.jpeg", screenSurface);
	if( gJPGSurface == NULL ) {
		logger( "Failed to load image! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}*/
	sprites[0] = loadImage( "./media/blue.png", screenSurface );
	sprites[1] = loadImage( "./media/red.png", screenSurface );
	sprites[2] = loadImage( "./media/cian.png", screenSurface );
	sprites[3] = loadImage( "./media/green.png", screenSurface );
	sprites[4] = loadImage( "./media/pink.png", screenSurface );
	sprites[5] = loadImage( "./media/yellow.png", screenSurface );
	menuOverPlay = loadImage( "./media/menuOverPlay.png", screenSurface );
	menuOverNot = loadImage( "./media/menuOverNot.png", screenSurface );
	menuOverExit = loadImage( "./media/menuOverExit.png", screenSurface );
	partidaBg[0] = loadImage( "./media/bgFlintstones.png", screenSurface );
	partidaBg[1] = loadImage( "./media/bgScooby.png", screenSurface );
	partidaBg[2] = loadImage( "./media/bgPrisao.png", screenSurface );
	partidaBg[3] = loadImage( "./media/bgPapa.png", screenSurface );
	partidaBg[4] = loadImage( "./media/bgLilo.png", screenSurface );
	partidaExit0 = loadImage( "./media/partidaExit0.png", screenSurface );
	partidaExit1 = loadImage( "./media/partidaExit1.png", screenSurface );
	partidaHud = loadImage( "./media/partidaHud.png", screenSurface );
	partidaMenu0 = loadImage( "./media/partidaMenu0.png", screenSurface );
	partidaMenu1 = loadImage( "./media/partidaMenu1.png", screenSurface );
	blackRect = loadImage( "./media/blackRect.png", screenSurface );

	return success;
}

void closing() {
	println("\t* Encerrando... *");

	//Free loaded image
	/*SDL_FreeSurface( gJPGSurface );
	gJPGSurface = NULL;*/
	//TODO

	//Destroy window
	SDL_DestroyWindow( janela );
	janela = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
