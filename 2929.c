#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000000

int minimos[MAX_SIZE];

int main() {
    char operacao[5];  // Ajuste para suportar operações com 4 caracteres + terminador nulo
    int N, V, minimo, p;

    p = -1;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%d", &V);

            if (p == -1) {
                minimo = V;
            } else {
                minimo = (minimos[p] < V ? minimos[p] : V);
            }

            minimos[++p] = minimo;
        } else if (strcmp(operacao, "POP") == 0) {
            if (p == -1) {
                printf("EMPTY\n");
            } else {
                --p;
            }
        } else if (strcmp(operacao, "MIN") == 0) {
            if (p == -1) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", minimos[p]);
            }
        }
    }

    return 0;
}
