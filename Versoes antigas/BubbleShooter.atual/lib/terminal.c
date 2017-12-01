//#include "../lib-headers/lib.h"
//#include "../lib-headers/terminal.h"
#include "terminal.h"

#include <stdio.h>
#include <stdlib.h>

void println(const char *format, ...){
	va_list arg;
	//int done;

	va_start (arg, format);
	//done = printf (format, arg);
	vfprintf (stdout, format, arg);
	va_end (arg);

	//return done;

/*(char s[]){
	printf("%s%c",s,'\n');
	//printf(s); printnl();*/
	
	printf("\n");
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
