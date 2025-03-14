#include <stdio.h>

#define TAMANHO_VETOR 50

void ordenarVetor(int vetor[], int tamanho) {
    int i, j, temp;

    for (i = 0; i < tamanho-1; i++) {
        for (j = 0; j < tamanho-i-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

int main() {
    int valores[TAMANHO_VETOR];
    int i;

    // Receber os valores do usuário
    printf("Digite os 50 valores positivos:\n");
    for (i = 0; i < TAMANHO_VETOR; i++) {
        scanf("%d", &valores[i]);

        // Verificar se o valor é positivo
        while (valores[i] < 0) {
            printf("Valor inválido! Digite novamente: ");
            scanf("%d", &valores[i]);
        }
    }

    // Ordenar o vetor em ordem crescente
    ordenarVetor(valores, TAMANHO_VETOR);

    // Imprimir o vetor ordenado
    printf("Valores ordenados em ordem crescente:\n");
    for (i = 0; i < TAMANHO_VETOR; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");

    return 0;
}
