//#include "../lib-headers/lib.h"
#include "lib.h"

//typedef void (*aaa)(void);
void *_executar(void *func){
	//printf("oi\n");
	//printf("%d\n",n);
	//void (*x) (void) = (void (*)(void))func;
	//x();
	//x();
	
	((void (*)(void))func)();
}
	
Thread executar(void *func (void)){
	//int n = 5;
	/*
	void *tete(void *NADA){
		printf("oI");
	}*/
	
	//printnl();
	
	Thread t;
	pthread_create(&t, NULL, _executar, func);
	return t;
}

/*

//const unsigned char false = 0;
//const unsigned char true = 1;

#ifndef BOOLEANO
#define BOOLEANO
const unsigned char false = 0;
const unsigned char true = 1;
#endif
*/
