//Junção de Insert, Merge e Quick para comparar os três Algoritmos
//Neste mesmo repositório há um código em Python para a criação de gráficios
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

#define MAX_N 400000
#define STEP_N 20000

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

// Função auxiliar do Merge
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

// Função Principal do Merge
void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        mesclar(arr, esquerda, meio, direita);
    }
}

// Função auxiliar do Quick
int separar(int v[], int p, int r) {
    int pivo = v[r];
    int i = (p - 1);
    for (int j = p; j <= r - 1; j++) {
        if (v[j] < pivo) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i + 1];
    v[i + 1] = v[r];
    v[r] = temp;
    return (i + 1);
}

// Função Principal do Quick
void quickSort(int v[], int p, int r) {
    if (p < r) {
        int q = separar(v, p, r);

        quickSort(v, p, q - 1);
        quickSort(v, q + 1, r);
    }
}

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

double medirTempoQuickSort(int v[], int p, int r) {
    clock_t t;
    t = clock();
    quickSort(v, p, r);
    t = clock() - t;
    return ((double)t) / ((CLOCKS_PER_SEC / 1000));
}

int main() {
    int n, i, j;

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

        double mediaTempoInsertionSort = somaTempoInsertionSort / 3.0;
        double mediaTempoMergeSort = somaTempoMergeSort / 3.0;
        double mediaTempoQuickSort = somaTempoQuickSort / 3.0;

        printf("n = %d, InsertionSort: %lf ms, MergeSort: %lf ms, QuickSort: %lf ms\n", n, mediaTempoInsertionSort, mediaTempoMergeSort, mediaTempoQuickSort);
    }
    return 0;
}
