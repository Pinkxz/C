#include <stdio.h>
#include <stdlib.h>

int somador(int *x,int *y){
    int soma;
    soma = *x + *y;
    return soma;
}
int main()
{
    int x, y;
    int *m, *q;

    m = &x;
    q = &y;
    printf("Hello world!\n");
    scanf("%d %d", &x, &y);

    int soma =  somador(m, q);

    printf("%d", soma);
    return 0;
}
