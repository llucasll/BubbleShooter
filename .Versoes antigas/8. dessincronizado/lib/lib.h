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
#define esperar(t) pthread_join(t, NULL) //void esperar(Thread *t);
#define parar(t) pthread_cancel(t)

#define ascii_num 0x30 + //numeros
#define ascii_min 96 + //minusculas
#define ascii_mai 64 + //maiusculas
