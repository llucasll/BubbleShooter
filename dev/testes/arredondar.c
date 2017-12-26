#include "../../lib/terminal.h"

#define sinal(x) (x<0 ? -1 : 1)

//int arredonda(int dividendo, int divisor){
float arredonda(int dividendo, int divisor){
	int inteiro = dividendo/divisor;
	
	float decimal = (float)dividendo/(float)divisor-inteiro;
	
	//return decimal;
	
	/*
	if(decimal>0.5)
		return sinal(decimal);
	else
		return 0;
	*/
	
	int a = inteiro;
	int b = sinal(decimal);
	
	println("DEBUG: %d + %d = %d", a, b, inteiro + sinal(decimal));
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
		println("%d/%d = %f\n",a,b,arredonda(a,b));
	}
	
	/*
	int x;
	while(true){
		scanf("%d",&x);
		println("%d\n",sinal(x));
	}
	*/
}
