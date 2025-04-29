#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cig, ano;
    printf("Quantos cigarros por dia voce fuma?\n");
    scanf("%d", &cig);
    printf("Quantos dias fumando?");
     scanf("%d", &ano);

     cig = cig * 365;
     cig = cig * ano;
     cig = cig * 10;
     ano = cig / 1440;

     printf("Dias de vida perdidos %d", ano);
    return 0;
}
