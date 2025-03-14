#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int passagem;
    char nome[20];
    char sexo;
}Poltrona;

typedef struct{
    char de[20];
    char para[20];
    int hora;
    int chegada;

    Poltrona poltrona[44];
}Onibus;

int main()
{
    Onibus linha;


    return 0;
}
