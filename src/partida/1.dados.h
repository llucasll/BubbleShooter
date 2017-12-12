#ifndef DADOS //evitar inclusões cíclicas ("guarda de cabeçalho")
	#define DADOS
	
	#include "../0.cabecalho.h"

	/* TIPOS */

	typedef struct{
		byte cor;
		int x,y;
		Coordenadas pos;
		bool morreu;
		bool existe;
	} Bola;

	typedef struct{
		byte cor;
		float x,y;
		struct{
			float x,y;
		}vel;
	} Tiro;

	/* PROTÓTIPOS */

	bool insere(int x, int y, byte b);
	Bola *obter(int x, int y);
	bool remover(int x, int y);
	bool existe(int x, int y);
	bool valido(int x, int y);

	Bola** getVizinhos(int x, int y);
	void liberaVizinhos(Bola*** ptr);
	byte sortear(void);
	voidvoid preencher;
	void percorrer(void *func(Bola *b));
	voidvoid liberar_tudo;

	int getLinha(int posY);
	int getColuna(int posX, int posY);

	/* GLOBAIS */
	extern Bola matriz[linhastotal][colunas];
	extern int ordem[linhas][colunas];
	extern Tiro tiro;
	
#endif
