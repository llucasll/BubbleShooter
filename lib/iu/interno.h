/* PARA USO INTERNO DA BIBLIOTECA */
static voidvoid thread_principal;
static voidvoid thread_eventos;
static voidvoid thread_visualizacao;
static void _newJanela(int x, int y, char nome[]);

/* COMUNICAÇÃO ENTRE AS THREADS */
struct __novaJanela{
	Janela janela;
	int x;
	int y;
	char* nome;
	Thread thread;//TODO
};
