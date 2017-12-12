#include "../1.dados.h"

#include "3.fim.h"
#include "../partida/3.partida.h"
#include "2.fim.h"
#include "../3.visualizacao.h"

bool exibeScores;
//Surface botaoMenu;
Surface fimExit;

void vitoriaView(void){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0xEE, 0xEE, 0xEE ) );

	//printSurface(screenSurface,menuOver,0,0,tam.tela.x,tam.tela.y);

	//80,210,170,60
	//Update the surface
	SDL_UpdateWindowSurface( janela );
}

void derrotaView(void){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0x22, 0x22, 0x22 ) );

	//printSurface(screenSurface,menuOver,0,0,tam.tela.x,tam.tela.y);

	//80,210,170,60
	//Update the surface
	SDL_UpdateWindowSurface( janela );
}

void fimView(void){
	//Fill the surface white
	SDL_FillRect( screenSurface, NULL,
						  SDL_MapRGB( screenSurface->format,
						  0x66, 0x66, 0x66 ) );


	printSurface(screenSurface,fimFundo,0,0,tam.tela.x,tam.tela.y);
	if(exibeScores)printSurface(screenSurface,fimOverScores1,0,0,tam.tela.x/2,tam.tela.y);
	else printSurface(screenSurface,fimOverScores0,0,0,tam.tela.x/2,tam.tela.y);
	printSurface(screenSurface, fimExit, 594, 426, 54, 54);
	if(musicaOn)printSurface(screenSurface,sound1,0,tam.tela.y-54,54,tam.tela.y);
	else printSurface(screenSurface,sound0,0,tam.tela.y-54,54,tam.tela.y);
	printScore(40,61,61,61,tam.tela.x/2-20-2,tam.tela.y*3/4-30+2);
	printScore(40,244,244,244,tam.tela.x/2-20,tam.tela.y*3/4-30);
	//printFimSurface(screenSurface,fimOverScores,0,0,tam.tela.x/2,tam.tela.y);
	//printScore();

	//80,210,170,60
	//Update the surface
	SDL_UpdateWindowSurface( janela );
}
