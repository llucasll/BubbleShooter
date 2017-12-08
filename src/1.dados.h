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

	bool insere(int x, int y, byte b);
	Bola *obter(int x, int y);
	bool remover(int x, int y);
	bool existe(int x, int y);

	byte sortear(void);
	voidvoid preencher;//retornaria se houve sucesso
	void percorrer(void *func(Bola *b));
	voidvoid liberar_tudo;

	int getLinha(int posY);
	int getColuna(int posX, int posY);

	/* GLOBAIS */

	struct _medidas{
		Coordenadas tela;
		//Coordenadas matriz;//TODO ainda não em uso
		Coordenadas bola;
		byte cores;
	}extern tam;

	extern Surface sprites[ncores]; //Vetor de imagens :^)
	extern Coordenadas velocidade;
	//extern Bola ***matriz;
	extern Bola matriz[linhastotal][colunas];
	extern int ordem[linhas][colunas];
	extern Tiro tiro;

	extern Surface menuOverNot;
	extern Surface menuOverExit;
	extern Surface menuOverPlay;
	extern Surface partidaExit0;
	extern Surface partidaExit1;
	extern Surface partidaBg[5];
	extern Surface partidaHud;
	extern Surface partidaMenu0;
	extern Surface partidaMenu1;
	extern Surface blackRect;
	extern bool partidaMenuStatus;
	extern bool partidaExitStatus;
	extern byte bgIndex;

	extern Surface menuFundo;
	extern Mix_Music *musica;

#endif
