#include "1.dados.h"

/* GLOBAIS */
Coordenadas velocidade;
Bola matriz[linhastotal][colunas];
Tiro tiro;



Bola** getVizinhos(int x, int y){
	Bola** vizinhos = malloc(sizeof(Bola)*6);

	if (vizinhos == NULL) {
		printf ("Socorro! malloc devolveu NULL!\n");
		exit (EXIT_FAILURE);
	}

	vizinhos[0] =
		(y%2? existe(x,y-1) : existe(x-1,y-1))?
			y%2? obter(x,y-1) : obter(x-1,y-1)
		:
			NULL;
	vizinhos[1] =
		(y%2? existe(x+1,y-1) : existe(x,y-1))?
			y%2? obter(x+1,y-1) : obter(x,y-1)
		:
			NULL;

	vizinhos[2] =
		existe(x-1,y)?
			obter(x-1,y)
		:
			NULL;
	vizinhos[3] =
		existe(x+1,y)?
			obter(x+1,y)
		:
			NULL;

	vizinhos[4] =
		(y%2? existe(x,y+1) : existe(x-1,y+1))?
			y%2? obter(x,y+1) : obter(x-1,y+1)
		:
			NULL;
	vizinhos[5] =
		(y%2? existe(x+1,y+1) : existe(x,y+1))?
			y%2? obter(x+1,y+1) : obter(x,y+1)
		:
			NULL;

	return vizinhos;
}

void liberaVizinhos(Bola*** ptr){
	for(int i=0; i<6; i+=2)
		(*ptr)[i] = NULL;
	free (*ptr);
	*ptr = NULL;
}

byte sortear(void){
	return rand() % tam.cores;
	//return 0;
}

void preencher(void){
	for(int y=0;y<linhas;y++){
		for(int x=0;x<colunas;x++)
			insere(x,y,sortear());
	}
	for(int y=linhas;y<linhastotal;y++){
		for(int x=0;x<colunas;x++){
			matriz[y][x].existe = false;
			matriz[y][x].x = tam.bola.x * x + (y%2?tam.bola.x/2:0);
			matriz[y][x].y = tam.bola.y * y/*- 4*y */  /* * 0.9*/;//TODO
			matriz[y][x].pos.x = x;
			matriz[y][x].pos.y = y;
		}
	}
}

bool valido(int x, int y){
	if(x>=0 && y>=0 && x<colunas && y<linhastotal)
		return true;
	else return false;
}

bool insere(int x, int y, byte b){
	if(existe(x,y))
		logger("Erro!! Bola SOBRESCRITA");

	if(valido(x,y)){
		matriz[y][x].cor = b;

		matriz[y][x].existe = true;
		matriz[y][x].morreu = false;

		matriz[y][x].pos.x = x;
		matriz[y][x].pos.y = y;

		matriz[y][x].x = tam.bola.x * x + (y%2?tam.bola.x/2:0);
		matriz[y][x].y = tam.bola.y * y/*- 4*y */  /* * 0.9*/;//TODO

		return true;
	}
	else return false;
}
bool remover(int x, int y){
	matriz[y][x].existe = false;
}

bool existe(int x, int y){
	Bola* b = obter(x,y);
	if(b)
		if(b->existe)
			return true;

	else return false;
}

Bola *obter(int x, int y){
	if(valido(x,y))
		return &matriz[y][x];
	else
		return NULL;
}

#define sinal(x) (x<0 ? -1 : 1)

int arredonda(int dividendo, int divisor){
	int inteiro = dividendo/divisor;
	return inteiro;
}

int getLinha(int posY){
	return arredonda(posY+tam.bola.y/2,tam.bola.y);
}


int getColuna(int posX, int posY){
	int linha = getLinha(posY);
	return arredonda((linha%2 ? posX/*+(tam.bola.x/*0.9)/2*/ : posX+(tam.bola.x/2)),(tam.bola.x/**0.9*/));
}
