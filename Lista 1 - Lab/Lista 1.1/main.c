#include <stdio.h>
#include <stdlib.h>

int main()
{
    float conta = 0, depo = 0;
    printf("Digite o valor de deposito e saque no primeiro mes: ");
    scanf("%f", &depo);
    conta = depo;
    scanf("%f", &depo);
    conta = conta - depo;

    printf("Digite o valor de deposito e saque no segundo mes: ");
    scanf("%f", &depo);
    conta = conta + depo;
    scanf("%f", &depo);
    conta = conta - depo;

    printf("Digite o valor de deposito e saque no terceiro mes: ");
    scanf("%f", &depo);
    conta = conta + depo;
    scanf("%f", &depo);
    conta = conta - depo;

    printf("Digite o valor de deposito e saque no quarto mes: ");
    scanf("%f", &depo);
    conta = conta + depo;
    scanf("%f", &depo);
    conta = conta - depo;

    printf("O saldo da conta no quarto mes e de: %f", conta);
    return 0;
}
