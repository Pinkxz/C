#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numA = 0, numB = 0, numF = 0;
    printf("Digite o numero A: ");
    scanf("%d", &numA);
    printf("Digite o numero B: ");
    scanf("%d", &numB);

    numF = numA;
    numA = numB;
    numB = numF;

    printf("Os numeros trocados sao: A = %d, B = %d", numA, numB);

    return 0;
}
