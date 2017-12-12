#include "1.mecanica.h"

#include "2.partida.h"
#include "3.partida.h"
#include "../3.visualizacao.h"

#include "../menu/2.menu.h"
#include "../fim/2.fim.h"
#include "3.debug.h"

/*
Este arquivo contém a parte de Controle do programa mais relacionada à lógica do jogo.
*/

voidvoid partidaLoop;
int x, y;
byte proximoTiro;

byte vidas;

void aloca(void){
	if(!insere(x,y,tiro.cor)){
		on.run = derrota;
		return;
	}
	
	if(contar(x,y)){
		estourando = true;
		explodir(x,y);
		score-=30;
		estourando = false;
		
		on.run = vitoria;
		for(int i=0; i<colunas; i++)
			if(existe(i,0)){
				on.run = partidaLoop;
				break;
			}
		if(on.run == vitoria){
			score *= 2;
		}
	}
	else{
		vidas--;
		if(vidas<1){
			// PARA A EXIBIÇÃO TEMPORARIAMENTE
			on.screenRefresh = NULL;
			while(desenhandoPartida);

			//FAZ O QUE TIVER QUE FAZER
			for(int i=0; i<colunas; i++)
				if(existe(i,linhastotal-1)){
					on.run = derrota;
					return;
				}
			descer();

			//VOLTA A EXIBIR
			on.screenRefresh = partidaView;

			vidas=5;
		}
	}

	logger("Vidas: %d",vidas);

	sprintf(scoreString, "%010d", score);
	iniciarTiro();
	on.click = partidaOnClick;
}

void partida(void){
	on.screenRefresh = partidaView;
	on.click = partidaOnClick;
	on.mouseMove = partidaOnMouseMove;

	botaoExit = partidaExit0;
	botaoMenu = partidaMenu0;
	
	iniciarJogo();

	//TODO debug
	exibeMatriz(
		lambda(
			char*, (Bola b) {
				char* saida;
				saida = malloc(sizeof(char)*10);

				/* COORDENADAS NA TELA */
				//sprintf(saida,"%d,%d",b.x,b.y);

				/* COORDENADAS NA MATRIZ (getLinha/getColuna) */
				if(existe(getLinha(b.y),getColuna(b.x,b.y)))
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
	x = getColuna(tiro.x,tiro.y);
	y = getLinha(tiro.y);
	logger("");
	logger("%d,%d",x,y);
	logger("");

	int a=2;
	int b=2;
	logger("Vizinhos de %d,%d",a,b);
	Bola** vizinhos = getVizinhos(a,b);
	for(int i=0; i<6; i+=2){/* TODO
		if(vizinhos[i])
			printf("%d",vizinhos[i]->cor);
		else
			printf("X");

		printf(" ");

		if(vizinhos[i+1])
			printf("%d",vizinhos[i+1]->cor);
		else
			printf("X");

		printnl();*/
	}
	liberaVizinhos(&vizinhos);

	//While application is running
	on.run = partidaLoop;
}

Coordenadas destino = {-1,-1};
void partidaLoop(void){
	moveNPC();
	//TODO debug
	if(x != getColuna(tiro.x,tiro.y) || y != getLinha(tiro.y)){
		x = getColuna(tiro.x,tiro.y);
		y = getLinha(tiro.y);
	}

	if(habitavel(x,y)){
		if(colisao(&matriz[y][x-1],&tiro) ||
			colisao(&matriz[y][x+1],&tiro) ||
			colisao(&matriz[y-1][x],&tiro) ||
			colisao(&matriz[y+1][x],&tiro)){
				aloca();
		}
		if(y%2){
			if(colisao(&matriz[y-1][x+1],&tiro) ||
				colisao(&matriz[y+1][x+1],&tiro)){
					aloca();
			}
		}
		else{
			if(colisao(&matriz[y-1][x-1],&tiro) ||
				colisao(&matriz[y+1][x-1],&tiro)){
					aloca();
			}
		}
	}
	else if(!((int)tiro.y%tam.bola.y) || !((int)tiro.x%tam.bola.x)) logger("%d %d",x,y);
	
	if(on.run == menu) return;
	else SDL_Delay(5);//Not so good solution, depends on your computer
}

//iniciar globais; preparar jogo
bool iniciarJogo(void){
	estourando = false;
	score = 0;
	sprintf(scoreString, "%010d", score);

	vidas = vidastotal;

	preencher();

	//Create NPC
	proximoTiro = sortear();
	iniciarTiro();
}

/* Create NPC */
void iniciarTiro(void){
	tiro.x = (tam.tela.x - tam.bola.x)/2;
	tiro.y = tam.tela.y - tam.bola.y;
	tiro.vel.x = 0;
	tiro.vel.y = 0;
	tiro.cor = proximoTiro;
	proximoTiro = sortear();
}

void moveNPC() {
	
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
		aloca();
	}
}

void partidaOnClick(){
	Coordenadas pos = getMousePos();
	
	if(pos.x>=594 && pos.x<=648 && pos.y>=426 && pos.y<=480){
		on.stop();
		return;
	}
	else if(pos.x>=535 && pos.x<=589 && pos.y>=426 && pos.y<=450){
		on.run = menu;
		return;
	}
	else if(pos.x>=0 && pos.x<=54 && pos.y>=426 && pos.y<=480){
		if(musicaOn){
			Mix_VolumeMusic(0);
			musicaOn = false;
		}
		else if(!musicaOn){
			Mix_VolumeMusic(100);
			musicaOn = true;
		}
		return;
	}
	else if(pos.y>419)return;

	pos.x -= (tam.tela.x)/2;
	pos.y -= (tam.tela.y)-((tam.bola.y)/2);

	double d = sqrt( pow(pos.x,2) + pow(pos.y,2) );

	tiro.vel.x = pos.x/d * tiroVelocidade;
	tiro.vel.y = pos.y/d * tiroVelocidade;

	on.click = NULL;//TODO experimenta tirar essa linha
}

void partidaOnMouseMove(Coordenadas pos){
	//135,85 257,200
	//54,54 594,426

	if(pos.x>=594 && pos.x<=648 && pos.y>=426 && pos.y<=480){
		botaoExit = partidaExit1;
	}
	else if(pos.x>=535 && pos.x<=589 && pos.y>=426 && pos.y<=450){
		botaoMenu = partidaMenu1;
	}
	else{
		botaoExit = partidaExit0;
		botaoMenu = partidaMenu0;
	}
	return;
}
