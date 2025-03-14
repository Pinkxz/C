#include <stdio.h>
#include <stdlib.h>

short int jogada = 0;

void encheMatriz(char matriz[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matriz[i][j] = '#';
        }
    }

}

void imprime(char matriz[3][3]){
    system("cls");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
     short int i = 0, j = 0, jogador = 0;
     char matriz[3][3];

     if(jogada == 0){
        encheMatriz(matriz);
        imprime(matriz);
    }

    while(jogada < 10){

     if(jogador == 0){
                printf("Digite o valor Jogador %d: ", jogador + 1);
                scanf("%d", &j);
                matriz[i][j] = 'X';
                jogador = 1;
                imprime(matriz);
     }if(jogador == 1){
                printf("Digite o valor Jogador %d: ", jogador + 1);
                scanf("%d", &j);
                matriz[i][j] = 'O';
                jogador = 0;
                imprime(matriz);
     }
     jogada++;
    }
    main();
    return 0;
}
