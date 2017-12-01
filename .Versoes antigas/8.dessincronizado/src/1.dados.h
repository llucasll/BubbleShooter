#include "0.cabecalho.h"
#ifndef DADOS //evitar inclusões cíclicas ("guarda de cabeçalho")
	#define DADOS
	
	/* TIPOS */
	typedef struct{
		int x,y;
	} Coordenadas;

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
	
	/*
	typedef struct{
		int nada;
	}_globais;
	
	_globais o;
	
	#undef _globais
	int _globais;
	*/
	
	/* PROTÓTIPOS */
	
	bool iniciarJogo(void);//iniciar globais; preparar jogo

	bool insere(byte b, int x, int y);
	Bola *obter(int x, int y);
	bool remover(int x, int y);
	
	byte sortear();
	bool preencher();//retorna se houve sucesso
	void percorrer(void *func(Bola *b));
	void liberar_tudo();

	int getLinha(Bola b);
	int getColuna(Bola b, int linha);
	
	/* GLOBAIS */
	extern const Coordenadas campo, npc, tela;//tamanhos
	extern Coordenadas velocidade;
	extern Bola *matriz[linhas][colunas];
	extern Tiro tiro;
	
	/* Global Variables */
	extern SDL_Window* gWindow; //The window we'll be rendering to
	extern SDL_Surface* gScreenSurface; //The surface contained by the window
	extern SDL_Surface* gJPGSurface; //Current displayed PNG image

	extern bool quit; //Main loop flag
	
#endif
//#endif
