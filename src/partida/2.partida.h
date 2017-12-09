#include "../0.cabecalho.h"

voidvoid partida;
voidvoid moveNPC;
voidvoid iniciarTiro;
bool iniciarJogo(void);//iniciar globais; preparar jogo

voidvoid partidaOnClick;
void partidaOnMouseMove(Coordenadas pos);

typedef struct{
	Coordenadas pos, tam;
	Surface onOver, onOut, view;
	voidvoid *onClick;
}Botao;

struct _partida{
	struct{
		Botao exit;
		Botao menu;
	}botoes;
}extern s_partida;//struct partida

enum booleano {sim, nao};//TODO
