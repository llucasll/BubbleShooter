#ifndef CABECALHO
	#define CABECALHO
	
	/* LIBS EXTERNAS */
	#include <stdio.h>
	#include <string.h>
	#include <time.h>
	#include <math.h>
	
	/* LIBS PERSONALIZADAS */
	#include "../lib/lib.h"
	#include "../lib/terminal.h"
	#include "../lib/iu.h"
	
	/* CONSTANTES */
	#define linhas 10
	#define colunas 30
	
	/* Global Variables */
	extern Janela janela; //The window we'll be rendering to
	extern Surface screenSurface; //The surface contained by the window
	extern Surface gJPGSurface; //Current displayed PNG image

	typedef struct{
		int x,y;
	} Coordenadas;
	
	extern const Coordenadas campo;//tamanhos
	
	/* ERROS */
	//#define 
#endif
