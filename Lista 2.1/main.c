#include <stdio.h>
#include <stdlib.h>
int main()
{
 char vendedor[12], vendedor2[12];
 float salario, vendas, total, vendas2, total2;

 printf("O nome do vendedor: ");
 gets(vendedor);
 fflush(stdin);

 printf("O nome do vendedor 2: ");
 gets(vendedor2);
 fflush(stdin);

 printf("\nO salario dos vendedores: \t");
 scanf("%f", &salario);
 fflush(stdin);

 printf("\nO total de vendas do vendedor 1: \t");
 scanf("%f", &vendas);

 printf("\nO total de vendas do vendedor 2: \t");
 scanf("%f", &vendas2);

 total = salario + vendas*0.15;
 total2 = salario + vendas2*0.15;

 printf("\nO salario com a comissao do: %s e de %f", vendedor, total);
 printf("\nO salario com a comissao do: %s e de %f", vendedor2, total2);

 return 0;
}
