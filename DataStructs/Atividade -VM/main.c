#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int valor;
    struct no *prox;
} No;

void inserirInicio(No **inicio, int valor){
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *inicio;
    *inicio = novo;
}

void inserirFim(No **inicio, int valor){
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if(*inicio == NULL){
        *inicio = novo;
    }else{
        No *atual = *inicio;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void imprimirLista(No *inicio){
    printf("Lista:\n");
    No *atual = inicio;
    while(atual != NULL){
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
}

int main(){
    No *lista = NULL;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 8);
    inserirFim(&lista, 40);
    inserirFim(&lista, 30);

    imprimirLista(lista);

    return 0;
}
