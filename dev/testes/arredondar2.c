#include "../../lib/terminal.h"

#define sinal(x) (x<0 ? -1 : 1)

int arredonda(int dividendo, int divisor){
	int inteiro = dividendo/divisor;
	float decimal = (float)dividendo/(float)divisor-inteiro;
	if(decimal>0.5)
		return inteiro + sinal(decimal);
	else
		return inteiro;
}

int main(void){
	printnl();
	println("Começou");
	printnl();
	
	int a,b;
	while(true){
		scanf("%d %d",&a,&b);
		println("%d/%d = %d\n",a,b,arredonda(a,b));
	}
}
