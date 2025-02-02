#include <stdio.h>
#include <string.h>

#define MAX_REGIOES 101
#define MAX_PONTES 4951

int R, K; // Variáveis globais
int graus[MAX_REGIOES];
int dp[MAX_REGIOES][MAX_PONTES];

// Função de programação dinâmica
int podeDistribuir(int regiao, int pontesRestantes) {
    if (regiao > R) {
        return (pontesRestantes == K);
    }
    
    if (dp[regiao][pontesRestantes] != -1) {
        return dp[regiao][pontesRestantes];
    }

    // Verifica se é possível distribuir as pontes
    int naoDistribuir = podeDistribuir(regiao + 1, pontesRestantes);
    int distribuir = (pontesRestantes + graus[regiao] <= K) ? podeDistribuir(regiao + 1, pontesRestantes + graus[regiao]) : 0;

    // Armazena e retorna o resultado
    return dp[regiao][pontesRestantes] = (naoDistribuir || distribuir);
}

int main() {
    int A, B;

    // Processa cada caso de teste
    while (scanf("%d %d", &R, &K) != EOF) {
        // Inicializa as variáveis
        memset(graus, 0, sizeof(graus));
        memset(dp, -1, sizeof(dp));

        // Lê as pontes e atualiza os graus das regiões
        for (int i = 0; i < K; ++i) {
            scanf("%d %d", &A, &B);
            ++graus[A];
            ++graus[B];
        }

        // Verifica se é possível distribuir as pontes e imprime o resultado
        printf("%c\n", podeDistribuir(1, 0) ? 'S' : 'N');
    }

    return 0;
}
