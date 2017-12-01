//#include "../lib-headers/lib.h"
#include "lib.h"

//typedef void (*aaa)(void);
void *_executar(void *func){
	//printf("oi\n");
	//printf("%d\n",n);
	//void (*x) (void) = (void (*)(void))func;
	//x();
	//x();
	
	((voidvoid*)func)();
}
	
Thread executar(voidvoid *executavel){
	//int n = 5;
	/*
	void *tete(void *NADA){
		printf("oI");
	}*/
	
	//printnl();
	
	Thread t;
	pthread_create(&t, NULL, _executar, (void*)executavel);
	return t;
}

/*
bool semaforo = true;

void *th(void){
	int i=0;
	printnl();
	while(semaforo){
		i++;
		printf("Ola numero %d\n",i);
		sleep(1);
	}
	printf("Encerrando...\n");
	//pthread_exit(NULL);
	printnl();
}
*/

/*

//const unsigned char false = 0;
//const unsigned char true = 1;

#ifndef BOOLEANO
#define BOOLEANO
const unsigned char false = 0;
const unsigned char true = 1;
#endif
*/
