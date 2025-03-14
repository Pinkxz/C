#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maximo 100
int main()
{
    char palavra[maximo], palavra2[maximo];
    int tamanho;

    printf("Digite sua frase: ");
    gets(palavra);

    tamanho = strlen(palavra) - 1;

    for(int i = 0; palavra[i] != '\0'; i++){
        palavra2[i] = palavra[tamanho];
        tamanho--;
    }

    printf("A frase invertida: %s", palavra2);
    return 0;
}
