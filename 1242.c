#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 301  // Define o tamanho máximo da string

int calcular_ligacoes(char *fita) {
    int cont = 0;
    char pilha[MAX];  // Pilha para armazenar as bases
    int topo = -1;  // Índice do topo da pilha
    char resp[MAX];  // Resposta para pares correspondentes

    // Gerar a sequência de bases correspondentes
    for (int i = 0; fita[i] != '\0'; i++) {
        if (fita[i] == 'S')
            resp[i] = 'B';
        else if (fita[i] == 'B')
            resp[i] = 'S';
        else if (fita[i] == 'C')
            resp[i] = 'F';
        else if (fita[i] == 'F')
            resp[i] = 'C';
    }

    // Processar as bases e contar as ligações
    for (int i = 0; fita[i] != '\0'; i++) {
        // Se a pilha está vazia ou o topo da pilha não corresponde à base que procuramos
        if (topo == -1 || pilha[topo] != resp[i]) {
            pilha[++topo] = fita[i];  // Empilha a base atual
        } else {
            cont++;
            topo--;  // Desempilha o topo da pilha
        }
    }

    return cont;
}

int main() {
    char fita[MAX];
  
    while (scanf("%s", fita) != EOF) {
        int resultado = calcular_ligacoes(fita);
        printf("%d\n", resultado);  
    }
    return 0;
}
