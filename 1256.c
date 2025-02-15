#include <stdio.h>
#include <string.h>

#define TAMANHO_MAXIMO 200

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M, C;
        scanf("%d %d", &M, &C);

        int tabela[M][TAMANHO_MAXIMO];
        int tamanhos[M];  
        
        //pra
        memset(tamanhos, 0, sizeof(tamanhos));

        for (int i = 0; i < C; i++) {
            int chave;
            scanf("%d", &chave);
            int indice = chave % M;
            tabela[indice][tamanhos[indice]++] = chave;
        }

        for (int i = 0; i < M; i++) {
            printf("%d ->", i);
            for (int j = 0; j < tamanhos[i]; j++) {
                printf(" %d ->", tabela[i][j]);
            }
            printf(" \\\n");
        }

        if (N > 0) {
            printf("\n");
        }
    }

    return 0;
}
