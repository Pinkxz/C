#include <stdio.h>
#include <stdlib.h>
/*O custo ao consumidor de um carro novo é a soma do custo de fábrica com a porcentagem
do distribuidor e dos impostos (aplicados ao custo de fábrica). Supondo que a porcentagem
do distribuidor seja de 28% e os impostos de 45% sobre o custo da fábrica, escreva um
algoritmo que leia o custo de fábrica de um carro e escreva o custo ao consumidor.*/

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
