#include <stdio.h>
#include <stdlib.h>
/* Considerando uma string X como entrada e outras 5 strings representadas em uma tabela, encontre
a string da tabela que mais se parece com a string X. Para isso verifique o cálculo de similaridade
entre duas palavras. Para esse caso, calcule a similaridade entre duas strings comparando caracter a
caracter e quando iguais acrescentando o valor um ao somador.
Entrada
A primeira linha contém uma string X ( em que 1 ≤ tamanho(X) ). Cada uma das próximas 5 linhas
contém uma string y ( tamanho(y) ≤ 1000).*/

int compara (char matriz[][15], char string[15], int maior){
    int similiar = 0;
    int indice = 0;
        for(int i = 0; i < 5; i++){
             for(int j = 0; j < 15; j++){
                if(string[j] == matriz[i][j]){
                    similiar++;
                }
            }
            if(similiar > maior){
                maior = similiar;
                indice = i;
            }
            similiar = 0;
        }
    return indice;
}

int main()
{
    char matriz[5][15], string[15];
    int maior = 0;

    printf("Digite a string: ");
    gets(string);

    for(int i = 0; i < 5; i++){
        printf("Digite uma string para comparacao: ");
        gets(matriz[i]);
    }

    maior = compara(matriz, string, maior);

    printf("\nString original %s ", string);

    for(int i = 0; i < 5; i++){
        printf("\nOutras strings %s ", matriz[i]);
    }
    printf("\nA mais parecida com a string e %s do indice %d", matriz[maior], maior);
    return 0;
}
