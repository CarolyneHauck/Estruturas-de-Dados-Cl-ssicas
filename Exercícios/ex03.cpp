#include <stdio.h>
int main() {
	int a = 2, b = 3, c;
	int *p, *q; // declara 2 ponteiros
	p = &a; // p aponta para o endere�o de a
	q = &b; // q aponta para o endere�o de b
	c = *p + *q; //c = a + b
	printf("%d",c);
}
