#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, peso;
} Aresta;

int pai[200000], rank[200000];

// Função para encontrar o representante do conjunto de um elemento
int encontrar(int x) {
    if (pai[x] != x){
        pai[x] = encontrar(pai[x]);
    }
    return pai[x];
}

// Função para unir dois conjuntos
void unir_conjuntos(int x, int y) {
    int raiz_x = encontrar(x);
    int raiz_y = encontrar(y);
    if (rank[raiz_x] > rank[raiz_y]) {
        pai[raiz_y] = raiz_x;
    } else if (rank[raiz_x] < rank[raiz_y]) {
        pai[raiz_x] = raiz_y;
    } else {
        pai[raiz_y] = raiz_x;
        rank[raiz_x]++;
    }
}

// Função para comparar as arestas com base no peso
int comparar_arestas(const void *a, const void *b) {
    return ((Aresta *)a)->peso - ((Aresta *)b)->peso;
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n), m != 0 || n != 0) {
        Aresta arestas[n];
        int custo_total = 0;

        for (int i = 0; i < m; i++) {
            pai[i] = i;
            rank[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
            custo_total += arestas[i].peso;
        }

        // Ordena as arestas pelo peso
        qsort(arestas, n, sizeof(Aresta), comparar_arestas);

        int custo_mst = 0;
        int arestas_incluidas = 0;

        // Algoritmo de Kruskal
        for (int i = 0; i < n && arestas_incluidas < m - 1; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;
            if (encontrar(u) != encontrar(v)) {
                unir_conjuntos(u, v);
                custo_mst += arestas[i].peso;
                arestas_incluidas++;
            }
        }

        // A economia é o custo total das estradas menos o custo da MST
        printf("%d\n", custo_total - custo_mst);
    }
    return 0;
}
