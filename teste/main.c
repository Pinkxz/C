#include <stdio.h>

// Função de ordenação por inserção
void insertionSort(int *V, int N) {
    int i, j, atual;
    for(i = 1; i < N; i++) {
        atual = V[i];
        j = i - 1;
        while(j >= 0 && V[j] > atual) {
            V[j + 1] = V[j];
            j--;
        }
        V[j + 1] = atual;
    }
}

// Função de mesclagem para Merge Sort
void merge(int *V, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = V[l + i];
    for(j = 0; j < n2; j++)
        R[j] = V[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            V[k] = L[i];
            i++;
        } else {
            V[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        V[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        V[k] = R[j];
        j++;
        k++;
    }
}

// Função de ordenação Merge Sort
void mergeSort(int *V, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;

        mergeSort(V, l, m);
        mergeSort(V, m + 1, r);

        merge(V, l, m, r);
    }
}

// Função para imprimir o vetor
void printArray(int *V, int N) {
    for(int i = 0; i < N; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

// Função principal para testar Insertion Sort e Merge Sort
int main() {
    // Vetor de exemplo para Insertion Sort
    int V1[] = {12, 11, 13, 5, 6};
    int N1 = sizeof(V1) / sizeof(V1[0]);

    // Vetor de exemplo para Merge Sort
    int V2[] = {38, 27, 43, 3, 9, 82, 10};
    int N2 = sizeof(V2) / sizeof(V2[0]);

    // Testa Insertion Sort
    printf("Vetor original (Insertion Sort): ");
    printArray(V1, N1);

    insertionSort(V1, N1);

    printf("Vetor ordenado (Insertion Sort): ");
    printArray(V1, N1);

    // Testa Merge Sort
    printf("Vetor original (Merge Sort): ");
    printArray(V2, N2);

    mergeSort(V2, 0, N2 - 1);

    printf("Vetor ordenado (Merge Sort): ");
    printArray(V2, N2);

    return 0;
}
