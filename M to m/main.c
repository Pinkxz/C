#include <stdio.h>

int main() {
    char letras[10];
    int i;

    printf("Digite 10 letras min�sculas:\n");

    for (i = 0; i < 10; i++) {
        scanf(" %c", &letras[i]);
        //fflush(stdin);
    }

    for(i = 0; i < 10; i++){
        letras[i] = letras[i] + 32;
    }
    printf("\nAs letras em mai�sculas s�o:\n");

    for (i = 0; i < 10; i++) {
        printf("%c ", letras[i]);
    }

    return 0;
}

