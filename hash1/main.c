#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_TABELA 1000 // Tamanho da tabela hash
#define MAX_NOME 100        // Tamanho máximo dos nomes

// Definindo a estrutura de nó da lista encadeada para a tabela hash
typedef struct No {
    char nome[MAX_NOME];
    int posicao;
    struct No* prox;
} No;

// Função hash fornecida para calcular o valor hash de uma string
int valorString(char *str) {
    int i, valor = 7;
    int tam = strlen(str);
    for (i = 0; i < tam; i++)
        valor = 31 * valor + (int)str[i];
    return valor;
}

// Função para criar um novo nó
No* criarNo(char* nome, int posicao) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->nome, nome);
    novoNo->posicao = posicao;
    novoNo->prox = NULL;
    return novoNo;
}

// Função para inicializar a tabela hash
void inicializarTabela(No* tabelaHash[]) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabelaHash[i] = NULL;
    }
}

// Função para inserir um nome na tabela hash
void inserirNaTabela(No* tabelaHash[], char* nome, int posicao) {
    int hashIndex = abs(valorString(nome)) % TAMANHO_TABELA;
    No* novoNo = criarNo(nome, posicao);

    // Inserção no início da lista encadeada (endereçamento fechado)
    if (tabelaHash[hashIndex] == NULL) {
        tabelaHash[hashIndex] = novoNo;
    } else {
        No* temp = tabelaHash[hashIndex];
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoNo;
    }
}

// Função para buscar um nome na tabela hash
int buscarNaTabela(No* tabelaHash[], char* nome) {
    int hashIndex = abs(valorString(nome)) % TAMANHO_TABELA;
    No* temp = tabelaHash[hashIndex];

    while (temp != NULL) {
        if (strcmp(temp->nome, nome) == 0) {
            return temp->posicao;
        }
        temp = temp->prox;
    }
    return -1; // Retorna -1 se o nome não for encontrado
}

int main() {
    // Lista de nomes
    char* nomes[] = {"Abel", "Abelardo", "Ab�lio", "Abra�o", "Abrah�o", "Abr�o", "Ada", "Adalberto",
                     "Adalgisa", "Ad�o", "Adela", "Adelaide", "Adelberto", "Ad�le", "Ad�lia", "Adelina", "Ademar", /* e assim por diante... */ };

    int numNomes = sizeof(nomes) / sizeof(nomes[0]);

    // Criar tabela hash
    No* tabelaHash[TAMANHO_TABELA];
    inicializarTabela(tabelaHash);

    // Inserir nomes na tabela hash
    for (int i = 0; i < numNomes; i++) {
        inserirNaTabela(tabelaHash, nomes[i], i);
    }

    // Buscar um nome na tabela hash
    char nomeParaBuscar[MAX_NOME];
    printf("Digite o nome que deseja buscar: ");
    scanf("%s", nomeParaBuscar);

    int posicao = buscarNaTabela(tabelaHash, nomeParaBuscar);

    if (posicao != -1) {
        printf("O nome %s está na posição %d da lista.\n", nomeParaBuscar, posicao);
    } else {
        printf("O nome %s não foi encontrado.\n", nomeParaBuscar);
    }

    return 0;
}
