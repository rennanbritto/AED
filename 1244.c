#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 50
#define MAX_TAMANHO 50

// Função para ordenar as strings por tamanho e manter a ordem original
void ordenar_strings(char palavras[MAX_STRINGS][MAX_TAMANHO + 1], int quantidade) {
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (strlen(palavras[j]) > strlen(palavras[j + 1])) {
                char temp[MAX_TAMANHO + 1];
                strcpy(temp, palavras[j]);
                strcpy(palavras[j], palavras[j + 1]);
                strcpy(palavras[j + 1], temp);
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // Consumir o \n após o número de casos
    
    while (N--) {
        char palavras[MAX_STRINGS][MAX_TAMANHO + 1];
        int count = 0;
        
        char linha[MAX_STRINGS * (MAX_TAMANHO + 1)];
        fgets(linha, sizeof(linha), stdin);
        
        char *token = strtok(linha, " \n");
        while (token && count < MAX_STRINGS) {
            strcpy(palavras[count], token);
            count++;
            token = strtok(NULL, " \n");
        }
        
        ordenar_strings(palavras, count);
        
        for (int i = 0; i < count; i++) {
            if (i > 0) printf(" ");
            printf("%s", palavras[i]);
        }
        printf("\n");
    }
    
    return 0;
}
