/*
	A estrutura do jogo foi dividida seguindo alguns conceitos de MVC.
	Os arquivos são numerados com um código, que antecede seu nome, seguindo a numenclatura:

	0. Inicializações básicas
	1. Dados
	2. Controle
	3. Visualização
*/

/*
 * 06_moving_images.c
 * Este programa move uma imagem pela tela. Ao colidir com uma parede a imagem irá ser refletida.
 * 2016/01/26
 * @adriano cruz
 */

#include "0.cabecalho.h"

#include "2.controle.h" // OU CHAMAR DE "JOGO" E SÓ IMPORTAR ELE, AO INVÉS DO CABEÇALHO TBM.

/*

int main (int argc, char* args[]){
	iniciar();//controle
	jogo();//mecanica
	encerrar();//controle
}

*/

/* Function prototypes */
/*SDL_Surface* loadSurface( char *path ); //Loads individual image
int init(); //Starts up SDL and creates window
int loadMedia(); //Loads media
void closing(); //Frees media and shuts down SDL
void createNPC( int x, int y, int velx, int vely); //Create NPC
void moveNPC(); //Move NPC
*/

int main( int argc, char* args[] ) {
	
	preparar();
	
	//while(true)
		execucao();
	
	//while(1);
	
	closing();//Free resources and closing SDL

	return 0;
}
