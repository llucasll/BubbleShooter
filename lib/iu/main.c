
#include "interno.h"

int main( int argc, char* args[] ) {

	// Inicializa com os padrões biblioteca, o resto fica a cargo do init
	on.run = NULL;
	on.checkEvents = eventsDefault;
	on.screenRefresh = NULL;
	
	on.click = NULL;
	on.mouseMove = NULL;
	on.keyDown = NULL;
	on.rightClick = NULL;
	
	on.stop = stopDefault;
	on.finish = NULL;

	// Chama o "main"
	init();

	// Iniciar as threads
	threads.principal = executar(_thread_principal);
	threads.eventos = executar(_thread_eventos);

	// Aguarda o fim do programa
	while(!quit);
	esperar(threads.visualizacao);
	//TODO encerrar threads

	// Chama a função de finalização
	if(on.finish) on.finish();//Free resources and closing SDL

	return 0;
}

