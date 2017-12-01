#include "lib.h"

static void *_executar(void *func){
	((voidvoid*)func)();
}

Thread executar(voidvoid *executavel){	
	Thread t;
	pthread_create(&t, NULL, _executar, (void*)executavel);
	return t;
}
