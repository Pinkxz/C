#include <stdio.h>
#include <stdlib.h>
int main()
{
 int num = 0, centena = 0, dezena = 0, unidade = 0;

 printf("Informe um numero inteiro de ate 3 digitos: ");
 scanf("%i", &num);

 centena = (num/100);
 dezena = (num/10)-centena*10;
 unidade = num%10;

 printf("\nCentena: %i", centena);
 printf("\nDezena: %i", dezena);
 printf("\nUnidade: %i", unidade);
 return 0;
}
