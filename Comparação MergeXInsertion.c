#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

#define MAX_N 400000
#define STEP_N 50000

void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

void mesclar(int arr[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    int L[n1], R[n2];

    // Copia os dados para arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    // Mescla os arrays temporários de volta para arr[esquerda..direita]
    i = 0;
    j = 0;
    k = esquerda;
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

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        // Mescla as duas metades ordenadas
        mesclar(arr, esquerda, meio, direita);
    }
}

// Função para medir o tempo de execução do Insertion Sort
double medirTempoInsertionSort(int arr[], int n) {
    clock_t t;
    t = clock();
    insertionSort(arr, n);
    t = clock() - t;
    return ((double)t) / ((CLOCKS_PER_SEC / 1000)); // Retorna o tempo em milissegundos
}

// Função para medir o tempo de execução do Merge Sort
double medirTempoMergeSort(int arr[], int esquerda, int direita) {
    clock_t t;
    t = clock();
    mergeSort(arr, esquerda, direita);
    t = clock() - t;
    return ((double)t) / ((CLOCKS_PER_SEC / 1000)); // Retorna o tempo em milissegundos
}

int main() {
    int n, i, j;

    // Define a semente de aleatoriedade
    srand((unsigned)time(NULL));

    // Itera sobre diferentes tamanhos de vetores
    for (n = STEP_N; n <= MAX_N; n += STEP_N) {
        double somaTempoInsertionSort = 0.0;
        double somaTempoMergeSort = 0.0;

        // Realiza três testes para cada tamanho de vetor
        for (j = 0; j < 3; j++) {
            int *arr1 = (int*) malloc(n * sizeof(int));
            int *arr2 = (int*) malloc(n * sizeof(int));

            // Gera valores aleatórios para os vetores
            for (i = 0; i < n; i++) {
                arr1[i] = rand() % MAX_N;
                arr2[i] = arr1[i];
            }

            // Mede o tempo de execução do Insertion Sort
            somaTempoInsertionSort += medirTempoInsertionSort(arr1, n);

            // Mede o tempo de execução do Merge Sort
            somaTempoMergeSort += medirTempoMergeSort(arr2, 0, n-1);

            free(arr1);
            free(arr2);
        }

        double mediaTempoInsertionSort = somaTempoInsertionSort / 3.0;
        double mediaTempoMergeSort = somaTempoMergeSort / 3.0;

        printf("n = %d, InsertionSort: %lf ms, MergeSort: %lf ms\n", n, mediaTempoInsertionSort, mediaTempoMergeSort);

    }
    return 0;
}
