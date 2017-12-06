#include "3.debug.h"

void exibeMatriz(void){
	for(int y=0;y<linhas;y++){
		for(int x=0;x<colunas;x++)
			//coordenadas
			//printf("%d,%d\t",getColuna(matriz[y][x].x,matriz[y][x].y),getLinha(matriz[y][x].y));
			//cor TODO
			printf("%d,%d\t",getColuna(matriz[y][x].x,matriz[y][x].y),getLinha(matriz[y][x].y));
		printnl();
	}
}
