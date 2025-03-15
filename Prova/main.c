#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct sala{
    char alunos[50];
    int NumCadeira;
    char professor[50];
    struct sala *proximo;
} Sala;

void imprimir(Sala*);
Sala* inserir();
Sala* deletar();
Sala* modificar();


int main()
{
    setlocale(LC_ALL, "Portuguese");
    Sala *salas = NULL;

    int menu = 20;

    system("color f0");

    while (menu != 0) {
        printf("\n--------------------------------------------------------------------");
        printf("\n--------------------Controle de Salas-----------------------------");
        printf("\n--------------------------------------------------------------------\n");
        printf("1- Cadastrar Aluno\n");
        printf("2- Imprimir Aluno\n");
        printf("3- Deletar Aluno\n");
        printf("--------------------------------------------------------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: salas = inserir(salas); break;
            case 2: imprimir(salas); break;
            case 3: salas = deletar(salas); break;
            case 0: printf("\nSaindo do programa.\n"); break;
            default: printf("\nOpção inválida!\n");
        }
        if (menu != 0) {
            system("pause");
            system("cls");
        }
    }
    return 0;
}


void imprimir(Sala *lista){

    Sala *auxiliar = lista;

    while(auxiliar!=NULL){
        printf("Alunos: %s\n", auxiliar->alunos);
        printf("Professores: %s\n", auxiliar->professor);
        printf("Cadeiras: %d\n", auxiliar->NumCadeira);
        auxiliar=auxiliar->proximo;

        if(auxiliar == NULL){
            printf("Fim da lista");
        }
    }

}

Sala *inserir(Sala *destino){
    Sala *novo = (Sala *)malloc(sizeof(Sala));

    fflush(stdin);
    printf("Insira o nome do Aluno: ");
    gets(novo->alunos);
    fflush(stdin);

    printf("Insira a cadeira dele: ");
    scanf("%d", &novo->NumCadeira);
    fflush(stdin);

    printf("Insira o nome do professor: \n");
    gets(novo->professor);
    fflush(stdin);

    novo->proximo = destino;
    return novo;

}


Sala *deletar(Sala *salas){

    Sala *anterior = NULL;
    Sala *auxiliar = salas;

    int numCadeira;
    printf("Digite a cadeira do aluno: ");
    scanf("%d", &numCadeira);

    while(auxiliar != NULL && auxiliar->NumCadeira != numCadeira){
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }

    if(anterior == NULL){
        salas = auxiliar->proximo;
    }else{
        anterior->proximo = auxiliar->proximo;
    }

    free(auxiliar);
    printf("aluno removido");
    return salas;

}


