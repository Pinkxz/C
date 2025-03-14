#include <stdio.h>

int main() {
    printf("Pense em um número entre 0 e 10.000.\n");
    printf("Pressione Enter quando estiver pronto...");

    // Aguarda o usuário pressionar Enter
    getchar();

    int limite_inferior = 0;
    int limite_superior = 10000;
    int tentativa;
    int tentativas = 0;

    while (limite_inferior <= limite_superior) {
        // Calcula a tentativa no meio do intervalo
        tentativa = (limite_inferior + limite_superior) / 2;

        // Incrementa o número de tentativas
        tentativas++;

        printf("O número que você está pensando é %d? (S para Sim, M para Maior, m para Menor): ", tentativa);

        char resposta;
        scanf(" %c", &resposta);

        if (resposta == 'S' || resposta == 's') {
            printf("Número adivinhado em %d tentativas!\n", tentativas);
            break;
        } else if (resposta == 'M' || resposta == 'm') {
            limite_inferior = tentativa + 1;
        } else {
            limite_superior = tentativa - 1;
        }
    }

    return 0;
}
