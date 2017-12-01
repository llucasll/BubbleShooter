#include "lib.h"

/* COMPORTAMENTO DE BIBLIOTECA */
#ifndef IUlib
	#define IUlib
	
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
	
	typedef SDL_Window* Janela;
	typedef SDL_Surface* Surface;
	
	typedef struct{
		int x,y;
	} Coordenadas;
#endif

/* COMPORTAMENTO DE FRAMEWORK */

// ESTRUTURAS
struct{	
	Thread principal;
	Thread monitor;//gerencia os eventos
	Thread atualizador;
}threads;

struct{
	/* Principais */
	voidvoid *screenRefresh;//comportamento
	
	/* Finalizar */
	voidvoid *quit;//listener(espera o evento)
	
	/* Eventos */
	voidvoid *mouseClick;//listener(espera o evento)
}on;

// FUNÇÃO PRINCIPAL (SUBSTITUI A MAIN)
voidvoid init;// Função inicial (substitui a main)
struct{
	voidvoid *executar;//Função principal
	voidvoid *monitor;//gerencia os eventos
	voidvoid *close;//comportamento
}controle;

// VARIÁVEIS COMPARTILHADAS
extern bool quit; // Semáforo global que controla o término de todo o programa

// FUNÇÕES-PADÃO
voidvoid quitDefault;
voidvoid monitorDefault;

// FUNÇÕES
Janela newJanela(int x, int y, char nome[]);
#define surfaceFrom SDL_GetWindowSurface
Surface loadImage( char *path, Surface base );
void changeMonitor(voidvoid novo);
