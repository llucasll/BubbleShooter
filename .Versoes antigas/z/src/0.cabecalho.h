/*
	Convenções de nomenclatura:
	
	* Variável/Função - primeiroSegundo
	* Tipos personalizados - PrimeiroSegundo
*/

/*
	chamadas à lib
	macros
	tipos
	protótipos
	globais

	func's de dados

	mecânica
	exibição/apresentação

	controle(geral)

	main

	//

	CABECALHO.H
		chamadas à lib
		macros
		-chamada a dados.h
		globais
	
	DADOS.H
		tipos
		func's de dados
		
	//
	
	APRESENTACAO.H
		exibição/apresentação
	MECANICA.H
		mecânica
	
	CONTROLE.C
		controle(geral)
	
	//
	
	CONTROLE.H
		controle(geral)
	
	MAIN.C
		main
	
	//
	
	DADOS.C
		func's de dados

	MECANICA.C, APRESENTACAO.C	
		mecânica
		exibição/apresentação
*/

/*#include "../lib-headers/iu.h"

TALVEZ VALESSE MAIS USAR APENAS PROTÓTIPOS, PARA EVITAR "JÁ DEFINIDO"
#include "0.all.h"
#include "0.cabecalho.c"

#include "2.controle.c"
#include "2.mecanica.c"
#include "3.iu.c"
#include "main.c"

	#include "1.dados.h" //define os tipos
	//#include "0.cabecalho.h" //define constantes, globais, etc
	#include "1.dados.h" //define as funções, etc

*/
#ifndef CABECALHO
	#define CABECALHO
	
	//#ifndef LIB
	//	#define LIB
	
		/* LIBS EXTERNAS
				Using SDL, SDL_image, standard IO, and strings */
		#include <SDL2/SDL.h>
		#include <SDL2/SDL_image.h>
		#include <stdio.h>
		#include <string.h>
		#include <time.h>
		#include <math.h>
		
		/* MINHAS LIBS */
		#include "../lib-headers/lib.h"
		#include "../lib-headers/terminal.h"
		
	//#endif

	//#ifndef MACROS //evitar inclusões cíclicas ("guarda de cabeçalho")
	//	#define MACROS

		/* CONSTANTES */
		#define linhas 10
		#define colunas 30
	//#endif

	#include "1.dados.h" //cabeçalho da camada de dados

	//#ifndef GLOBAIS
	//	#define GLOBAIS
	
		/* GLOBAIS */
		extern const Coordenadas campo, npc, tela;//tamanhos
		extern Coordenadas velocidade;
		extern Bola *matriz[linhas][colunas];
		extern Tiro tiro;
		
		/* Global Variables */
		extern SDL_Window* gWindow; //The window we'll be rendering to
		//SDL_Surface* imagem; //The imagem character
		extern SDL_Surface* gScreenSurface; //The surface contained by the window
		extern SDL_Surface* gJPGSurface; //Current displayed PNG image

		extern bool quit; //Main loop flag

	//#endif
#endif
