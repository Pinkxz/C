#include "sorts.h"

//Busca Bin�ria
/*Tempo m�dio: O(log n)
Melhor caso: O(1)
Pior caso: O(log n)*/
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Verifica se o elemento est� presente no meio
        if (arr[mid] == x)
            return mid;

        // Se o elemento � maior, ignore a metade esquerda
        if (arr[mid] < x)
            left = mid + 1;
        // Se o elemento � menor, ignore a metade direita
        else
            right = mid - 1;
    }

    // Se o elemento n�o estiver presente no array
    return -1;
}

// Bubble Sort
/*Tempo m�dio: O(n^2)
Melhor caso: O(n)
Pior caso: O(n^2)*/
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort
/*Tempo m�dio: O(n^2)
Melhor caso: O(n^2)
Pior caso: O(n^2)
*/
void selectionSort(int arr[], int n) {
    int minIndex;
    for (int i = 0; i < n-1; i++) {
        minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Insertion Sort
/*Tempo m�dio: O(n^2)
Melhor caso: O(n)
Pior caso: O(n^2)*/
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
/*Tempo m�dio: O(n log n)
Melhor caso: O(n log n)
Pior caso: O(n log n)*/
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Quick Sort
/*Tempo m�dio: O(n log n)
Melhor caso: O(n log n)
Pior caso: O(n^2)*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Counting Sort
/*Tempo m�dio: O(n + k)
Melhor caso: O(n + k)
Pior caso: O(n + k)
Onde 'k' � o intervalo dos elementos (a diferen�a entre o maior e o menor elemento).*/
void countingSort(int arr[], int n, int range) {
    int output[n];
    int count[range + 1];
    for (int i = 0; i <= range; ++i)
        count[i] = 0;
    for (int i = 0; i < n; ++i)
        ++count[arr[i]];
    for (int i = 1; i <= range; ++i)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

// Radix Sort
/*/*Tempo m�dio: O(n * d)
Melhor caso: O(n * d)
Pior caso: O(n * d)
Onde 'd' � o n�mero de d�gitos no maior n�mero do array.*/
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Bucket Sort
/*Tempo m�dio: O(n + k)
Melhor caso: O(n + k)
Pior caso: O(n^2)
Onde 'k' � o n�mero de baldes.*/
void bucketSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int bucket[maxVal + 1];
    for (int i = 0; i <= maxVal; i++) {
        bucket[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    for (int i = 0, j = 0; i <= maxVal; i++) {
        while (bucket[i] > 0) {
            arr[j++] = i;
            bucket[i]--;
        }
    }
}

// Fun��o de impress�o de array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

