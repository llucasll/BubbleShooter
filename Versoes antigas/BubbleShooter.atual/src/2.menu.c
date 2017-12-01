#include "2.partida.h"
#include "3.partida.h"

void menu(void){
	
	int n;
	scanf("%d",&n);
	/* TESTANDO ESCOPO ATRAVÉS DOS ENDEREÇOS */
	void func(int a){
		//println("FUNÇÃO %d:\t%u",a,&func);
		println("PARÂMETRO %d:\t%u",a,&a);
		//printnl();
		if(a)
			func(a-1);
	}
	//println("%u",&menu); printnl();
	func(n);
	//println("%u",&func);
}
