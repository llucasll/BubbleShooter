#include "0.cabecalho.h"

#ifndef DADOS //evitar inclusões cíclicas ("guarda de cabeçalho")
	#define DADOS

	/* TIPOS */

	typedef struct /*_Bola*/{
		byte cor;
		//struct _Bola *vizinhos[6];
		int x,y;
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

	bool insere(byte b, int x, int y);
	Bola *obter(int x, int y);
	bool remover(int x, int y);

	byte sortear(void);
	bool preencher(void);//retorna se houve sucesso
	void percorrer(void *func(Bola *b));
	voidvoid liberar_tudo;

	int getLinha(Bola b);
	int getColuna(Bola b, int linha);

	/* GLOBAIS */

	struct _medidas{
		Coordenadas tela;
		//Coordenadas matriz;//ainda não em uso
		Coordenadas bola;
		byte cores;
	}extern tam;
	
	extern Surface sprites[ncores]; //Vetor de imagens :^)
	extern Coordenadas velocidade;
	//extern Bola ***matriz;
	extern Bola matriz[linhas][colunas];
	extern int ordem[linhas][colunas];
	extern Tiro tiro;

#endif
