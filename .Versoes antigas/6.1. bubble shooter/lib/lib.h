typedef unsigned char bool;
#ifndef false
#define false 0
#define true 1
#endif

#define byte char

/* threads */
#include <pthread.h>
#include <unistd.h>
#define Thread pthread_t
Thread executar(void *func(void));
//void esperar(Thread *t);
#define esperar(t) pthread_join(t, NULL)
#define parar(t) pthread_cancel(t)

/*
//#include "../src/0.bool.h"

#ifndef LIB
#define LIB
const unsigned char false = 0;
const unsigned char true = 1;
#endif
*/
