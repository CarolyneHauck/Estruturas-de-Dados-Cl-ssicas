// Pilha com Lista
#include <stdio.h>
#include <stdlib.h>

// n� da lista para armazenar valores
typedef struct {
	float info;
	Lista* prox;
} Lista;

// estrutura da pilha
typedef struct {
	Lista* prim;
} Pilha;

Pilha* pilha_cria(void);
void pilha_push(Pilha*, float);
float pilha_pop(Pilha*);
int pilha_vazia(Pilha*);
void pilha_exibe(Pilha*);
void pilha_libera(Pilha*);

int main(void) {
	
	printf("Criacao de pilha com lista \n");
	Pilha* p = pilha_cria();
	
	printf("Insere e imprime elementos \n");
	pilha_push(p, 10);
	pilha_push(p, 1);
	pilha_push(p, 10);
	pilha_push(p, 10);
	pilha_push(p, 10);
}

/* Fun��o para alocar a estrutura da pilha e inicializar a lista como vazia */
Pilha* pilha_cria(void) {
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

/* Fun��o para inserir elemento no topo da pilha, no caso, no in�cio da lista */
void pilha_push(Pilha* p, float v) {
	Lista* n = (Lista*)malloc(sizeof(Lista));
	n->info = v;
	n->prox	= p->prim;
	p->prim = n;
}

/* Fun��o para retirar o elemento do topo da pilha, no caso, do in�cio da lista */
float pilha_pop(Pilha* p) {
	Lista* t;
	float v;
	
	if (pilha_vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1);
	}
	
	t = p->prim; // ponteiro para in�cio da lista
	v = t->info; // valor do primeiro elemento da lista
	p->prim = t->prox; // ponteiro para in�cio da lista
	free(t);
	
	return v;
}

/* Fun��o para verificar se a pilha est� vazia */
int pilha_vazia(Pilha* p) {
	return (p->prim==NULL);
}

/* Fun��o para exibir o conte�do da pilha */
void pilha_exibe(Pilha* p) {
	Lista* q;
	
	for (q=p->prim;q!=NULL;q=q->prox)
		printf("%f\n", q->info);
}

/* Fun��o que libera a pilha deve liberar a lista primeiro */
void pilha_libera(Pilha* p) {
	Lista* q = p->prim;
	
	while (q != NULL) {
		Lista* t = q->prox;
		free(q);
		q = t;
	}
	
	free(p);
}
