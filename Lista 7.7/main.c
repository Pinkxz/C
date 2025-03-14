#include <stdio.h>
#include <string.h>

#define MAX_POMEKONS 151
#define MAX_NOME 1001

int contarPomekonsFaltantes(char capturados[][MAX_NOME], int n) {
    int i, j, faltantes = MAX_POMEKONS;
    int encontrados[MAX_POMEKONS] = {0};

    // Marcar os Pomekons já capturados como encontrados
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_POMEKONS; j++) {
            if (strcmp(capturados[i], todos_pomekons[j]) == 0) {
                encontrados[j] = 1;
                break;
            }
        }
    }

    // Contar os Pomekons faltantes
    for (i = 0; i < MAX_POMEKONS; i++) {
        if (encontrados[i] == 1) {
            faltantes--;
        }
    }

    return faltantes;
}

int main() {
    int n, i;
    char capturados[MAX_POMEKONS][MAX_NOME];

    // Leitura da quantidade de Pomekons capturados
    scanf("%d", &n);

    // Leitura dos Pomekons capturados
    for (i = 0; i < n; i++) {
        scanf("%s", capturados[i]);
    }

    // Lista com todos os Pomekons disponíveis (151 no total)
    char todos_pomekons[MAX_POMEKONS][MAX_NOME] = {
        "Bulbasaur", "Ivysaur", "Venusaur",  // Exemplo de alguns nomes de Pomekons
        // Restante dos nomes...
    };

    // Chamada da função para contar os Pomekons faltantes
    int faltantes = contarPomekonsFaltantes(capturados, n);

    // Impressão do resultado
    printf("Falta(m) %d pomekon(s).\n", faltantes);

    return 0;
}
