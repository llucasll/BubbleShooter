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

/*
bool semaforo = true;

void *th(void){
	int i=0;
	printnl();
	while(semaforo){
		i++;
		printf("Ola numero %d\n",i);
		sleep(1);
	}
	printf("Encerrando...\n");
	//pthread_exit(NULL);
	printnl();
}
*/


int main( int argc, char* args[] ) {
	
	//Thread t = executar(th);
	
	//pthread_create(&t, NULL, th, NULL);
	
	//atualizarTela = atualiza;
	
	preparar();
	
	atualizarTela=atualiza;
	Thread t = executar(atualizador);
	//oi();
	//while(true)
		execucao();
	
	//while(1);
	
	//semaforo = false;
	
	//pthread_join(t,NULL);
	//oi();
	parar(t);
	//oi();
	closing();//Free resources and closing SDL

	return 0;
}
