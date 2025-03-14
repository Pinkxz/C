#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base = 0, altura = 0, area = 0;
    printf("Digite a Base e a Altura do retangulo: ");
    scanf("%d", &base);
    scanf("%d", &altura);

    area = base * altura;

    printf("A area e : %d", area);
    return 0
;}
