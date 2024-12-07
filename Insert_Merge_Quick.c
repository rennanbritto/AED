#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

#define MAX_N 400000
#define STEP_N 20000

//função do insertion
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

//função auxiliar para o Mergesort
void mesclar(int arr[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

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

//função principal do MergeSort
void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        mesclar(arr, esquerda, meio, direita);
    }
}

//função auxiliar do QuickSort
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

//função principal do QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Abaixo, segue as funções para medição do tempo dos três métodos
double medirTempoInsertionSort(int arr[], int n) {
    clock_t t;
    t = clock();
    insertionSort(arr, n);
    t = clock() - t;
    return ((double)t) / ((CLOCKS_PER_SEC / 1000));
}

double medirTempoMergeSort(int arr[], int esquerda, int direita) {
    clock_t t;
    t = clock();
    mergeSort(arr, esquerda, direita);
    t = clock() - t;
    return ((double)t) / ((CLOCKS_PER_SEC / 1000));
}

double medirTempoQuickSort(int arr[], int low, int high) {
    clock_t t;
    t = clock();
    quickSort(arr, low, high);
    t = clock() - t;
    return ((double)t) / ((CLOCKS_PER_SEC / 1000));
}

int main() {
    int n, i, j;

    //baseado no código disponibilizado no classroom
    srand((unsigned)time(NULL));

    for (n = STEP_N; n <= MAX_N; n += STEP_N) {
        double somaTempoInsertionSort = 0.0;
        double somaTempoMergeSort = 0.0;
        double somaTempoQuickSort = 0.0;

        for (j = 0; j < 3; j++) {
            int *arr1 = (int*) malloc(n * sizeof(int));
            int *arr2 = (int*) malloc(n * sizeof(int));
            int *arr3 = (int*) malloc(n * sizeof(int));

            for (i = 0; i < n; i++) {
                arr1[i] = rand() % MAX_N;
                arr2[i] = arr1[i];
                arr3[i] = arr1[i];
            }

            somaTempoInsertionSort += medirTempoInsertionSort(arr1, n);
            somaTempoMergeSort += medirTempoMergeSort(arr2, 0, n - 1);
            somaTempoQuickSort += medirTempoQuickSort(arr3, 0, n - 1);

            free(arr1);
            free(arr2);
            free(arr3);
        }

        //média do tempo a partir de três rodagens
        double mediaTempoInsertionSort = somaTempoInsertionSort / 3.0;
        double mediaTempoMergeSort = somaTempoMergeSort / 3.0;
        double mediaTempoQuickSort = somaTempoQuickSort / 3.0;

        printf("n = %d, InsertionSort: %lf ms, MergeSort: %lf ms, QuickSort: %lf ms\n", n, mediaTempoInsertionSort, mediaTempoMergeSort, mediaTempoQuickSort);
    }
    return 0;
}
