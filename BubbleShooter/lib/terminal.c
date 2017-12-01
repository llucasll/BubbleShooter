#include "terminal.h"

#include <stdio.h>
#include <stdlib.h>

void println(const char *format, ...){
	va_list arg;

	va_start (arg, format);
	vfprintf (stdout, format, arg);
	va_end (arg);
		
	printf("\n");//TODO
}

void printnl(void){//print new line
	//printf("\n");
	println("");
}

void printls(int n){//print LineS
	int i;
	for(i=0; i<n; i++)
		printnl();
}

void printint(int n){
	printf("%d\n",n);
}

void limpa(){
	system ("clear");
	system ("clear");
}
