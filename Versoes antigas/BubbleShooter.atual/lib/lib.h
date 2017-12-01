/*typedef unsigned char bool;
#ifndef BOOLEANOS
#define BOOLEANOS
#define false 0
#define true 1
#endif
*/

#ifndef MAINLIBRARY
	#define MAINLIBRARY
	#include <stdbool.h>
	typedef void voidvoid(void);

	/*
	typedef void teste2(void);
	teste2 func2;//aqui se declara uma função do tipo teste2. Porém, não é possível definí-la assim
	void func2(){}//aqui se define
	teste2 *func3();//aqui retorna um ponteiro do tipo teste2

	//CÓDIGO DE EXEMPLO. COPIAR PARA O MAIN.

	voidvoid *ola = NULL;

	void fun(){
		println("Ptrs funcionam!");
	}
	ola = fun;

	ola();
	*/

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
