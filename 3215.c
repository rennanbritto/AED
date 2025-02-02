#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 10000

int N, M;                // Número de pessoas (nós) e número de amizades (arestas)
int deve[MAX_N];         // Quanto cada pessoa deve ou é devida
int visitado[MAX_N];     // Array para marcar quais nós foram visitados
int *amizades[MAX_N];    // Lista de adjacência para o grafo (amizades)
int tamanho_lista[MAX_N];// Tamanho da lista de adjacência para cada nó

// Função para adicionar uma aresta no grafo
void adicionar_aresta(int x, int y) {
    amizades[x] = realloc(amizades[x], (tamanho_lista[x] + 1) * sizeof(int));
    amizades[y] = realloc(amizades[y], (tamanho_lista[y] + 1) * sizeof(int));
    amizades[x][tamanho_lista[x]++] = y;
    amizades[y][tamanho_lista[y]++] = x;
}

// Função de DFS para explorar um componente conectado
int dfs(int no) {
    visitado[no] = 1;
    int soma = deve[no];  // Inicia a soma com o valor da dívida do nó atual

    // Visita todos os vizinhos do nó atual
    for (int i = 0; i < tamanho_lista[no]; i++) {
        int vizinho = amizades[no][i];
        if (!visitado[vizinho]) {
            soma += dfs(vizinho);  // Soma as dívidas dos vizinhos
        }
    }

    return soma;
}

int main() {
    // Leitura da entrada
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &deve[i]);
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adicionar_aresta(x, y);
    }

    // Verifica todos os componentes conectados
    for (int i = 0; i < N; i++) {
        if (!visitado[i]) {
            if (dfs(i) != 0) {
                printf("IMPOSSIBLE\n");
                return 0;
            }
        }
    }

    printf("POSSIBLE\n");
    return 0;
}
