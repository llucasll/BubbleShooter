#include "1.dados.h"

#include "3.partida.h"

void printBola(byte cor, int x, int y);

void partidaView(){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0xFF, 0xFF, 0xFF ) );

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
