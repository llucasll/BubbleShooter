/*
	A estrutura do jogo foi dividida seguindo alguns conceitos de MVC.
	Os arquivos são numerados com um código, que antecede seu nome, seguindo a numenclatura:

	0. Inicializações básicas
	1. Dados
	2. Controle
	3. Visualização
*/

#include "0.all.h"

int main (int argc, char* args[]){
	iniciar();//controle
	jogo();//mecanica
	encerrar();//controle
}
