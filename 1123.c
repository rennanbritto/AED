#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CIDADES 1010
#define INF INT_MAX

typedef struct {
    int destino;
    int peso;
    struct Aresta* prox;
} Aresta;

typedef struct {
    Aresta* listaAdj;
} Grafo;

// Função para criar uma aresta
Aresta* criarAresta(int destino, int peso) {
    Aresta* nova = (Aresta*)malloc(sizeof(Aresta));
    nova->destino = destino;
    nova->peso = peso;
    nova->prox = NULL;
    return nova;
}

// Função para adicionar uma aresta ao grafo
void adicionarAresta(Grafo* grafo, int origem, int destino, int peso) {
    Aresta* nova = criarAresta(destino, peso);
    nova->prox = grafo[origem].listaAdj;
    grafo[origem].listaAdj = nova;
}

// Inicializa o grafo
void inicializarGrafo(Grafo* grafo, int n) {
    for (int i = 0; i < n; i++) {
        grafo[i].listaAdj = NULL;
    }
}

int dijkstra(Grafo* grafo, int n, int origem, int destino) {
    int custo[MAX_CIDADES], visitado[MAX_CIDADES];
    for (int i = 0; i < n; i++) {
        custo[i] = INF;
        visitado[i] = 0;
    }

    custo[origem] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        // Encontra o menor custo não visitado
        for (int j = 0; j < n; j++) {
            if (!visitado[j] && (u == -1 || custo[j] < custo[u])) {
                u = j;
            }
        }

        if (custo[u] == INF) break;

        visitado[u] = 1;

        // Atualiza os custos para os vizinhos
        for (Aresta* aresta = grafo[u].listaAdj; aresta != NULL; aresta = aresta->prox) {
            int v = aresta->destino;
            int peso = aresta->peso;

            if (custo[u] + peso < custo[v]) {
                custo[v] = custo[u] + peso;
            }
        }
    }

    return custo[destino];
}

int main() {
    int n, m, c, k;

    while (scanf("%d %d %d %d", &n, &m, &c, &k), (n || m || c || k)) {
        Grafo grafo[MAX_CIDADES];
        inicializarGrafo(grafo, n);

        for (int i = 0; i < m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            if (u >= c && v >= c) {
                adicionarAresta(grafo, u, v, p);
                adicionarAresta(grafo, v, u, p);
            } else if (u >= c && v < c) {
                adicionarAresta(grafo, u, v, p);
            } else if (u < c && v >= c) {
                adicionarAresta(grafo, v, u, p);
            } else if (u < c && v < c && abs(u - v) == 1) {
                adicionarAresta(grafo, u, v, p);
                adicionarAresta(grafo, v, u, p);
            }
        }

        printf("%d\n", dijkstra(grafo, n, k, c - 1));
    }

    return 0;
}
