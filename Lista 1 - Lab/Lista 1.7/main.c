#include <stdio.h>
#include <stdlib.h>
/*O custo ao consumidor de um carro novo � a soma do custo de f�brica com a porcentagem
do distribuidor e dos impostos (aplicados ao custo de f�brica). Supondo que a porcentagem
do distribuidor seja de 28% e os impostos de 45% sobre o custo da f�brica, escreva um
algoritmo que leia o custo de f�brica de um carro e escreva o custo ao consumidor.*/

int main()
{
    float carro;
    printf("Qual o custo de fabricacao do carro? ");
    scanf("%f", &carro);

    carro = carro + carro * 0.45;
    carro = carro + carro * 0.28;

    printf("O custo ao consumidor sera de: %f", carro);
    return 0;
}
