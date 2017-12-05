#include "0.all.h"

#ifndef TIPOS //evitar inclusões cíclicas ("guarda de cabeçalho")
	#define TIPOS

	/* TIPOS */
	typedef struct{
		int x,y;
	} Coordenadas;

	typedef struct _Bola{
		char cor;
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

#endif

#ifdef CABECALHO
	#ifndef DADOS //evitar inclusões cíclicas ("guarda de cabeçalho")
		#define DADOS

		bool iniciarJogo(void){//iniciar globais; preparar jogo
		}

		bool insere(Bola b, Coordenadas pos){
		}
		bool remove2(Bola b, Coordenadas pos){
		}

		int getLinha(Bola b){
			return (int) b.x/npc.x;
		}

		int getColuna(Bola b, int linha){
			return (int) (linha%2 ? b.y-npc.y/2 : b.y)/npc.y;
		}

	#endif
#endif
