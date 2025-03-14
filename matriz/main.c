#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 100
#define MAX_MAT_SIZE 10

void inverterPalavras(char *str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

int main() {
    char matriz[MAX_MAT_SIZE][MAX_STR_LENGTH];
    int linhas = 0;
    char palavra[MAX_STR_LENGTH];

    printf("Digite as strings para preencher a matriz (digite 'fim' para encerrar):\n");

    while (1) {
        printf("Linha %d: ", linhas + 1);
        scanf("%s", palavra);

        if (strcmp(palavra, "fim") == 0) {
            break;
        }

        if (linhas == MAX_MAT_SIZE) {
            printf("A matriz está cheia. Encerrando a inserção de strings.\n");
            break;
        }

        strncpy(matriz[linhas], palavra, MAX_STR_LENGTH);
        linhas++;
    }

    printf("\nMatriz preenchida:\n");
    for (int i = 0; i < linhas; i++) {
        inverterPalavras(matriz[i]);
        printf("%s\n", matriz[i]);
    }

    return 0;
}
