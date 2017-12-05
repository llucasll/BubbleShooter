#include "1.dados.h"

/* ETAPA DE INICIALIZAÇÃO DO **CONTROLE** */
bool carregarMidia(void);
bool iniciarSDL(void);
void iniciarInterface(void);

/* ETAPA DE MECÂNICA */
void moverSeta();
//void atualizar();

/* ETAPA DE FINALIZAÇÃO */


void atualiza();

void (*atualizarTela)(void);

void *atualizador(void);
