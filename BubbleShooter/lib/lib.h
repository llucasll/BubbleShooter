#ifndef MAINLIBRARY //guarda de cabeçalho
	#define MAINLIBRARY
	
	/* BIBLIOTECAS OBRIGATÓRIAS */
	#include <stdbool.h>
	#include <stdarg.h>
	
	/* TIPOS */
	typedef void voidvoid(void);
	typedef char byte;//#define byte char

	/* THREADS */
	#include <pthread.h> // Lib
	#define Thread pthread_t // Tipo
	// Funções
	Thread executar(voidvoid *executavel);
	#define esperar(t) pthread_join(t, NULL) //void esperar(Thread *t);
	#define parar(t) pthread_cancel(t)

	/* CONSTANTES ASCII */
	#define ascii_num 0x30 + //numeros
	#define ascii_min 96 + //minusculas
	#define ascii_mai 64 + //maiusculas
	
#endif
