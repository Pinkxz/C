#include <stdio.h>


int main() {
    long long int numeroTelefone;
    short int codigoArea;

    printf("Digite um numero de 8 + ddd digitos: ");
    scanf("%lld", &numeroTelefone);
    codigoArea = numeroTelefone / 100000000;

    printf("O codigo de area do telefone e %d.\n", codigoArea);

    return 0;
}
