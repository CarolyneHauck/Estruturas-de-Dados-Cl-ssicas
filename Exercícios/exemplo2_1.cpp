// Exemplo 2.1
#include <stdio.h>
#include <stdlib.h>
typedef struct lista {
	int info;
	struct lista* prox;
} Lista;

Lista* lst_cria(void);
Lista* lst_insere(Lista*,int);
void lst_exibe(Lista*);

int main(void) {
	Lista* lst = lst_cria();
	lst = lst_insere(lst, 23);
	lst = lst_insere(lst, 45);
	lst_exibe(lst);
	return 0;
}

/* Fun��o de cria��o: cria uma lista vazia */
Lista* lst_cria(void) {
	return NULL;
}

/* Fun��o de inser��o no in�cio da lista */
Lista* lst_insere(Lista* lst, int i) {
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = lst;
	return novo;
}

/* Fun��o de exibi��o da lista */
void lst_exibe(Lista* lst) {
	Lista* aux;  // vari�vel auxiliar
	for(aux=lst;aux!=NULL;aux=aux->prox)
		printf("Info = %d\n",aux->info);
}
