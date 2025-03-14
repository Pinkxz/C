#include <stdio.h>
#include <stdlib.h>
/*Criar um programa que leia os elementos de uma matriz inteira 10 x 10 e escreva os elementos da
diagonal principal.
*/

int main()
{
    int matriz[5][5], k = 0, m = 0;

    for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5; j++){
            printf("\nPreencha a matriz na posicao %d %d: ", i + 1, j+ 1);
            scanf("%d", &matriz[i][j]);
        }
    }
    for( k = 0; k < 5;k++){
        printf("\n%d %d = %d", k, m, matriz[k][m]);
        m++;
    }
    return 0;
}
