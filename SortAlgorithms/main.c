#include <stdio.h>
#include "sorts.h"

int main() {
    // Inicialize o gerador de n�meros aleat�rios com o tempo atual
    srand(time(NULL));

    // Defina o tamanho do array
    int n = 100;

    // Declare o array
    int arr[n];

    // Preencha o array com n�meros aleat�rios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Gera n�meros aleat�rios entre 0 e 999
    }

    // Escolha qual algoritmo de ordena��o deseja usar descomentando a linha correspondente

     //bubbleSort(arr, n);
     //selectionSort(arr, n);
    // insertionSort(arr, n);
    // mergeSort(arr, 0, n-1);
    // quickSort(arr, 0, n-1);
    // countingSort(arr, n, 90);
    // radixSort(arr, n);
    // bucketSort(arr, n);

    printf("Array gerado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Array ordenado:\n");
    printArray(arr, n);
    return 0;
}
