#include "iu.h"

/* PARA USO INTERNO DA BIBLIOTECA */

/* FUNÇÕES QUE AS THREADS EXECUTAM */
voidvoid _thread_principal;
voidvoid _thread_eventos;
voidvoid _thread_visualizacao;

/* FUNÇÃO INTERNA */
void _newJanela(int x, int y, char nome[]);

/* COMUNICAÇÃO ENTRE AS THREADS */
struct __novaJanela{
	Janela janela;
	int x;
	int y;
	char* nome;
	Thread thread;//TODO
}extern _novaJanela;
