#include "0.cabecalho.h"

#ifndef DADOS //evitar inclusões cíclicas ("guarda de cabeçalho")
	#define DADOS
	
	/* TIPOS */

	typedef struct _Bola{
		byte cor;
		struct _Bola *vizinhos[6];
		int x,y;
		bool morreu;
	} Bola;

	typedef struct{
		char cor;
		float x,y;
		struct{
			float x,y;
		}vel;
	} Tiro;
	
	/* PROTÓTIPOS */
	
	bool iniciarJogo(void);//iniciar globais; preparar jogo

	bool insere(byte b, int x, int y);
	Bola *obter(int x, int y);
	bool remover(int x, int y);
	
	byte sortear();
	bool preencher();//retorna se houve sucesso
	void percorrer(void *func(Bola *b));
	voidvoid liberar_tudo;

	int getLinha(Bola b);
	int getColuna(Bola b, int linha);
	
	/* GLOBAIS */
	
	extern Coordenadas velocidade;
	extern Bola *matriz[linhas][colunas];
	extern Tiro tiro;
	
	struct _medidas{
		Coordenadas tela;
		Coordenadas campo;//ainda não em uso
		Coordenadas bola;
	}extern tam;
	
#endif
