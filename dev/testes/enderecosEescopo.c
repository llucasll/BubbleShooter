#include "../../lib/terminal.h"

int main(void){
	
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
