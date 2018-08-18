#include <stdio.h>
#include <stdlib.h>

/*
	Ponteiro para estruturas: do mesmo modo que � poss�vel declarar
	vari�veis de estruturas, tamb�m pode declarar ponteiros de estruturas:
	Ponto *ponto;
	Para acessar um campo: (*ponto).x = 12;
	Esta opera��o pode ser reescrita como:
	ponto->x = 12;
*/

typedef struct ponto {
	int x;
	int y;
} Ponto;

int main() {
	Ponto *pt = (Ponto*) malloc(sizeof(Ponto));
	(*pt).x = 4; // pt->x = 4;
	(*pt).y = 3;
	printf("%d %d", (*pt).x, (*pt).y);
}
