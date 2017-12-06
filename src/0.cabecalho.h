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
	#include "../lib/debug.h"

	/* CONSTANTES */
	#define linhas 9
	#define colunas 17
	#define linhastotal 12
	#define ncores 6

	/* Global Variables */
	extern Janela janela; //The window we'll be rendering to
	extern Surface screenSurface; //The surface contained by the window

	extern const Coordenadas campo;//tamanhos

	/* ERROS */
	//#define
#endif
