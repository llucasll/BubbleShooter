#include "3.debug.h"

typedef char* (*bolaToInt)(Bola b);

void exibeMatriz(bolaToInt printa){
	for(int y=0;y<linhas;y++){
		for(int x=0;x<colunas;x++)
			if(printa)
				printf("%s\t",printa(matriz[y][x]));
			else
				printf("X\t");
		printnl();
	}
}
