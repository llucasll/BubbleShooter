//#include "../lib-headers/lib.h"
//#include "../lib-headers/terminal.h"
#include "terminal.h"

#include <stdio.h>
#include <stdlib.h>

void println(char s[]){
	printf("%s%c",s,'\n');
	//printf(s); printnl();
}

void printnl(void){//print new line
	//printf("\n");
	println("");
}

void printls(int n){//print LineS
	int i;
	for(i=0; i<n; i++)
		//printf("\n");
		printnl();
}

void printint(int n){
	printf("%d\n",n);
}

void limpa(){
	system ("clear");
	system ("clear");
}
