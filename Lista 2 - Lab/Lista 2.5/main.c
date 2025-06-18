#include<stdio.h>
#include<stdlib.h>
int main()
{
 int peq, med, gra, total = 0;

 printf("Quantidade de camisetas pequenas compradas: ");
 scanf("%d", &peq);

 printf("Quantidade de medias: ");
 scanf("%d", &med);

 printf("Grandes: ");
 scanf("%d", &gra);

 total = peq*10+med*12+gra*15;

 printf("O valor total devido e %d", total);
 return 0;
}
