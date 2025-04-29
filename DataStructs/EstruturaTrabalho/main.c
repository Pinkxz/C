#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAMANHOS 3

// Função para capturar o tempo de execução
double medir_tempo(void (*funcao)(int[], int), int arr[], int n) {
    clock_t inicio = clock();
    funcao(arr, n);
    return ((double)(clock() - inicio)) / CLOCKS_PER_SEC;
}

// Função para preencher vetores
void preencher_vetores(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 10);
    }
}

// O(1) - Retorna primeiro elemento
void constante(int arr[], int n) {
     int resultado = arr[0];
}

// O(log n) - Busca binária
void logaritmica(int arr[], int n) {
    int inicio = 0, fim = n - 1, meio;
    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;
        if (arr[meio] == arr[n - 1]) return;
        if (arr[meio] < arr[n - 1]) inicio = meio + 1;
        else fim = meio - 1;
    }
}

// O(n) - Percorre a lista uma vez
void linear(int arr[], int n) {
    volatile int soma = 0;
    for (int i = 0; i < n; i++) soma += arr[i];
}

// O(n log n) - QuickSort
void quicksort(int arr[], int baixo, int alto) {
    while (baixo < alto) {
        int pivo = arr[alto], i = baixo - 1;
        for (int j = baixo; j < alto; j++) {
            if (arr[j] < pivo) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[alto];
        arr[alto] = temp;

        if ((i - baixo) < (alto - i - 2)) {
            quicksort(arr, baixo, i);
            baixo = i + 2;
        } else {
            quicksort(arr, i + 2, alto);
            alto = i;
        }
    }
}

void quasilinear(int arr[], int n) {
    quicksort(arr, 0, n - 1);
}

// O(n²) - Ordenação por Inserção
void quadratica(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

// Fibonacci com complexidade O(2ⁿ)
int fib(int x) {
    if (x <= 1) return x;
    return fib(x - 1) + fib(x - 2);
}

void fibonacci(int arr[], int n) {
    fib(n);  // Calculando o Fibonacci de n
}

// O(n!) - Permutação
void permutacao(int arr[], int l, int r) {
    if (l == r) return;
    for (int i = l; i <= r; i++) {
        int temp = arr[l]; arr[l] = arr[i]; arr[i] = temp;
        permutacao(arr, l + 1, r);
        temp = arr[l]; arr[l] = arr[i]; arr[i] = temp;
    }
}

void fatorial(int arr[], int n) {
    permutacao(arr, 0, n - 1);
}

// Função para testar algoritmos
void testar_algoritmo(void (*algoritmo)(int[], int), int tamanhos[], int qtd_tamanhos, const char *nome) {
    for (int i = 0; i < qtd_tamanhos; i++) {
        int n = tamanhos[i];
        int *arr = (int *)malloc(n * sizeof(int));
        if (!arr) {
            printf("Erro ao alocar memória!\n");
            return;
        }
        preencher_vetores(arr, n);

        printf("\nExecutando %s com n = %d...\n", nome, n);
        double tempo = medir_tempo(algoritmo, arr, n);
        printf("Tempo de execução: %f segundos\n", tempo);

        free(arr);
    }
}

// Menu principal
void menu() {
    int opcao;
    int tamanhos_normais[] = {1, 100000, 1000000};
    int tamanhos_fibonacci[] = {1, 45, 54};
    int tamanhos_fatorial[] = {1, 13, 14};

    while (1) {
        printf("\nEscolha um algoritmo:\n");
        printf("1. O(1) - Constante\n2. O(log n) - Logarítmica\n3. O(n) - Linear\n");
        printf("4. O(n log n) - Quasilinear\n5. O(n²) - Quadrática\n6. O(2^n) - Fibonacci\n");
        printf("7. O(n!) - Permutação\n8. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 8) break;

        switch (opcao) {
            case 1: testar_algoritmo(constante, tamanhos_normais, 3, "Constante"); break;
            case 2: testar_algoritmo(logaritmica, tamanhos_normais, 3, "Logarítmica"); break;
            case 3: testar_algoritmo(linear, tamanhos_normais, 3, "Linear"); break;
            case 4: testar_algoritmo(quasilinear, tamanhos_normais, 3, "Quasilinear"); break;
            case 5: testar_algoritmo(quadratica, tamanhos_normais, 3, "Quadrática"); break;
            case 6: testar_algoritmo(fibonacci, tamanhos_fibonacci, 3, "Fibonacci"); break;
            case 7: testar_algoritmo(fatorial, tamanhos_fatorial, 3, "Permutação"); break;
            default: printf("Opção inválida!\n");
        }
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}
