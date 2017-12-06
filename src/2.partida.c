#include "1.dados.h"
#include "1.mecanica.h"

#include "2.partida.h"
#include "3.partida.h"

#include "3.debug.h"

/*
Este arquivo contém a parte de Controle do programa mais relacionada à lógica do jogo.
*/

/*

void jogo(void){
	bool acabou = false;
	while(!acabou){
		while(!iuf.mouse.clicou()){
			while(!iuf.mouse.moveu());
			moverSeta();
		}
		Coordenadas pos = atirar();//"atirar()" retorna as Coordenadas da Bola que foi lançada
		if(match(pos)){//verifica, recursivamente, se há mais de 2 bolas da mesma cor que "pos"
			verifica(pos);//marca, recursivamente, como "morreu" todas as bolas
			explodir(pos);//explode todas as bolas marcadas, e filhas órfãs
		}
	}
}

Coordenadas atirar(){
	bool desalojada=true;
	Coordenadas dest;//destino

	while(desalojada){
		move();
		dest.x = getColuna(tiro, dest.y = getLinha(tiro));

		if(habitavel(dest)){//verifica se, para essa casa, há um pai (acima) na estrutura)
			while(tiro.y > npc.y){
				move(); pausa();
			}
			insere(tiro, dest);
			desalojada = false;
		}
		else pausa();
	}
	return dest;
}

bool habitavel(Coordenadas pos){
	if(l) //verifica se há pais disponíveis
	else //guardar na primeira linha msm
}

bool match(Coordenadas bola){
}

void move(void){
}

*/

void partida(void){

	on.screenRefresh = partidaView;
	on.click = partidaOnClick;

	//println("%d",sortear());

	iniciarJogo();
	
	exibeMatriz();

	//While application is running
	while( !quit ) {
		moveNPC();

		//Not so good solution, depends on your computer
		SDL_Delay(5);
	}
}

void partidaOnClick(){
	bool pri = true; /* SÓ O PRIMEIRO CLIQUE TEM VALIDADE */
	if(pri){
		//println("Clicou!");
		int x, y;
		SDL_GetMouseState(&x,&y);
		//printf("\n%d,%d\n",x,y);

		x -= (tam.tela.x)/2;
		y -= (tam.tela.y)-((tam.bola.y)/2);

		double d = sqrt( pow(x,2) + pow(y,2) );

		tiro.vel.x = x/d;
		tiro.vel.y = y/d;

		pri = false;
	}
}

void moveNPC() {

	//printf("%d, %d\n",tiro.vel.x,tiro.vel.y);

	tiro.x += tiro.vel.x;
	tiro.y += tiro.vel.y;

	if ( (tiro.x + tam.bola.x > tam.tela.x) ||
		 (tiro.x < 0) ) {
		tiro.vel.x = -tiro.vel.x;
		tiro.x += tiro.vel.x;
	}
	if (tiro.y + tam.bola.y > tam.tela.y) {
		tiro.vel.y = -tiro.vel.y;
		tiro.y += tiro.vel.y;
	}

	if (tiro.y < 0) {
		/*tiro.vel.x = 0;
		tiro.vel.y = 0;*/
		//main(0, NULL);
		quit = true;
	}
}

/* Create NPC */
void createNPC( int x, int y, int velx, int vely, byte cor) {
	tiro.x = x;
	tiro.y = y;
	tiro.vel.x = velx;
	tiro.vel.y = vely;
	tiro.cor = cor;
}

bool iniciarJogo(void){//iniciar globais; preparar jogo
	for(int y=0;y<linhas;y++){
		for(int x=0;x<colunas;x++){
			matriz[y][x].cor = sortear();
			matriz[y][x].existe = true;
			matriz[y][x].morreu = false;
			
			//printint(tam.bola.x * x + (y%2?tam.bola.x/2:0));
			
			matriz[y][x].x = tam.bola.x * x + (y%2?tam.bola.x/2:0);
			matriz[y][x].y = tam.bola.y * y/*- 4*y */  /* * 0.9*/;//TODO
			
			//printf("%d,%d\t",getColuna(matriz[y][x],getLinha(matriz[y][x])),getLinha(matriz[y][x]));
			
			//println("%d\t%d\n%d\t%d\n", matriz[y][x].x, getLinha(matriz[y][x]), matriz[y][x].y, getColuna(matriz[y][x],getLinha(matriz[y][x])));
			///println("%d\t%d\n%d\t%d\n", x, getLinha(matriz[y][x]), y, getColuna(matriz[y][x],getLinha(matriz[y][x])));
			//getColuna(matriz[y][x],getLinha(matriz[y][x]));
			
			//println("%d dividido por %d = %d",x,y,arredonda(x,y));
			
			///printnl();
			//println("%d",matriz[y][x].x/tam.bola.x);
		}
		//printnl();
	}

	//Create NPC
	createNPC(
		(tam.tela.x - tam.bola.x)/2,
		(tam.tela.y - tam.bola.y),
		0,
		0,
		sortear()
	);
}
