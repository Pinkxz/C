#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct no {
    int numero;
    struct no *prox;
} No;

// TAD simples
No *inserir(No *Lista);
void imprimir(No *Lista);
void busca(No *Lista);
No *remover(No *Lista);
void liberarLista(No *Lista);


No *inserir(No *Lista) {
    int numero, posicao, i = 0;
    printf("Digite o número a inserir: ");
    scanf("%d", &numero);
    printf("Digite a posição (começa em 0): ");
    scanf("%d", &posicao);

    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        return Lista;
    }

    novo->numero = numero;
    novo->prox = NULL;

    if (posicao == 0 || Lista == NULL) {
        novo->prox = Lista;
        Lista = novo;
    } else {
        No *atual = Lista;
        while (atual != NULL && i < posicao - 1) {
            atual = atual->prox;
            i++;
        }
        if (atual == NULL) {
            printf("Posição inválida. Inserção cancelada.\n");
            free(novo);
        } else {
            novo->prox = atual->prox;
            atual->prox = novo;
        }
    }
    return Lista;
}

void imprimir(No *Lista) {
    if (Lista == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Elementos da lista: ");
    No *atual = Lista;
    while (atual != NULL) {
        printf("%d ", atual->numero);
        atual = atual->prox;
    }
    printf("\n");
}

void busca(No *Lista) {
    if (Lista == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    int numero;
    printf("Digite o número para buscar: ");
    scanf("%d", &numero);

    No *atual = Lista;
    while (atual != NULL) {
        if (atual->numero == numero) {
            printf("Número %d encontrado na lista.\n", numero);
            return;
        }
        atual = atual->prox;
    }

    printf("Número %d não encontrado.\n", numero);
}

No *remover(No *Lista) {
    if (Lista == NULL) {
        printf("A lista está vazia. Nada para remover.\n");
        return Lista;
    }

    int numero;
    printf("Digite o número a remover: ");
    scanf("%d", &numero);

    No *atual = Lista;
    No *anterior = NULL;

    while (atual != NULL && atual->numero != numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Número %d não encontrado na lista.\n", numero);
        return Lista;
    }

    if (anterior == NULL) {
        Lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Número %d removido da lista.\n", numero);
    return Lista;
}

void liberarLista(No *Lista) {
    No *temp;
    while (Lista != NULL) {
        temp = Lista;
        Lista = Lista->prox;
        free(temp);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("No VScode o terminal fica bugado por algum motivo, recomendo testar em outros lugares");


    No *Lista = NULL;
    int menu = -1;

    while (menu != 0) {
        printf("\n--------------------------------------------------------------------");
        printf("\n-------------------- Lista Encadeada -------------------------------");
        printf("\n--------------------------------------------------------------------\n");
        printf("1 - Inserir\n");
        printf("2 - Imprimir todos\n");
        printf("3 - Buscar número\n");
        printf("4 - Remover número\n");
        printf("0 - Sair\n");
        printf("--------------------------------------------------------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: Lista = inserir(Lista); break;
            case 2: imprimir(Lista); break;
            case 3: busca(Lista); break;
            case 4: Lista = remover(Lista); break;
            case 0:
                liberarLista(Lista);
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

        if (menu != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar(); 
            getchar(); 
            system("cls || clear");
        }
    }

    return 0;
}
