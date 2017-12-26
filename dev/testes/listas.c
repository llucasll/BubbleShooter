#include <stdio.h>
#include <stdlib.h>

struct no{
	unsigned int telefone;
	struct no *prox;
};

unsigned int obter(void){
	unsigned int tel;
	printf("Digite um número de telefone: ");
	scanf("%u",&tel);
	return tel;
}

int main(void){
	struct no *pri = NULL, *atual;
	unsigned int tel;
	
	printf("\n");
	
	tel = obter();
	if(tel){
		pri = malloc(sizeof(struct no));
		pri->telefone = tel;
		pri->prox = NULL;
		atual = pri;
		tel = obter();
	}
	
	while(tel){
		atual->prox = malloc(sizeof(struct no));
		atual->prox->telefone = tel;
		
		atual = atual->prox;
		tel = obter();
	}
	if(pri) atual->prox = NULL;
	
	printf("\n* Agora, a lista fornecida:\n");
	
	atual = pri;
	while(atual){
		static int i = 1;
		printf("Telefone número %d é: %u\n",i,atual->telefone);
		i++;
		atual = atual->prox;
	}
	
	printf("* Fim da lista\n");
	
	atual = pri;
	while(atual){
		pri = pri->prox;
		free(atual);
		atual = pri;
	}
}
