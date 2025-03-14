#include <stdio.h>
#include <string.h>

#define MAX_NOMES 10
#define TAM_NOME 50

int pesquisarNome(char nomes[][TAM_NOME], int numNomes, char* nomeProcurado) {
    for (int i = 0; i < numNomes; i++) {
        if (strcmp(nomes[i], nomeProcurado) == 0) {
            return 1; // Achou o nome
        }
    }
    return 0; // Não achou o nome
}

int main() {
    char nomes[MAX_NOMES][TAM_NOME];
    char nomeProcurado[TAM_NOME];

    // Leitura do vetor de nomes
    printf("Digite 10 nomes:\n");
    for (int i = 0; i < MAX_NOMES; i++) {
        printf("Nome %d: ", i + 1);
        scanf("%s", &nomes[i]);
    }

    // Leitura do nome a ser procurado
    printf("\nDigite um nome para buscar: ");
    scanf("%s", &nomeProcurado);

    // Chamada da função para pesquisar o nome
    int encontrado = pesquisarNome(nomes, MAX_NOMES, nomeProcurado);

    // Exibir resultado
    if (encontrado) {
        printf("ACHEI\n");
    } else {
        printf("NÃO ACHEI\n");
    }

    return 0;
}
