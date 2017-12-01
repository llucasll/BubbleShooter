/*#include "lib.h"

#define lambda(return_type, body_and_args) \
    ({                                     \
        return_type __fn__ body_and_args   \
            &__fn__;                       \
    })
    
// Constantes para Interface do Usuário
struct{
	struct{
		bool clicado;
	}mouse;
}iuc;

// Tipos para Interface do Usuário
struct{
	struct{
		int x;
	}janela;
}iut;

// Objetos para Interface do Usuário
struct{
	
}iuo;

// Funções para Interface do Usuário
struct{
	struct{
		int (*moveu)(int);
		int (*clicou)(int);
	}mouse;
}iuf;*/

#include "lib.h"

/* COMPORTAMENTO DE BIBLIOTECA */
#ifndef IUlib
	#define IUlib
	
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
	
	typedef SDL_Window* Janela;
	typedef SDL_Surface* Surface;
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
void changeMonitor(voidvoid novo);
