#include <stdio.h>
#include <stdlib.h>

/* Crie um programa em linguagem C que:
- crie uma árvore binária (utilize cabeça);
- faça inserções ordenadas;
- faça uma função que apresente a altura de uma subárvore;
- faça remoções, utilizando os três conceitos apresentados (nó folha; menor filho à direita da subárvore à direita, menor filho da subárvore à esquerda com apenas um filho. )
- faça uma função para impressão em pré-ordem, ordem e pós-ordem (não função principal o usuário escolhe qual metodologia de impressão)
*/

typedef struct Arvore{
    int valor;
     struct Arvore *esq, *dir;
}Arvore;


// Criando nó
Arvore* novoNo(int valor){
    Arvore* no = (Arvore*) malloc(sizeof(Arvore));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

// Insercao Ordenada
Arvore* insercao(Arvore* raiz, int valor){
    // Caso não existe nada
    if(raiz == NULL){
        return novoNo(valor);
    }
    // Insercoes
    if(valor < raiz->valor){
        raiz->esq = insercao(raiz->esq, valor);
    }else if(valor > raiz->valor){
        raiz->dir = insercao(raiz->dir, valor);
    }
    return raiz;
}

// Fucao para altura
int altura(Arvore* raiz){
    if(raiz == NULL){
        return -1;
    }
    int AltEsq = altura(raiz->esq);
    int AltDir = altura(raiz->dir);
    return (AltEsq > AltDir ? AltEsq : AltDir) + 1;
}

Arvore* menorNo(Arvore* raiz){
    while(raiz && raiz-> esq != NULL){
        raiz = raiz->esq;
    }
    return raiz;
}

Arvore* remover(Arvore* raiz, int valor){
    if(raiz == NULL){
        return NULL;
    }

    if(valor < raiz->valor){
        raiz->esq = remover(raiz->esq, valor);
    }else if(valor > raiz->valor){
        raiz->dir = remover(raiz->dir, valor);
    }else{
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            return NULL;
        }else if(raiz->esq == NULL || raiz->dir == NULL){
            Arvore* aux = (raiz->esq != NULL) ? raiz->esq : raiz->dir;
            free(raiz);
            return aux;
        }else{
            Arvore* menor = menorNo(raiz->dir);
            raiz->valor = menor->valor;
            raiz->dir = remover(raiz->dir, menor->valor);
        }
    }
    return raiz;
}


// Impressoes
void preOrdem(Arvore* raiz){
    if(raiz){
        printf("Pre-ordem: %d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(Arvore* raiz){
    if(raiz){
        emOrdem(raiz->esq);
        printf("Em ordem %d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void posOrdem(Arvore* raiz){
    if(raiz){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("Pos ordem %d ", raiz->valor);
    }
}

int main(){
    Arvore* raiz = NULL;
    int opcao = 20, valor = 0;


    while(opcao != 0){
        printf("\n1-Inserir 2-Remover 3-Altura 4-Imprimir 0-Sair: ");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case 1:
            printf("Insira um valor: ");
            scanf("%d", &valor);
            raiz = insercao(raiz, valor);
            break;
        case 2:
            printf("Insira o valor a se remover: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        case 3: 
            printf("Altura: %d\n", altura(raiz));
            break;
        case 4:
            printf("1 - Pre-Ordem | 2 - Em ordem | 3 - Pos-Ordem ");
            scanf("%d", &valor);
            if (valor == 1){
                preOrdem(raiz);
            }else if (valor == 2){
                emOrdem(raiz);
            }else if (valor == 3) {
                posOrdem(raiz);
            }
            printf("\n");
            break;
        default:
            break;
        }

    }
    printf("Execucao Finalizada!");
    return 0;
}

// Sem ifs de uma linha sem "{}" porque acho mais legivel e organizado com.