#include <stdio.h>

void insere(int V[], int val, int n) {
    V[n] = val;

    // Bubble Sort
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n + 1 - i - 1; j++) {
            if (V[j] > V[j + 1]) {
                int temp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = temp;
            }
        }
    }

    printf("Vetor resultante: ");
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

int main() {
    int val = 10;
    int V[5] = {1, 3, 4, 5};
    int n = 4;

    insere(V, val, n);

    return 0;
}
