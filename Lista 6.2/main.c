#include <stdio.h>
#include <stdlib.h>

int verificaVezes(int vetor[], int numero, int vezes){
    for(int j = 0; j < 307; j++){
        if(numero == vetor[j]){
            vezes++;
        }
    }
    return vezes;
}
int main()
{
    int vetor[30], vezes = 0, numero;

    for(int i = 0; i < 30; i++){
        printf("\nPreencha o vetor na posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }
         printf("Digite um numero qualquer: ");
            scanf("%d", &numero);

            vezes = verificaVezes(vetor, numero, vezes);
            printf("O numero %d aparece %d vezes.", numero, vezes);
    return 0;
}
