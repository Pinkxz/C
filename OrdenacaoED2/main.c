#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>



void preencheVetor(int *vetor, int tamanhoi){

    for(int i = 0; i < tamanhoi; i++){
        vetor[i] = rand() % 1000;
    }
}

float bubbleSort(int *vetor, int tamanhoi) {
    clock_t inicio = clock();
    for (int i = 0; i < tamanhoi - 1; i++) {
        for (int j = 0; j < tamanhoi - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    return ((float)(clock() - inicio)) / CLOCKS_PER_SEC;
}


float selectionSort(int *vetor, int tamanhoi) {
    clock_t inicio = clock();
    for (int i = 0; i < tamanhoi - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanhoi; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        int aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
    return ((float)(clock() - inicio)) / CLOCKS_PER_SEC;
}


float insertionSort(int *vetor, int tamanhoi){
    clock_t inicio = clock();
    for (int i = 1; i < tamanhoi; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }

    return ((float)(clock() - inicio)) / CLOCKS_PER_SEC;
}


/* 
Cópia de vetor para evitar de chamar um algoritmo de ordenação para um vetor anteriormente
ordenado por outra função
*/
void testaSorts(int *vetorOriginal, int tamanho) {
    int *vetor = malloc(sizeof(int) * tamanho);
    float tempo;

    memcpy(vetor, vetorOriginal, sizeof(int) * tamanho);
    tempo = bubbleSort(vetor, tamanho);
    printf("Tempo de execucao bubble de %d: %f\n", tamanho, tempo);

    memcpy(vetor, vetorOriginal, sizeof(int) * tamanho);
    tempo = selectionSort(vetor, tamanho);
    printf("Tempo de execucao selection de %d: %f\n", tamanho, tempo);

    memcpy(vetor, vetorOriginal, sizeof(int) * tamanho);
    tempo = insertionSort(vetor, tamanho);
    printf("Tempo de execucao insertion de %d: %f\n", tamanho, tempo);

    free(vetor);
}

int main(){

    int *vetor10 = malloc(sizeof(int) * 10);
    int *vetor1000 = malloc(sizeof(int) * 1000);
    int *vetor100000 = malloc(sizeof(int) * 100000);

    preencheVetor(vetor10, 10);
    testaSorts(vetor10, 10);

    preencheVetor(vetor1000, 1000);
    testaSorts(vetor1000, 1000);

    preencheVetor(vetor100000, 100000);
    testaSorts(vetor100000, 100000);

    free(vetor10);
    free(vetor1000);
    free(vetor100000);

    return 0;
}