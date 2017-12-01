/*

#define lambda(return_type, body_and_args) \
    ({                                     \
        return_type __fn__ body_and_args   \
            &__fn__;                       \
    })

struct tipo{
	struct{
		int (*moveu)(int);
		int (*clicou)(int);
	}mouse;
}iuf;// Funções para Interface do Usuário

iuf.mouse.clicou =
({
	int __fn__ (int n) {
		return n*n;
	}
	&__fn__;
});

iuf.mouse.moveu = lambda(
	int, (int n) {
		if(n==3)
			return 1;
		//else
	}
);

/*
lambda(
	retorno, (parametros) {
		//corpo
	}
);
*/
