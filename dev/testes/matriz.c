#include <stdio.h>
#include <stdlib.h>

/* Prototipos das funcoes ***************************************************/
int **CreateArray(int c, int l);
void DeleteArray(int **array, int l);

/* Implementacao ************************************************************/
/* CreateArray */
int **CreateArray(int c, int l){
	int cy;
	int **array;
	array = (int **)malloc(sizeof(int *) * l);
	if(!array)
		return 0;

	for(cy = 0; cy < l; cy++){
		array[cy] = (int *)malloc(sizeof(int) * c);
		if(!array[cy]){
			DeleteArray(array, cy);
			return 0;
		}
	}

	return array;
}

/* DeleteArray */
void DeleteArray(int **array, int l){
	int cy;

	for(cy = 0; cy < l; cy++)
		if(array[cy])
			free(array[cy]);

	if(array)
		free(array);
}
/****************************************************************************/

/* Funcao principal */
void main(){
	int **array;
	int c, l;
	int sc = 5, sl = 100;
	//clrscr();

	limpa();

	/* Cria uma matriz com tamanho sc x sl */
	array = CreateArray(sc, sl);
	if(!array){
		printf("Erro de alocação de memória!");
		return;
	}

	/* Preenche a matriz com valores */
	for(l = 0; l < sl; l++)
		for(c = 0; c < sc; c++)
			array[l][c] = c;

	/* Imprime a matriz para mostrar que funcionou */
	for(c = 0; c < sc; c++)
		printf("\t[%d]", c);

	for(l = 0; l < sl; l++){
		printf("\n[%d]", l);
		for(c = 0; c < sc; c++)
			printf("\t%3d", array[l][c]);
			//getch();
	}

	scanf("%c",&array[0][0]);
	/* Apaga a matriz */
	DeleteArray(array, sl);

	//getch();
}
