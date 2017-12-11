#include "1.dados.h"

/* GLOBAIS */
Coordenadas velocidade;
Bola matriz[linhastotal][colunas];//Bola **matriz;
Tiro tiro;

/* Global Variables */
Janela janela = NULL; //The window we'll be rendering to
Surface screenSurface = NULL; //The surface contained by the window
Surface sprites[ncores]; //Vetor de imagens :^)

Surface menuOverNot; //Fundo do menu
Surface menuOverPlay; //Fundo do menu
Surface menuOverExit; //Fundo do menu
Surface partidaExit0;
Surface partidaExit1;
Surface partidaBg[5];
Surface partidaHud;
Surface partidaMenu0;
Surface partidaMenu1;
Surface blackRect;
byte bgIndex;
bool partidaExitStatus;
bool partidaMenuStatus;
bool estourando;
TTF_Font* fonte;
SDL_Color ttfCor;
Surface msgPontos;
int score;
char scoreString[scoreDigit];

Surface menuFundo; //Fundo do menu
Mix_Music *musica = NULL;


Bola** getVizinhos(int x, int y){
	//int x = b.pos.x, y = b.pos.y;
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
}

void preencher(void){
	for(int y=0;y<linhas;y++){
		for(int x=0;x<colunas;x++)
			insere(x,y,sortear());
		//printnl();
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
	if(valido(x,y))
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
	//float decimal = (float)dividendo/(float)divisor-inteiro;
	//if(decimal>0.5)
	//	return inteiro + sinal(decimal);
	//else
		return inteiro;
}

int getLinha(int posY){
	//return (int) posY/tam.bola.y;
	return arredonda(posY+tam.bola.y/2,tam.bola.y);
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
	return arredonda((linha%2 ? posX/*+(tam.bola.x/*0.9)/2*/ : posX+(tam.bola.x/2)),(tam.bola.x/**0.9*/));
}

struct _medidas tam = {//TODO
	{648, 480},//tela
	//{30, 10},//campo
	{37, 37},//bola
	6
};
