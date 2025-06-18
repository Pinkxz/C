#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0, soma = 0;
    printf("Digite o numero A: ");
    scanf("%d",&a);

    printf("Digite o numero B: ");
    scanf("%d",&b);

    printf("Digite o numero C: ");
    scanf("%d",&c);

    printf("Digite o numero D: ");
    scanf("%d",&d);

    printf("Digite o numero E: ");
    scanf("%d",&e);

    soma = a%2*a + b%2*b + c%2*c + d%2*d + e%2*e;

    printf("A soma dos numeros impares e: %d", soma);
    return 0;
}
