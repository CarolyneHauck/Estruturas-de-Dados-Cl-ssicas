// Exemplo 2.2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct lista {
	int info;
	struct lista* prox;
} Lista;

Lista* lst_cria(void);
Lista* lst_insere(Lista*, int);
int lst_vazia(Lista* lst);
void lst_exibe(Lista*);
Lista* lst_busca(Lista*, int);

int main(void) {
	Lista* lst; /* Declara uma lista */
	lst = lst_cria();
	lst = lst_insere(lst,23);
	lst = lst_insere(lst,45);
	lst = lst_insere(lst,56);
	
	if (!lst_vazia(lst)) {
		lst_exibe(lst);
		Lista* p = lst_busca(lst,12);
		
		if (p==NULL)
			printf("12 nao esta contido na lista\n");
		else
			printf("12 esta contido na lista\n");
		
		p = lst_busca(lst,45);
	
		if (p==NULL)
			printf("45 nao esta contido na lista\n");
		else
			printf("45 esta contido na lista\n");
	}
	else
		printf("Lista vazia");
		
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

/* Fun��o vazia: retorna 1 se vazia e 0 se n�o vazia */
int lst_vazia(Lista* lst) {
	if (lst==NULL)
		return 1;
	else
		return 0;
}

/* Fun��o de exibi��o da lista */
void lst_exibe(Lista* lst) {
	Lista* aux;  // vari�vel auxiliar
	for(aux=lst;aux!=NULL;aux=aux->prox)
		printf("Info: %2d\n",aux->info);
}

/* Fun��o busca: verifica se um elemento est� contido na lista */
Lista* lst_busca(Lista* lst, int v) {
	Lista* p; /* Vari�vel auxiliar */
	for(p=lst; p!=NULL; p=p->prox)
		if(p->info==v)
			return p;
	return NULL; /* n�o achou o elemento */
}
