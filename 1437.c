#include <stdio.h>

int main() {
    char comando;
    int N, direcao;
    char direcoes[4] = {'N', 'L', 'S', 'O'};

    while (scanf("%d\n", &N) != EOF) {
        if (N == 0) {
            break;
        }

        direcao = 0;

        for (int i = 0; i < N; ++i) {
            scanf("%c", &comando);

            direcao += (comando == 'D') ? 1 : -1;
            direcao = (direcao + 4) % 4;
        }

        // Imprime a direção final
        printf("%c\n", direcoes[direcao]);
    }

    return 0;
}
