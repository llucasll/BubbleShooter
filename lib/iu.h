#include "lib.h"
#include "debug.h"

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

// Função inicial (substitui a main)
voidvoid init;
	// Ela não pode ficar em uma struct pq é um protótipo,
	// o programa espera que haja um init assim como espera um main.

// Aqui se define o restante do ciclo de vida do programa
struct{
	voidvoid *principal; // Função principal
	voidvoid *monitor; // Gerencia os eventos
	voidvoid *close; // Finaliza a execução
}controle;

// Threads
struct{	
	Thread principal; // Esse é o programa em si
	Thread monitor; // Gerencia os eventos
	Thread visualizador; // Thread responsável pela apresentação
}threads;

struct{
	voidvoid *screenRefresh; // Executado periodicamente pelo atualizador
	voidvoid *quit; // Função chamada quando é momento de fechar
	voidvoid *click; // Comportamento de resposta ao Evento
}on;

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
void preparaJanela(Janela* janela, Surface* surface, int x, int y, char nome[]);
