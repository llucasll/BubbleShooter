#include "2.controle.h"

int main( int argc, char* args[] ) {

	//iniciar();//controle
	//jogo();//mecanica
	//encerrar();//controle
	
	/*Coordenadas c = {3,4};
	insere(2,c);
	
	struct{
		int (*teste)(void){
			return 26;
		}
	}teste;
		
	printint(teste.teste());
	*/
	
	preparar();
	
	atualizarTela=atualiza;
	Thread t = executar(atualizador);
	
	execucao();
	
	esperar(t);
	
	closing();//Free resources and closing SDL

	return 0;
}
