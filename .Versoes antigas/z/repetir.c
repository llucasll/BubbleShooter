#include <stdlib.h>
#include <stdio.h>
int main(void){
	while(1){//!feof(stdin)){
		system("make exec");
		printf("\n\
				LEIA-ME\n\
			Tecle ESC para encerrar.\n\
	Use qualquer outra tecla para executar novamente...\n\n");
		
		//fflush(stdin);
		system("/bin/stty raw");
		char c = fgetc(stdin);
		if(/*c==13||*/c==27) break;
		//printf("\n\n\%d\n\n",fgetc(stdin));
		system("/bin/stty cooked");
	}
	system("/bin/stty cooked");
}

/*
printf("\n\
				LEIA-ME\n\
		O programa irá se repetir indefinidamente.\n\
		Use CRTL+C ou ESC para encerrar o jogo,\n\
			e CRTL+C novamente para encerrar o loop;\n\
		Use CRTL+C ou ESC para encerrar o jogo,\n\
			e em seguida ENTER para iniciar novamente.\n\n");*/
