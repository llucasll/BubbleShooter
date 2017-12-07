#include "1.dados.h"
#include "1.mecanica.h"

bool habitavel(int x, int y){
	if(existe(x+1,y)||existe(x-1,y))
		return true;
	if(existe(x,y+1)||existe(x,y-1))
		return true;
	if(x%2)
		if(existe(x+1,y+1)||existe(x,y-1))
			return true;
	else
		if(existe(x-1,y+1)||existe(x,y-1))
			return true;
	
	return false;
}

/*

float distancia(Bola* b, Tiro t){
	//println("%d",b);
	//oi();
	//pow(((int)b->x)-(t.x),2);
	return sqrt(pow(b->x-t.x,2)+pow(b->y-t.y,2));
}

bool colidiu(int x, int y){
	//oi();
	if(existe(x,y))
		if(distancia(obter(x,y),tiro)<tam.bola.x)
			return true;
			
	else return false;
}
*/
