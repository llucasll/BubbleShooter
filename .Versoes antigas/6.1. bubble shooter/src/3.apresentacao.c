#include "3.apresentacao.h"

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

void atualiza(){
	SDL_Rect srcRect, dstRect;
	//Fill the surface white
	
	//printf("%s",gScreenSurface);
	//oi();
	/*SDL_MapRGB( gScreenSurface->format, 
						  0xFF, 0xFF, 0xFF );
						  oi();
						  */
						  
	SDL_FillRect( gScreenSurface, NULL, 
						  SDL_MapRGB( gScreenSurface->format, 
						  0xFF, 0xFF, 0xFF ) );

	srcRect.x = 0; srcRect.y = 0;
	srcRect.w = npc.x;
	srcRect.h = npc.y;
	dstRect.x = tiro.x;
	dstRect.y = tiro.y;
	
	if( SDL_BlitSurface( gJPGSurface, &srcRect, 
								 gScreenSurface, &dstRect ) < 0 ) {
		printf( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
		quit = true;
	}

	//printf("%f, %f\n",tiro.x,tiro.y);
	
	//Update the surface
	SDL_UpdateWindowSurface( gWindow );
}

void (*atualizarTela)(void);

void *atualizador(void){
	while(!quit){
		if(atualizarTela)
			atualizarTela();
		//else
		//	println("nao");
		//printoi();
		//usleep(1000000/24);
	}
}
