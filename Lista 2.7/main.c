#include<stdio.h>
#include<stdlib.h>
int main()
{
 int Car = 0, and=0;
 float feli =0, conta=0;

 printf("O valor da conta: ");
 scanf("%f", &conta);

 Car = conta/3;
 and = conta/3;
 feli = conta - (and*2);

 printf("Carlos pagara %d, Andre pagara %d e Felipe pagara %f", Car, and, feli);
 return 0;
}
