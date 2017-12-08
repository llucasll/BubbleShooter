#include "../lib.h"
#include "../debug.h"

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
	
	// FUNÇÕES-PADÃO
	voidvoid stopDefault;
	voidvoid eventsDefault;

	// FUNÇÕES
	Janela newJanela(int x, int y, char nome[]);
	#define surfaceFrom SDL_GetWindowSurface

	Surface loadImage( char *path, Surface base );
	void printSurface(Janela janela, Surface surface, int x, int y, int tamx, int tamy);

	Coordenadas getMousePos(void);
#endif

/* COMPORTAMENTO DE FRAMEWORK */

// Função inicial (substitui a main)
// Aqui se define o restante do ciclo de vida do programa
voidvoid init;
	// Ela não pode ficar em uma struct pq é um protótipo,
	// o programa espera que haja um init assim como espera um main.

// Threads
struct{	
	Thread principal; // Esse é o programa em si
	Thread eventos; // Gerencia os eventos
	Thread visualizacao; // Thread responsável pela apresentação
}threads;

struct{
	/* THREADS */
	voidvoid *run; // Função principal
	voidvoid *checkEvents; // Gerencia os eventos
	voidvoid *screenRefresh; // Executado periodicamente pelo atualizador
	
	/* Comportamentos de resposta ao Evento */
	voidvoid *click; // O mouse clicou
	void (*mouseMove)(Coordenadas pos); // O mouse se moveu na tela
	voidvoid *keyDown; // Alguma tecla pressionada (no teclado)
	//SDLKey
	voidvoid *rightClick; // Clique direito do mouse
	
	/* ENCERRAMENTO DO PROGRAMA */
	voidvoid *stop; // Inicia o encerramento do programa
	voidvoid *finish; // Encerra o programa
}on;

// VARIÁVEIS COMPARTILHADAS
extern bool quit; // Semáforo global que controla o término de todo o programa


//void changeMonitor(voidvoid novo);
