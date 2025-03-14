#include <stdio.h>
#include <stdlib.h>
/*Fa�a uma an�lise emp�rica dos algoritmos mergesort, quicksort, selection sort
Para an�lise emp�rica:

Gere cinco vetores[] de tamanho 10000 com n�mero inteiros(de 0 a 65535) aleat�rios utilizando a fun��o rand()

Execute cada um dos algoritmos(ex: mergesort) utiizando cada vetor gerado no passo(1)*

Me�a o n�mero de opera��es de compara��o feitas por cada algoritmo
Compute o tempo m�dio das 5 execu��es para cada algortimo e apresente os resultados. Explique o porqu� dos resultados obtidos.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

void generate_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 65536;
    }
}

int main() {
    clock_t begin = clock();
    const int vector_size = 10000;
    const int num_vectors = 5;

    int vectors[num_vectors][vector_size];

    // Criar 5 vetores de 10.000 posi��es com n�meros aleat�rios
    for (int i = 0; i < num_vectors; i++) {
        generate_random_array(vectors[i], vector_size);
    }

    // Aplicar o Selection Sort em cada vetor
    for (int i = 0; i < num_vectors; i++) {
        selection_sort(vectors[i], vector_size);
    }

    // Imprimir todos os valores dos vetores ordenados
    for (int i = 0; i < num_vectors; i++) {
        printf("Vetor %d: ", i + 1);
        for (int j = 0; j < vector_size; j++) {
            printf("%d ", vectors[i][j]);
        }
        printf("\n");
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo-medio: %f", time_spent);

    return 0;
}

