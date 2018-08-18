// Exemplo 3.1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n; /* n�umero de elementos na pilha */
	int vet[10]; /* vetor de 10 elementos */
} Pilha;

Pilha* pilha_cria(void);
void pilha_push(Pilha*, int);
int pilha_pop(Pilha*);
int pilha_vazia(Pilha*);
void pilha_exibe(Pilha*);
void pilha_libera(Pilha*);

int main(void) {
	Pilha* p = pilha_cria();
	
	if (pilha_vazia)
		printf("Pilha vazia\n\n");
		
	pilha_push(p,23);
	pilha_push(p,78);
	pilha_push(p,45);
	
	printf("Pilha com 3 elementos\n\n");
	
	pilha_exibe(p);
	pilha_pop(p);
	
	printf("\nPilha com 2 elementos\n\n");
	
	pilha_exibe(p);
	pilha_pop(p);
	pilha_pop(p);
	
	if (pilha_vazia)
		printf("\nPilha vazia\n\n");
		
	pilha_libera(p);
}

/* Fun��o para criar a pilha */
Pilha* pilha_cria(void) {
	/* retorna um ponteiro para a pilha */
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->n = 0; /* inicializa com 0 elementos */
	return p;
}

/* Fun��o para inserir um novo elemento no topo da pilha */
void pilha_push(Pilha* p, int v) {
	if (p->n == 10) /* n�o h� espa�o na pilha */
		printf("Capacidade da pilha estourou.\n\n");
	/* insere elemento na pr�oxima posi�c~ao livre */
	else {
		p->vet[p->n] = v; /* aloca elemento no vetor */
		p->n++;
	}
}

/* Fun��o para retirar o elemento do topo da pilha */
int pilha_pop(Pilha* p) {
	int v;
	
	if (pilha_vazia(p)) /* a pilha est� vazia */
		printf("Pilha vazia.\n\n");
	/* retira elemento do topo */
	else {
		v = p->vet[p->n-1]; /* o n�simo elemento na pos. n-1*/
		p->n--; /* subtrai 1 do n�mero de elementos da pilha */
	}
	return v;
}

/* Fun��o para verificar se a pilha est� vazia */
int pilha_vazia(Pilha* p) {
	return (p->n==0); /* n � igual a zero? */
}

/* Fun��o para exibir o conte�do da pilha */
void pilha_exibe(Pilha* p) {
	int i;
	
	for (i=p->n-1;i>=0;i--)
		printf("%d\n",p->vet[i]);
}

/* Fun��o para liberar a mem�ria alocada pela pilha */
void pilha_libera(Pilha* p) {
	free(p);
}
