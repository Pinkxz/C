#include <stdio.h>
// Crie uma fun��o que recebe um ponteiro para inteiro como par�metro
// e modifica o valor apontado pelo ponteiro para o dobro.
int function(int *pointer){
    int valor = *pointer *2;
    return valor;
}



int main() {
    int numero = 10;
    int *ponteiro;

    // Inicialize o ponteiro para apontar para o endere�o da vari�vel 'numero'
    ponteiro = &numero;

    // Imprima o valor da vari�vel 'numero' usando o ponteiro
    printf("%d", *ponteiro);

    // Inicialize o ponteiro para apontar para o endere�o da vari�vel 'numero'

    // Modifique o valor de 'numero' atrav�s do ponteiro
    *ponteiro = 2;

    // Imprima o novo valor de 'numero'
    printf("\n%d", numero);

    numero = 7;
    int *ponteiro1;
    int **ponteiro2;

    // Inicialize ponteiro1 para apontar para o endere�o da vari�vel 'numero'
    ponteiro1 = &numero;

    // Inicialize ponteiro2 para apontar para o endere�o de ponteiro1
    ponteiro2 = &ponteiro1;

    // Imprima o valor de 'numero' usando ponteiro2
    printf("\n%d, %d", ponteiro, ponteiro1);
    printf("\n%d", **ponteiro2);

    numero = function(ponteiro);
    printf("\n%d", numero);

    // Utilize a fun��o malloc para alocar dinamicamente mem�ria para um array de inteiros

    // Preencha o array com valores

    // Use um ponteiro para percorrer o array e imprima seus valores

    // Libere a mem�ria alocada

    return 0;

}
