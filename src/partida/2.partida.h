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
	struct botoes{
		Botao exit;
		Botao menu;
	}
};
