#include <stdio.h>
#include <stdlib.h>

/*) Crie um algoritmo que use uma matriz 5x5 e que receba do usuário um valor. O valor lido será
inserido em todos os campos da primeira linha da matriz. Agora coloque em todos os campos da
linha 2 o valor do usuário acrescido em 1, na terceira linha o valor acrescido em 2, e assim por diante.
Por fim seu algoritmo deve imprimir a matriz resultante.*/

int main()
{
    int numero = 0, matriz[5][5];

    printf("Digite seu numero: ");
    scanf("%d", &numero);

    for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5; j++){
            matriz[i][j] = numero + i;
        }
    }
    for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5; j++){
            printf("%d %d = %d", i, j, matriz[i][j]);
             printf("\n");
        }
         printf("\n");
    }
    return 0;
}
