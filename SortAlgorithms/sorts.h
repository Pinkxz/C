#ifndef SORTS_H
#define SORTS_H

#include <stdio.h>

// Busca Binária
int binarySearch(int arr[], int left, int right, int x);

// Bubble Sort
void bubbleSort(int arr[], int n);

// Selection Sort
void selectionSort(int arr[], int n);

// Insertion Sort
void insertionSort(int arr[], int n);

// Merge Sort
void mergeSort(int arr[], int l, int r);

// Quick Sort
void quickSort(int arr[], int low, int high);

// Counting Sort
void countingSort(int arr[], int n, int range);

// Radix Sort
void radixSort(int arr[], int n);

// Bucket Sort
void bucketSort(int arr[], int n);

// Função de impressão de array
void printArray(int arr[], int n);

#endif /* SORTS_H */
