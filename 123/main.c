#include <stdio.h>
#include <stdbool.h>

bool ehLetra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool ehPonto(char c) {
    return c == '.';
}

float calcularTamanhoMedio(char *texto) {
    int totalPalavras = 0;
    int totalLetras = 0;
    int comprimentoPalavra = 0;
    bool dentroPalavra = false;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (ehLetra(texto[i])) {
            dentroPalavra = true;
            comprimentoPalavra++;
        } else if (ehPonto(texto[i]) || texto[i] == ' ') {
            if (dentroPalavra) {
                totalPalavras++;
                totalLetras += comprimentoPalavra;
                comprimentoPalavra = 0;
                dentroPalavra = false;
            }
        }
    }

    if (totalPalavras > 0) {
        return (float) totalLetras / totalPalavras;
    } else {
        return 0;
    }
}

int main() {
    char texto[100];

    printf("Digite um texto: ");
    fgets(texto, sizeof(texto), stdin);

    float tamanhoMedio = calcularTamanhoMedio(texto);

    printf("O tamanho médio das palavras no texto é: %.2f\n", tamanhoMedio);

    return 0;
}

