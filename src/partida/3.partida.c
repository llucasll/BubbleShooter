#include "../1.dados.h"

#include "2.partida.h"
#include "3.partida.h"

Surface botaoMenu;
Surface botaoExit;

void printBola(byte cor, int x, int y);
// Tamanho Hud: (648,75)
//Tamanho Menu: (x é 5 de distancia do exit [checar propriedades])
//Tamanho Exit: (54 por 54)
//Tamanho VidaCover (91,19) (inicia em: 193,422)

void partidaView(){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0xFF, 0xFF, 0xFF ) );

	printSurface(screenSurface, partidaBg[bgIndex], 0, 0, 648, 480);
	//printf("%d",bgIndex);

	printSurface(screenSurface, partidaHud, 0, 405, 648, 75);

	printSurface(screenSurface, botaoExit, 594, 426, 54, 54);

	printSurface(screenSurface, botaoMenu, 535, 426, 50, 24);

	println("%s",scoreString);

	//msgPontos= TTF_RenderText_Solid( fonte, scoreString, ttfCor);
	//printSurface(screenSurface,msgPontos,0,0,tam.tela.x/2,tam.tela.y/2);
/*
	//Fill the surface white
	SDL_FillRect( gScreenSurface, NULL,
							SDL_MapRGB( gScreenSurface->format,
							fundo.R, fundo.G, fundo.B ));
*/

	for(int i=0;i<linhastotal;i++)
		for(int j=0;j<colunas;j++)
			if(existe(j,i))
				printBola(matriz[i][j].cor, matriz[i][j].x, matriz[i][j].y);
	if(!estourando)
		printBola(tiro.cor, tiro.x, tiro.y);

	printScore(30,61,61,0,tam.tela.x/2-2,tam.tela.y-40+2);
	printScore(30,244,244,0,tam.tela.x/2,tam.tela.y-40);
	//Update the surface
	SDL_UpdateWindowSurface( janela );
}

void printBola(byte cor, int x, int y){
	printSurface(screenSurface, sprites[cor], x, y, tam.bola.x, tam.bola.y);
}

void printScore( int tamFonte, int r, int g, int b,int posiX,int posiY){
	fonte = TTF_OpenFont("./font/fonteFolks.ttf",tamFonte);

	SDL_Rect msgRect;

	ttfCor.r=r; ttfCor.g=g; ttfCor.b=b;

	msgRect.x = posiX;
	msgRect.y = posiY;
	msgRect.w = 150;
	msgRect.h = 40;

	msgPontos= TTF_RenderText_Solid( fonte, scoreString, ttfCor);
	SDL_BlitSurface(msgPontos, NULL, screenSurface, &msgRect);

	//printSurface(screenSurface,msgPontos,0,0,tam.tela.x/2,tam.tela.y/2);
	SDL_FreeSurface(msgPontos);
	TTF_CloseFont(fonte);
}

/* ETAPA DE INICIALIZAÇÃO DO **CONTROLE** */
bool carregarMidia(void){//iu
}
bool iniciarSDL(void){//iu
}
void iniciarInterface(void){//iu
}

/* ETAPA DE MECÂNICA */
void moverSeta(){
}

/* ETAPA DE FINALIZAÇÃO */
