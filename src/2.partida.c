#include "1.dados.h"
#include "1.mecanica.h"

#include "2.partida.h"
#include "3.partida.h"

#include "2.menu.h"
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


	exibeMatriz(
		lambda(
			char*, (Bola b) {
				char* saida;
				saida = malloc(sizeof(char)*10);

				/* COORDENADAS NA TELA */
				//sprintf(saida,"%d,%d",b.x,b.y);

				/* COORDENADAS NA MATRIZ (getLinha/getColuna) */
				sprintf(saida,"%d,%d",getColuna(b.x,b.y),getLinha(b.y));

				/* COR */
				//sprintf(saida,"%d",b.cor);

				/* EXISTE */
				//sprintf(saida,"%d",b.existe);

				return saida;
			}
		)
	);

	//TODO debug
	int x = getColuna(tiro.x,tiro.y), y = getLinha(tiro.y);
	printnl();
	println("%d,%d",x,y);
	printnl();

	//printint((int)obter(16,8));
	//printnl();


	/*
	while(true){
		println("%d,%d",x,y);
		while(x == getColuna(tiro.x,tiro.y) && y == getLinha(tiro.y));
	}
	*/

	//While application is running

	Coordenadas destino = {-1,-1};
	while( !quit ) {
		if(controle.principal == menu){
			return;
		}
		moveNPC();
		partidaGetStatus();
		//TODO debug
		if(x != getColuna(tiro.x,tiro.y) || y != getLinha(tiro.y)){
			x = getColuna(tiro.x,tiro.y);
			y = getLinha(tiro.y);

			printnl();
			println("%d,%d",x,y);

			//println("a");

			Bola* b = obter(getColuna(tiro.x,tiro.y), getLinha(tiro.y));
			//println("b");


			if(destino.x != -1){//se finalmente tem abrigo, mas já saiu dele
				insere(destino.x,destino.y,tiro.cor);

				/*
				Bola* k = obter(destino.x,destino.y);
				if(k){
					println("dentro da matriz");
					if(k->existe)
						println("existe");
				}
				println("parecer do existe(): %s",existe(x,y)?"sim":"não");
				*/

				destino.x = -1;
				destino.y = -1;
				iniciarTiro();
				on.click = partidaOnClick;

				exibeMatriz(
					lambda(
						char*, (Bola b) {
							char* saida;
							saida = malloc(sizeof(char)*10);

							/* COORDENADAS NA TELA */
							//sprintf(saida,"%d,%d",b.x,b.y);

							/* COORDENADAS NA MATRIZ (getLinha/getColuna) */
							//sprintf(saida,"%d,%d",getColuna(b.x,b.y),getLinha(b.y));

							/* COR */
							//sprintf(saida,"%d",b.cor);

							/* EXISTE */
							sprintf(saida,"%d",b.existe);

							return saida;
						}
					)
				);
			}


			else if(habitavel(x,y)){
				//println("habitável");

				if(destino.x == -1){//se a bola ainda está desabrigada, os problemas acabara!
					destino.x = x;
					destino.y = y;
				}

				/*oi();
				Bola n = *b;
				oi();
				distancia(n,tiro);
				*/

				/*
				if(colidiu(1,y) || colidiu(x-1,y) || colidiu(x,y+1) || colidiu(x,y-1)){
					insere(x,y,tiro.cor);
					//oi();
				}

				if(x%2){
					if(colidiu(x+1,y+1) || colidiu(x,y-1)){
						insere(x,y,tiro.cor);
						//oi();
					}
				}
				else
					if(colidiu(x-1,y+1) || colidiu(x,y-1)){
						insere(x,y,tiro.cor);
						//oi();
					}

				*/

				/*||existe(x-1,y))
					return true;
				if(existe(x,y+1)||existe(x,y-1))
					return true;
				if(x%2){
					if(existe(x+1,y+1)||existe(x,y-1))
						return true;
				}
				else{
					if(existe(x-1,y+1)||existe(x,y-1))
						return true;
				}*/

				//sleep(3);
			}
			else
				println("não-habitável");

			/*
			if(existe(b)){

				//println("c");
				//println("Cor: %d",b->cor);

				char cor[10];

				switch (b->cor){
					case 0:
						sprintf(cor,"%s","blue");
						break;
					case 1:
						sprintf(cor,"%s","red");
						break;
					case 2:
						sprintf(cor,"%s","cian");
						break;
					case 3:
						sprintf(cor,"%s","green");
						break;
					case 4:
						sprintf(cor,"%s","pink");
						break;
					case 5:
						sprintf(cor,"%s","yellow");
						break;
				}

				println("Cor: %s",cor);

				//sleep(3);
				char c;
				scanf("%c",&c);
				//println("d");
			}
			*/
		}

		//Not so good solution, depends on your computer
		SDL_Delay(5);
	}
}

void partidaOnClick(){
	//println("Clicou!");
	int x, y;
	SDL_GetMouseState(&x,&y);
	//printf("\n%d,%d\n",x,y);
	if(x>=594 && x<=648 && y>=426 && y<=480){
		quit=true;
	}
	else if(x>=535 && x<=589 && y>=426 && y<=450){
		controle.principal = menu;
		return;
	}
	if(y>419)y=419;
	x -= (tam.tela.x)/2;
	y -= (tam.tela.y)-((tam.bola.y)/2);

	double d = sqrt( pow(x,2) + pow(y,2) );

	tiro.vel.x = x/d;
	tiro.vel.y = y/d;

	on.click = NULL;//TODO experimenta tirar essa linha
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
void iniciarTiro(void){
	tiro.x = (tam.tela.x - tam.bola.x)/2;
	tiro.y = tam.tela.y - tam.bola.y;
	tiro.vel.x = 0;
	tiro.vel.y = 0;
	tiro.cor = sortear();
}

void partidaGetStatus(void){
	int x, y;
	SDL_GetMouseState(&x,&y);

	//135,85 257,200
	//54,54 594,426

	if(x>=594 && x<=648 && y>=426 && y<=480){
		partidaExitStatus=1;
	}
	else if(x>=535 && x<=589 && y>=426 && y<=450){
		partidaMenuStatus=1;
	}
	else{
		partidaMenuStatus=0;
		partidaExitStatus=0;
	}
	return;
}

bool iniciarJogo(void){//iniciar globais; preparar jogo
	preencher();

	//Create NPC
	iniciarTiro();
}
