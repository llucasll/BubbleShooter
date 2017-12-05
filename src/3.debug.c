#include "3.debug.h"

void exibeMatriz(void){
	for(int y=0;y<linhas;y++){
		for(int x=0;x<colunas;x++)
			printf("%d,%d\t",getColuna(matriz[y][x],getLinha(matriz[y][x])),getLinha(matriz[y][x]));
		printnl();
	}
}
