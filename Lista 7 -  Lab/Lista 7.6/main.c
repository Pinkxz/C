#include <stdio.h>
#include <string.h>

#define MAX_POMEKONS 151
#define MAX_NOME 10

int main()
{
    int pomekon = 151;
    char matriz[10][10];
    int similaridade = 0;

    for(int i = 0; i < 10; i++){
        printf("Digite o pomekon capturado: ");
        scanf("%s", matriz[i]);
       // getchar();

    }
    pomekon--;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < strlen(matriz[i+1]); j++){
            if(matriz[i][j] == matriz[i+1][j]){
                similaridade++;
            }
        }
        if(similaridade >= strlen(matriz[i+1]) - 1){
            pomekon = pomekon;
        }else{
            pomekon--;
        }
        similaridade = 0;
    }
    printf("Faltam %d pomekons!!", pomekon);
    return 0;
}
