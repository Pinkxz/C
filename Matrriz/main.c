#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maximo 10
#define coluna 10

void inverteString(char *string){
    char mascara;
    int i = 0;
    int j = strlen(string) - 1;

    mascara = string[j];
    string[j] = string[i];
    string[i] = mascara;

    i++;
    j--;
}
int main()
{
    int linhas;
    char matriz[maximo][coluna], palavra[maximo];

    while(1){

        printf("Escreva sua frase %d: ", linhas + 1);
        gets(palavra);

        if(linhas == maximo){
                printf("A matriz esta cheia. Encerrando a insercao de strings.");
        break;
        }
        /*if(strcmp(palavra, "fim") == 0){
            break;
        }*/
        if(palavra[0] == 'f' && palavra[1] == 'i' && palavra[2] == 'm')
         break;

        strncpy(matriz[linhas], palavra, maximo);
        linhas++;

    }
    for(int i = 0; i < linhas; i++){
            inverteString(matriz[i]);
        printf("\nSua string %s", matriz[i]);
    }
    return 0;
}
