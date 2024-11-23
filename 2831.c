#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define TAMANHO_MAX_NOME 21

// Função para mesclar as duas metades
void mesclar(char arr[][TAMANHO_MAX_NOME], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Arrays temporários
    char E[n1][TAMANHO_MAX_NOME], D[n2][TAMANHO_MAX_NOME];

    // Copiar dados para os arrays temporários
    for (i = 0; i < n1; i++)
        strcpy(E[i], arr[esquerda + i]);
    for (j = 0; j < n2; j++)
        strcpy(D[j], arr[meio + 1 + j]);

    // Mesclar os arrays temporários em arr, após serem comparados alfabeticamente
    i = 0; 
    j = 0;
    k = esquerda;
    while (i < n1 && j < n2) {
        if (strcmp(E[i], D[j]) <= 0) {
            strcpy(arr[k], E[i]);
            i++;
        } else {
            strcpy(arr[k], D[j]);
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de E[]
    while (i < n1) {
        strcpy(arr[k], E[i]);
        i++;
        k++;
    }

    // Copiar os elementos restantes de D[],
    while (j < n2) {
        strcpy(arr[k], D[j]);
        j++;
        k++;
    }
}

void mergeSort(char arr[][TAMANHO_MAX_NOME], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordenar a primeira e a segunda metade
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        // Mesclar as metades ordenadas
        mesclar(arr, esquerda, meio, direita);
    }
}

int main() {
    int N, K;
    char nomes[MAX_ALUNOS][TAMANHO_MAX_NOME];

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%s", nomes[i]);
    }

    mergeSort(nomes, 0, N - 1);
    printf("%s\n", nomes[K-1]);

    return 0;
}
