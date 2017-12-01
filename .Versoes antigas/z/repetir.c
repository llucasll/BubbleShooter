#include <stdlib.h>
#include <stdio.h>
int main(void){
	//int i=1;
	while(1){//!feof(stdin)){
		system("make exec --no-print-directory");//https://www.gnu.org/software/automake/manual/html_node/Tricks-For-Silencing-Make.html
		printf("\n\
				LEIA-ME\n\
			Tecle ESC para encerrar.\n\
	Ou use qualquer outra tecla para executar novamente...\n");
		
		//fflush(stdin);
		system("/bin/stty raw");
		//printf("antes %d",i);
		char c = fgetc(stdin);
		//printf("depois %d\n",i);
		if(/*c==13||*/c==27) break;
		//printf("\n\n\%d\n\n",fgetc(stdin));
		//printf("OI");
		system("/bin/stty cooked");
		printf("\r        \n");
		//i++;
	}
	system("/bin/stty cooked");
	printf("\r        ");
}

/*
printf("\n\
				LEIA-ME\n\
		O programa irá se repetir indefinidamente.\n\
		Use CRTL+C ou ESC para encerrar o jogo,\n\
			e CRTL+C novamente para encerrar o loop;\n\
		Use CRTL+C ou ESC para encerrar o jogo,\n\
			e em seguida ENTER para iniciar novamente.\n\n");*/
