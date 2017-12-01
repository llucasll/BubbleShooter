#include "1.dados.h"

#include "3.partida.h"

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
//void atualizar(){
//}

/* ETAPA DE FINALIZAÇÃO */

void partidaView(){
	SDL_Rect srcRect, dstRect;
	
	//Fill the surface white			  
	SDL_FillRect( screenSurface, NULL, 
						  SDL_MapRGB( screenSurface->format, 
						  0xFF, 0xFF, 0xFF ) );

	
	srcRect.x = 0; srcRect.y = 0;
	srcRect.w = tam.bola.x;
	srcRect.h = tam.bola.y;
	dstRect.x = tiro.x;
	dstRect.y = tiro.y;
	
	if( SDL_BlitSurface( gJPGSurface, &srcRect, 
								 screenSurface, &dstRect ) < 0 ) {
		printf( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
		quit = true;
	}
	
	//Update the surface
	SDL_UpdateWindowSurface( janela );
}
