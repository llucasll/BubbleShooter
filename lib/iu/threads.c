
#include "interno.h"

void _thread_principal(void){
	//While application is running
	while(!quit){
		if(on.run)
			on.run();		
		usleep(1000);
	}
}

void _thread_eventos(void){
	//While application is running
	while(!quit){
		if(on.checkEvents)
			on.checkEvents();
		usleep(1000);
	}
}

void _thread_visualizacao(void){

	//Start up SDL and create window
	//_novaJanela.janela = _newJanela (_novaJanela.x, _novaJanela.y, _novaJanela.nome);
	_newJanela (_novaJanela.x, _novaJanela.y, _novaJanela.nome);

	if( !_novaJanela.janela ) {
		logger( "Failed to initialize the Window!\n" );
		exit(1);
	}

	//While application is running
	while(!quit){
		if(on.screenRefresh)
			on.screenRefresh();
		usleep(1000000/24);
	}
}
