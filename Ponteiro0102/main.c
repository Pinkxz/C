#include <stdio.h>
// Crie uma função que recebe um ponteiro para inteiro como parâmetro
// e modifica o valor apontado pelo ponteiro para o dobro.
int function(int *pointer){
    int valor = *pointer *2;
    return valor;
}



int main() {
    int numero = 10;
    int *ponteiro;

    // Inicialize o ponteiro para apontar para o endereço da variável 'numero'
    ponteiro = &numero;

    // Imprima o valor da variável 'numero' usando o ponteiro
    printf("%d", *ponteiro);

    // Inicialize o ponteiro para apontar para o endereço da variável 'numero'

    // Modifique o valor de 'numero' através do ponteiro
    *ponteiro = 2;

    // Imprima o novo valor de 'numero'
    printf("\n%d", numero);

    numero = 7;
    int *ponteiro1;
    int **ponteiro2;

    // Inicialize ponteiro1 para apontar para o endereço da variável 'numero'
    ponteiro1 = &numero;

    // Inicialize ponteiro2 para apontar para o endereço de ponteiro1
    ponteiro2 = &ponteiro1;

    // Imprima o valor de 'numero' usando ponteiro2
    printf("\n%d, %d", ponteiro, ponteiro1);
    printf("\n%d", **ponteiro2);

    numero = function(ponteiro);
    printf("\n%d", numero);

    // Utilize a função malloc para alocar dinamicamente memória para um array de inteiros

    // Preencha o array com valores

    // Use um ponteiro para percorrer o array e imprima seus valores

    // Libere a memória alocada

    return 0;

}
