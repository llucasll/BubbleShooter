#include "lib.h"

static void *_executar(void *func){
	((voidvoid*)func)();
}

Thread executar(voidvoid *executavel){	
	Thread t;
	int result = pthread_create(&t, NULL, _executar, (void*)executavel);
	if(result){
		//printf("\nErro ao criar Thread!\n\n");
		return 1;
	}
	return t;
}

static bool semente = false;

int aleatorio(int max){
	
	if(!semente){
		// Intializes random number generator
		time_t t;
		srand((unsigned) time(&t));
		
		semente = true;
	}
	
	return rand()%max;
}
