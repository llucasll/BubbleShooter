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
	printSurface(screenSurface, sprites[cor], x, y, tam.bola.x, tam.bola.y);
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
