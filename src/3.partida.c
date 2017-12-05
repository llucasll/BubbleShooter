#include "1.dados.h"

#include "3.partida.h"

void printBola(Bola *p);

void partidaView(){
	SDL_Rect srcRect, dstRect;

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

	srcRect.x = 0; srcRect.y = 0;
	srcRect.w = tam.bola.x;
	srcRect.h = tam.bola.y;
	dstRect.x = tiro.x;
	dstRect.y = tiro.y;


	for(int i=0;i<linhas;i++)
		for(int j=0;j<colunas;j++)
			if(matriz[i][j].existe)
				printBola(&matriz[i][j]);

	if( SDL_BlitSurface( sprites[tiro.cor], &srcRect,
								 screenSurface, &dstRect ) < 0 ) {
		logger( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
		quit = true;
	}


	//Update the surface
	SDL_UpdateWindowSurface( janela );
}

void printBola(Bola *p){
	SDL_Rect srciRect, dstiRect;
	Surface gprintSurface;

	srciRect.x = 0; srciRect.y = 0;
	srciRect.w = tam.bola.x;
	srciRect.h = tam.bola.y;
	dstiRect.x = p->x;
<<<<<<< HEAD
	dstiRect.y = p->y;
	gprintSurface=sprites[p->cor];
=======
	dstiRect.y = p->y;//
	gprintSurface=gcolorSurface[p->cor];
>>>>>>> cd8dd6082475671beab357f6ba6c58fa9d507e48

	if( SDL_BlitSurface( gprintSurface, &srciRect,
						 screenSurface, &dstiRect ) < 0 ) {
		printf( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
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
