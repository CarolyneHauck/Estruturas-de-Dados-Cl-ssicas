// Exerc�cio 3.2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int n;
	char vet[20];
} Pilha;

Pilha* pilha_cria(void);
void pilha_push(Pilha*, int);
int pilha_pop(Pilha*);
int pilha_vazia(Pilha*);
void pilha_exibe(Pilha*);
void pilha_libera(Pilha*);

int main(void) {
	
	srand(time(0));
	
	int i = 0;
	int al;
	Pilha* p = pilha_cria();
	
	while (1) {
		
		al = rand()%2;
		
		if (al) {
			
			if (p->n == 20)
				break;
				
			pilha_push(p, rand()%100);
			printf("[%3d] push: %d", i, p->n);
		}
		else {
			
			pilha_pop(p);
			printf("[%3d] pop: %d", i, p->n);
		}
		
		i++;
		printf("\n");
	}
	
	printf("Pilha Final\n");
	pilha_exibe(p);
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
	if (p->n == 20) /* n�o h� espa�o na pilha */
		printf("Capacidade da pilha estourou. ");
	/* insere elemento na pr�xima posi��o livre */
	else {
		p->vet[p->n] = v; /* aloca elemento no vetor */
		p->n++;
	}
}

/* Fun��o para retirar o elemento do topo da pilha */
int pilha_pop(Pilha* p) {
	int v;
	
	if (!pilha_vazia(p)) {
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
		printf("%d ",p->vet[i]);
}

/* Fun��o para liberar a mem�ria alocada pela pilha */
void pilha_libera(Pilha* p) {
	free(p);
}
