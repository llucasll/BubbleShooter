#include "1.dados.h"

/* GLOBAIS */
Coordenadas velocidade;
Bola matriz[linhastotal][colunas];//Bola **matriz;
Tiro tiro;

/* Global Variables */
Janela janela = NULL; //The window we'll be rendering to
Surface screenSurface = NULL; //The surface contained by the window
Surface sprites[ncores]; //Vetor de imagens :^)
Surface menuFundo; //Fundo do menu
Mix_Music *musica = NULL;

byte sortear(void){
	return rand() % tam.cores;
}

void preencher(void){
	for(int y=0;y<linhas;y++){
		for(int x=0;x<colunas;x++)
			insere(x,y,sortear());
		//printnl();
	}
}

bool insere(int x, int y, byte b){
	if(existe(x,y))
		logger("Erro!! Bola SOBRESCRITA");

	matriz[y][x].cor = b;
	matriz[y][x].existe = true;
	matriz[y][x].morreu = false;

	//printint(tam.bola.x * x + (y%2?tam.bola.x/2:0));

	matriz[y][x].x = tam.bola.x * x + (y%2?tam.bola.x/2:0);
	matriz[y][x].y = tam.bola.y * y/*- 4*y */  /* * 0.9*/;//TODO

	//printf("%d,%d\t",getColuna(matriz[y][x],getLinha(matriz[y][x])),getLinha(matriz[y][x]));

	//println("%d\t%d\n%d\t%d\n", matriz[y][x].x, getLinha(matriz[y][x]), matriz[y][x].y, getColuna(matriz[y][x],getLinha(matriz[y][x])));
	///println("%d\t%d\n%d\t%d\n", x, getLinha(matriz[y][x]), y, getColuna(matriz[y][x],getLinha(matriz[y][x])));
	//getColuna(matriz[y][x],getLinha(matriz[y][x]));

	//println("%d dividido por %d = %d",x,y,arredonda(x,y));

	///printnl();
	//println("%d",matriz[y][x].x/tam.bola.x);
}
bool remover(int x, int y){
	matriz[y][x].existe = false;
}

bool existe(int x, int y){
	Bola* b = obter(x,y);
	if(b)
		//println("%d %sexiste em %d,%d", b, b->existe?"":"não ",b->x,b->y);
		if(b->existe)
			return true;

	else return false;
}

Bola *obter(int x, int y){
	if(x>=0 && y>=0 && x<colunas && y<linhastotal)
		return &matriz[y][x];
	else
		return NULL;
}

/*
int arredonda(int dividendo, int divisor){
	int resultado = divisor?dividendo/divisor:0;
	return (int) divisor*resultado < dividendo? resultado+1 : resultado;
}
*/

#define sinal(x) (x<0 ? -1 : 1)

int arredonda(int dividendo, int divisor){
	int inteiro = dividendo/divisor;
	float decimal = (float)dividendo/(float)divisor-inteiro;
	if(decimal>0.5)
		return inteiro + sinal(decimal);
	else
		return inteiro;
}

int getLinha(int posY){
	//return (int) posY/tam.bola.y;
	return arredonda(posY,tam.bola.y);
}



int getColuna(int posX, int posY){
	/*int tmp = linha%2 ? b.y-(tam.bola.y*0.9)/2 : b.y;
	if(tmp / tam.bola.y){
		tmp /= (tam.bola.y*0.9);
		tmp +=1;
	}
	else
		tmp /= tam.bola.y;
	//printf("%d\t%d", tmp,linha);
	return (int) tmp;*/


	int linha = getLinha(posY);
	/*
	int candidato = (int) (linha%2 ? posX-(tam.bola.x/**0.9* /)/2 : posX)/(tam.bola.x/**0.9* /);
	int ajuste = posX - candidato*tam.bola.x;
	float tolerancia = tam.bola.x/2;
	return abs(ajuste) < tolerancia ? candidato : candidato + (sinal(ajuste));
	*/
	return arredonda((linha%2 ? posX-(tam.bola.x/**0.9*/)/2 : posX),(tam.bola.x/**0.9*/));
}

struct _medidas tam = {//TODO
	{648, 480},//tela
	//{30, 10},//campo
	{37, 37},//bola
	6
};
