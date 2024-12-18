#include <stdio.h>
#define TAM_MATRIZ 9

// Função para verificar se tem os números de 1 a 9 sem repetição
int ProcurarRepeticao(int arr[]) {
    int visitados[TAM_MATRIZ + 1] = {0}; // Array para controlar quais números já foram visitados
    for (int i = 0; i < TAM_MATRIZ; i++) {
        if (arr[i] < 1 || arr[i] > 9 || visitados[arr[i]] == 1) {
            return 0; // Se tiver repetição ou número inválido, retorna falso
        }
        visitados[arr[i]] = 1; // Marca o número como visitado
    }
    return 1;
}

int CorretorSudoku(int grade[TAM_MATRIZ][TAM_MATRIZ]) {
    // Verifica linhas
    for (int i = 0; i < TAM_MATRIZ; i++) {
        if (!ProcurarRepeticao(grade[i])) {
            return 0; // Se tiver repetição em alguma linha, retorna falso
        }
    }

    // Verifica colunas
    for (int j = 0; j < TAM_MATRIZ; j++) {
        int coluna[TAM_MATRIZ];
        for (int i = 0; i < TAM_MATRIZ; i++) {
            coluna[i] = grade[i][j]; // armazena no array temporario
        }
        if (!ProcurarRepeticao(coluna)) {
            return 0;
        }
    }

    // Verifica matrizes 3x3
    for (int blocoLinha = 0; blocoLinha < 3; blocoLinha++) {
        for (int blocoColuna = 0; blocoColuna < 3; blocoColuna++) {
            int bloco[TAM_MATRIZ];
            int indice = 0;
            for (int i = blocoLinha * 3; i < blocoLinha * 3 + 3; i++) {
                for (int j = blocoColuna * 3; j < blocoColuna * 3 + 3; j++) {
                    bloco[indice++] = grade[i][j];
                }
            }
            if (!ProcurarRepeticao(bloco)) {
                return 0;
            }
        }
    }

    return 1; // Se tudo tiver correto, retorna verdadeiro
}

int main() {
    int numInstancias;
    scanf("%d", &numInstancias);

    for (int inst = 1; inst <= numInstancias; inst++) {
        int grade[TAM_MATRIZ][TAM_MATRIZ];
        for (int i = 0; i < TAM_MATRIZ; i++) {
            for (int j = 0; j < TAM_MATRIZ; j++) {
                scanf("%d", &grade[i][j]);
            }
        }

        printf("Instancia %d\n", inst);
        if (CorretorSudoku(grade)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }
    return 0;
}
