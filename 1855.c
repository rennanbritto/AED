#include <stdio.h>
#include <string.h>

#define MAX 100 // Tamanho max do mapa

int main() {
    int n, m;
    char mapa[MAX][MAX];
    int visitado[MAX][MAX] = {0};
    int x = 0, y = 0; // Posição inicial
    int dx = 0, dy = 1; // Direção inicial

    // Dimensões do mapa
    scanf("%d %d", &n, &m);

    // Leitura do mapa
    for (int i = 0; i < m; i++) {
        scanf("%s", mapa[i]);
    }

    while (1) {
        // Verifica se a posição atual é inválida
        if (x < 0 || x >= m || y < 0 || y >= n || visitado[x][y]) {
            printf("!\n");
            return 0;
        }

        // Marca a posição como visitada
        visitado[x][y] = 1;

        if (mapa[x][y] == '*') {
            printf("*\n");
            return 0;
        } else if (mapa[x][y] == '>') {
            dx = 0; dy = 1;
        } else if (mapa[x][y] == '<') {
            dx = 0; dy = -1;
        } else if (mapa[x][y] == '^') {
            dx = -1; dy = 0;
        } else if (mapa[x][y] == 'v') {
            dx = 1; dy = 0;
        }

        // Atualiza a posição
        x += dx;
        y += dy;
    }
}
