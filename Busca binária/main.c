#include <stdio.h>
#include <stdlib.h>


int main()
{
    int contadorTent = 0;
    int numero = 0;
    int tentativa = 0;
    char resposta;
    int limite_inferior = 0;
    int limite_superior = 10000;

    printf("Digite um numero entre 0 e 10000: ");
    scanf("%d", &numero);

    while (limite_inferior <= limite_superior) {
        tentativa = (limite_inferior + limite_superior) / 2;
        contadorTent++;

        printf("\nO numero que voce esta pensando e %d? (S para Sim, M para Maior, N para Menor): ", tentativa);
        scanf(" %c", &resposta);

        if (resposta == 'S' || resposta == 's') {
            printf("Numero adivinhado em %d tentativas!\n", contadorTent);
            break;
        } else if (resposta == 'M' || resposta == 'm') {
            limite_inferior = tentativa + 1;
        } else if (resposta == 'N' || resposta == 'n'){
            limite_superior = tentativa - 1;
        }
    }
    return 0;
}
