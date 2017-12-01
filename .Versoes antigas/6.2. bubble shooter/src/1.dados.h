/*#ifndef CABECALHO
	#include "0.cabecalho.h"
	
#else
*/
/*

{
	#define ncores 6

	typedef struct{
		char caminho[100];
	}Cor;

	Cor cor[ncores]={
		{"azul.jpg"},
		{"vermelho.png"},
		{"verde.jpg"},
		{"amarelo.png"},
		{"cinza.jpg"},
		{".png"}
	};

	Bola *b = get(x,y);
	cor[b->cor].caminho;
}

sortear(){
	return rand(ncores);
}

insere(byte cor, byte x, byte y){
	

init(){
	//...
	Surface imagens[ncores];
	for(int i; i<ncores; i++){
		imagens[i] = SDL_get_surface(cor[i].caminho);
		imagens[i] = loadSurface(cor[i].caminho);
	}
	//...
	
	Bola *m[][] = malloc(tam.linhas);
	for(int i; i<tam.linhas; i++)
		m[i] = malloc(tam.colunas);
	//linkar ponteiros ds bolas entre si
	
	//int x=3;
	for(int x=0; x<tam.tela.x; x++)
		for(int y=0; y<tam.tela.y; y++)
			insere(sortear(),x,y);
}
	
imprime(Bola b){
	Surface img = imagens[b->cor];
	SDL_imprime(img,x,y);
}



/* VARIÁVEIS * /

Bola *primeiraLinha[] //vetor d ponteiros

struct{
	byte jogadas;
	byte recorde;
	byte pontuacao;
}jogo;

char[][] imagens = {
	"",
	"",
	"",
	""
}

struct{
	coordenadas tela;
	coordenadas bola;
}tam

/* TIPOS * /


/* FUNÇÕES * /

void insere(x,y,cor)
Bola get(x,y)
byte sortear()


*/

//init()
//imprime(b)
//insere(sortear(),x,y)


#include "0.cabecalho.h"
#ifndef DADOS //evitar inclusões cíclicas ("guarda de cabeçalho")
	#define DADOS
//#ifndef TIPOS //evitar inclusões cíclicas ("guarda de cabeçalho")
//	#define TIPOS
	
	/* TIPOS */
	typedef struct{
		int x,y;
	} Coordenadas;

	typedef struct _Bola{
		byte cor;
		struct _Bola *vizinhos[6];
		int x,y;
		bool morreu;
	} Bola;

	typedef struct{
		char cor;
		float x,y;
		struct{
			float x,y;
		}vel;
	} Tiro;

//#endif

//#ifndef DADOS //evitar inclusões cíclicas ("guarda de cabeçalho")
//	#define DADOS

	/* PROTÓTIPOS */
	
	bool iniciarJogo(void);//iniciar globais; preparar jogo

	bool insere(byte b, int x, int y);
	Bola *obter(int x, int y);
	bool remover(int x, int y);
	
	byte sortear();
	bool preencher();//retorna se houve sucesso
	void percorrer(void *func(Bola *b));
	void liberar_tudo();

	int getLinha(Bola b);
	int getColuna(Bola b, int linha);


	/* GLOBAIS */
	extern const Coordenadas campo, npc, tela;//tamanhos
	extern Coordenadas velocidade;
	extern Bola *matriz[linhas][colunas];
	extern Tiro tiro;
	
	/* Global Variables */
	extern SDL_Window* gWindow; //The window we'll be rendering to
	//SDL_Surface* imagem; //The imagem character
	extern SDL_Surface* gScreenSurface; //The surface contained by the window
	extern SDL_Surface* gJPGSurface; //Current displayed PNG image

	extern bool quit; //Main loop flag
	
#endif
//#endif
