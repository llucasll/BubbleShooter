#include "3.debug.h"

typedef char* (*bolaToInt)(Bola b);

void exibeMatriz(bolaToInt printa){
	for(int y=0;y<linhastotal;y++){
		for(int x=0;x<colunas;x++)
			if(existe(x,y))
				if(printa)
					printf("%s\t",printa(matriz[y][x]));
				else
					printf("X\t");
			else printf("\t");
		printnl();
	}
}
