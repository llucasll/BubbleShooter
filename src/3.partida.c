#include "1.dados.h"

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

	printSurface(janela, partidaBg[bgIndex], 0, 0, 648, 480);
	//printf("%d",bgIndex);

	printSurface(janela, partidaHud, 0, 405, 648, 75);
	
	printSurface(janela, botaoExit, 594, 426, 54, 54);

	printSurface(janela, botaoMenu, 535, 426, 50, 24);

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

	printBola(tiro.cor, tiro.x, tiro.y);

	//Update the surface
	SDL_UpdateWindowSurface( janela );
}

void printBola(byte cor, int x, int y){
	SDL_Rect srciRect, dstiRect;
	Surface gprintSurface;

	srciRect.x = 0; srciRect.y = 0;
	srciRect.w = tam.bola.x;
	srciRect.h = tam.bola.y;
	dstiRect.x = x;
	dstiRect.y = y;
	gprintSurface = sprites[cor];

	if( SDL_BlitSurface( gprintSurface, &srciRect,
						 screenSurface, &dstiRect ) < 0 ) {
		logger( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
		quit = true;
	}
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
