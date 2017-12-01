#include "2.jogo.h"

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
/*
void atualiza(){
	SDL_Rect srcRect, dstRect;
	//Fill the surface white
	SDL_FillRect( gScreenSurface, NULL, 
						  SDL_MapRGB( gScreenSurface->format, 
						  0xFF, 0xFF, 0xFF ) );

	moveNPC();

	srcRect.x = 0; srcRect.y = 0;
	srcRect.w = npc.x;
	srcRect.h = npc.y;
	dstRect.x = tiro.x;
	dstRect.y = tiro.y;
	
	if( SDL_BlitSurface( gJPGSurface, &srcRect, 
								 gScreenSurface, &dstRect ) < 0 ) {
		printf( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
		quit = true;
	}

	//printf("%f, %f\n",tiro.x,tiro.y);
	
	//Update the surface
	SDL_UpdateWindowSurface( gWindow );
}
*/

void execucao(void){
	SDL_Event e; // Event handler

	bool pri = true; /* SÓ O PRIMEIRO CLIQUE TEM VALIDADE */
	quit = false;
	
	//Create NPC
	createNPC(
		(tela.x - npc.x)/2, 
		(tela.y - npc.y), 
		0, 
		0
	);
	
	/* SE, QUANDO O SO MANDA O PROGRAMA FECHAR (usando "terminar" ao invés de "matar") REINICIA ELE RECOMEÇA A FUNÇÃO EM EXECUÇÃO NO MOMENTO.
	static int k=0;
	printf("i'm here %%%d\n",k);
	k++;
	
	void aninhada(void){
		
		
		static int k=0;
		printf("so na funcao %%%d\n",k);
		k++;
		*/
		
	
	//While application is running
	while( !quit ) {
		while( SDL_PollEvent( &e ) != 0 ) {
			switch (e.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN:
					if(e.button.button == SDL_BUTTON_LEFT){
						if(pri){
							//println("Clicou!");
							int x = e.motion.x, y = e.motion.y;
							//printf("\n%d,%d\n",x,y);
							x -= (tela.x)/2;
							y -= (tela.y)-((npc.y)/2);
						
							//printf("\n%d%d\n",x,y);
						
							//printf("\n%d,%d,%d\n",tela.x,tela.y,npc.y);
							//printf("\n%d,%d\n",x,y);
						
							double d = sqrt( pow(x,2) + pow(y,2) );
						
							tiro.vel.x = x/d;
							tiro.vel.y = y/d;
							//printf("%f,%f\n",tiro.vel.x,tiro.vel.y);
							pri = false;
						}
						//printf("\n%d, %d\n\n",e.motion.x,e.motion.y);
						//printf("oi\n");
						//printf("\nvel.x: %lf\nvel.y: %lf\nx: %lf\ny: %lf\n",tiro.vel.x,tiro.vel.y,tiro.x,tiro.y);
					}
					break;
				case SDL_KEYDOWN:
					if (e.key.keysym.sym == SDLK_ESCAPE) {
						quit = true;
					}
					break;
			}
		}
		
		
		moveNPC();
		//atualiza();
			
		//Not so good solution, depends on your computer
		SDL_Delay(5);
	}
}
//aninhada();
//}

void moveNPC() {
	
	//printf("%d, %d\n",tiro.vel.x,tiro.vel.y);

	tiro.x += tiro.vel.x;
	tiro.y += tiro.vel.y;
	
	if ( (tiro.x + npc.x > tela.x) ||
		 (tiro.x < 0) ) {
		tiro.vel.x = -tiro.vel.x;
		tiro.x += tiro.vel.x; 
	}
	if (tiro.y + npc.y > tela.y) {
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
void createNPC( int x, int y, int velx, int vely) {
	tiro.x = x;
	tiro.y = y;
	tiro.vel.x = velx;
	tiro.vel.y = vely;	
}
