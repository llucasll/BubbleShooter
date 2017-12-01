#ifndef MAINLIBRARY
	#define MAINLIBRARY
	#include <stdbool.h>
	#include <stdarg.h>
	typedef void voidvoid(void);

	#define byte char

	/* threads */
	#include <pthread.h>
	#include <unistd.h>
	#define Thread pthread_t
	Thread executar(voidvoid *executavel);
	#define esperar(t) pthread_join(t, NULL) //void esperar(Thread *t);
	#define parar(t) pthread_cancel(t)

	#define ascii_num 0x30 + //numeros
	#define ascii_min 96 + //minusculas
	#define ascii_mai 64 + //maiusculas

	#include "debug.h"
#endif
