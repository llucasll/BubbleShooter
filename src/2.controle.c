//#include "1.dados.h"//apenas pelas inicializações no init

#include "menu/2.menu.h"
#include "menu/3.menu.h"

#include "partida/2.partida.h"
#include "partida/3.partida.h"
#include "3.visualizacao.h"

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

	/* Initialize Music */

	/*Initialize Mixer */
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ){
		logger( "Failed to load media!\n" );
		exit(2);
	}
	/*Initialize TTF*/
	if (TTF_Init() == -1){
		logger( "Failed to load media!\n" );
		exit(2);
	}
	//Load media
	if( !loadMedia() ) {
		logger( "Failed to load media!\n" );
		exit(2);
	}
	Mix_PlayMusic( musica, -1);
	musicaOn = true;
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
	musica = Mix_LoadMUS("./media/sounds/Carnival_Kerfuffle.mp3");

	sprites[0] = loadImage( "./media/balls/blue.png", screenSurface );
	sprites[1] = loadImage( "./media/balls/red.png", screenSurface );
	sprites[2] = loadImage( "./media/balls/cian.png", screenSurface );
	sprites[3] = loadImage( "./media/balls/green.png", screenSurface );
	sprites[4] = loadImage( "./media/balls/pink.png", screenSurface );
	sprites[5] = loadImage( "./media/balls/yellow.png", screenSurface );
	menuOverPlay = loadImage( "./media/menu/menuOverPlay.png", screenSurface );
	menuOverNot = loadImage( "./media/menu/menuOverNot.png", screenSurface );
	menuOverExit = loadImage( "./media/menu/menuOverExit.png", screenSurface );
	partidaBg[0] = loadImage( "./media/bg/bgFlintstones.png", screenSurface );
	partidaBg[1] = loadImage( "./media/bg/bgScooby.png", screenSurface );
	partidaBg[2] = loadImage( "./media/bg/bgPrisao.png", screenSurface );
	partidaBg[3] = loadImage( "./media/bg/bgPapa.png", screenSurface );
	partidaBg[4] = loadImage( "./media/bg/bgLilo.png", screenSurface );
	partidaExit0 = loadImage( "./media/partida/partidaExit0.png", screenSurface );
	partidaExit1 = loadImage( "./media/partida/partidaExit1.png", screenSurface );
	partidaHud = loadImage( "./media/partida/partidaHud.png", screenSurface );
	partidaMenu0 = loadImage( "./media/partida/partidaMenu0.png", screenSurface );
	partidaMenu1 = loadImage( "./media/partida/partidaMenu1.png", screenSurface );
	//fonte = TTF_OpenFont("./font/fonteFolks.ttf",10);
	//ttfCor.r=244; ttfCor.g=244; ttfCor.b=244;
	msgPontos= NULL;

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

	//Free Music
	Mix_FreeMusic(musica);

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	Mix_CloseAudio();
}
