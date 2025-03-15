#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct produto {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
    struct produto *proximo;
} Produto;

Produto *inserir(Produto *);
void imprimir(Produto *);
void consultarProduto(Produto *);
void relatorio(Produto *);
Produto *removerProduto(Produto *);
Produto *consultarVolumeEstoque(Produto *);

int main() {
    setlocale(LC_ALL, "Portuguese");

    Produto *estoque = NULL;
    int menu = 20;

    system("color f0");

    while (menu != 0) {
        printf("\n--------------------------------------------------------------------");
        printf("\n--------------------Controle de estoque-----------------------------");
        printf("\n--------------------------------------------------------------------\n");
        printf("1- Cadastrar Produto\n");
        printf("2- Consultar Produto\n");
        printf("3- Relat�rio Produto\n");
        printf("4- Consultar volume em estoque\n");
        printf("5- Remover Produto\n");
        printf("0- Sair\n");
        printf("--------------------------------------------------------------------\n");
        printf("Digite a op��o desejada: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: estoque = inserir(estoque); break;
            case 2: consultarProduto(estoque); break;
            case 3: relatorio(estoque); break;
            case 4: consultarVolumeEstoque(estoque); break;
            case 5: estoque = removerProduto(estoque); break;
            case 0: printf("\nSaindo do programa.\n"); break;
            default: printf("\nOp��o inv�lida!\n");
        }
        if (menu != 0) {
            system("pause");
            system("cls");
        }
    }

    return 0;
}

Produto *inserir(Produto *destino) {
    Produto *novo = (Produto *)malloc(sizeof(Produto));

    printf("\nInsira o C�digo: ");
    scanf("%d", &novo->codigo);
    printf("\nInsira a descri��o: ");
    scanf(" %49[^\n]", novo->descricao);
    printf("\nInsira a quantidade: ");
    scanf("%d", &novo->quantidade);
    printf("\nInsira o valor: ");
    scanf("%f", &novo->valor);

    novo->proximo = destino;
    return novo;
}

void imprimir(Produto *lista) {
    Produto *auxiliar = lista;

    while (auxiliar != NULL) {
        printf("\nC�digo: %d", auxiliar->codigo);
        printf("\nDescri��o: %s", auxiliar->descricao);
        printf("\nQuantidade: %d", auxiliar->quantidade);
        printf("\nValor: %.2f\n", auxiliar->valor);
        auxiliar = auxiliar->proximo;
    }
}

void consultarProduto(Produto *estoque) {
    Produto *auxiliar = estoque;
    int codigo;

    printf("\n--------------------------------------------------------------------");
    printf("\n--------------------Consulta de estoque-----------------------------");
    printf("\n--------------------------------------------------------------------\n");
    printf("Digite o c�digo do produto: ");
    scanf("%d", &codigo);

    while (auxiliar != NULL) {
        if (auxiliar->codigo == codigo) {
            printf("\nProduto encontrado:\n");
            imprimir(auxiliar);
            return;
        }
        auxiliar = auxiliar->proximo;
    }
    printf("\nProduto n�o cadastrado.\n");
}

void relatorio(Produto *estoque) {
    Produto *auxiliar = estoque;
    int i = 1;

    printf("\n--------------------------------------------------------------------");
    printf("\n--------------------Relat�rio de estoque-----------------------------");
    printf("\n--------------------------------------------------------------------\n");

    while (auxiliar != NULL) {
        printf("\nProduto [%d]\n", i++);
        printf("C�digo: %d\n", auxiliar->codigo);
        printf("Descri��o: %s\n", auxiliar->descricao);
        printf("Quantidade: %d\n", auxiliar->quantidade);
        printf("Valor: %.2f\n", auxiliar->valor);
        auxiliar = auxiliar->proximo;
    }
}

Produto *removerProduto(Produto *estoque) {
    Produto *anterior = NULL;
    Produto *auxiliar = estoque;
    int codigo;

    printf("\n--------------------------------------------------------------------");
    printf("\n--------------------Remo��o de estoque-----------------------------");
    printf("\n--------------------------------------------------------------------\n");
    printf("Digite o c�digo do produto: ");
    scanf("%d", &codigo);

    while (auxiliar != NULL && auxiliar->codigo != codigo) {
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }

    if (auxiliar == NULL) {
        printf("\nProduto n�o cadastrado!\n");
        return estoque;
    }

    if (anterior == NULL) {
        estoque = auxiliar->proximo;
    } else {
        anterior->proximo = auxiliar->proximo;
    }

    free(auxiliar);
    printf("\nProduto removido!\n");
    return estoque;
}

Produto *consultarVolumeEstoque(Produto *estoque) {
    Produto *auxiliar = estoque;
    int volume;

    printf("\n--------------------------------------------------------------------");
    printf("\n--------------------Consulta de Volume em Estoque-------------------");
    printf("\n--------------------------------------------------------------------\n");
    printf("Digite o volume m�ximo de estoque: ");
    scanf("%d", &volume);

    while (auxiliar != NULL) {
        if (auxiliar->quantidade < volume) {
            printf("\nC�digo: %d", auxiliar->codigo);
            printf("\nDescri��o: %s", auxiliar->descricao);
            printf("\nQuantidade: %d", auxiliar->quantidade);
            printf("\nValor: %.2f\n", auxiliar->valor);
        }
        auxiliar = auxiliar->proximo;
    }
    return estoque;
}
