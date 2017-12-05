#define lambda(return_type, body_and_args) \
    ({                                     \
        return_type __fn__ body_and_args   \
            &__fn__;                       \
    })
    
// Constantes para Interface do Usuário
struct{
	struct{
		Uint8 clicado;
	}mouse;
}iuc;

// Tipos para Interface do Usuário
struct{
	struct{
		int x;
	}janela;
}iut;

// Objetos para Interface do Usuário
struct{
	
}iuo;

// Funções para Interface do Usuário
struct{
	struct{
		int (*moveu)(int);
		int (*clicou)(int);
	}mouse;
}iuf;
