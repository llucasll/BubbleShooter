#include "../0.cabecalho.h"
#include "1.dados.h"

extern Surface botaoMenu;
extern Surface botaoExit;
extern bool desenhandoPartida;

/* ETAPA DE INICIALIZAÇÃO DO **CONTROLE** */
bool carregarMidia(void);
bool iniciarSDL(void);
voidvoid iniciarInterface;

/* ETAPA DE MECÂNICA */
voidvoid moverSeta;
voidvoid partidaView;
void printScore( int tamFonte, int r, int g, int b,int posiX,int PosiY);
void explodir(int x, int y);

/* ETAPA DE FINALIZAÇÃO */
