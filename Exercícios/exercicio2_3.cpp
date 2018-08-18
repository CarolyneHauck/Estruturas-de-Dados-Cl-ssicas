// Exerc�cio 2.3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct lista {
	int inf1;
	float inf2;
	char inf3;
	struct lista* prox;
} Lista;

Lista* lst_cria(void);
Lista* lst_insere(Lista*,int,float,char);
void lst_exibe(Lista*);

int main(void) {
	srand(time(0));
	int i, n, k;
	float f;
	char c;
	printf("N: ");
	scanf("%d",&n);
	Lista* lst = lst_cria();
	for(k=0;k<n;k++) {
		i = rand()%100;
		f = rand()%100/10.;
		c = rand()%26+65;
		lst = lst_insere(lst,i,f,c);
	}
	lst_exibe(lst);
}

/* Fun��o de cria��o: cria uma lista vazia */
Lista* lst_cria(void) {
	return NULL;
}

/* Fun��o de inser��o no in�cio da lista */
Lista* lst_insere(Lista* lst,int i, float f, char c) {
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->inf1 = i;
	novo->inf2 = f;
	novo->inf3 = c;
	novo->prox = lst;
	return novo;
}

/* Fun��o de exibi��o da lista */
void lst_exibe(Lista* lst) {
	Lista* aux;  // vari�vel auxiliar
	for(aux=lst;aux!=NULL;aux=aux->prox) {
		printf("%2d ",aux->inf1);		
		printf("%.1f ",aux->inf2);
		printf("%c\n",aux->inf3);
	}
}
