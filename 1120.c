#include <stdio.h>
#include <string.h>

int main() {
    int D;
    char N[101];

    while (1) {
        scanf("%d %s", &D, N);
        if (D == 0 && strcmp(N, "0") == 0) {
            break;
        }

        char resultado[101];
        char digito = D + '0'; 
        int pos = 0;

        // Percorre a string original para tirar o dígito desejado
        for (int i = 0; N[i] != '\0'; i++) {
            if (N[i] != digito) {
                resultado[pos++] = N[i];
            }
        }
        resultado[pos] = '\0';

        // Remover zeros à esquerda
        int inicio = 0;
        while (resultado[inicio] == '0') {
            inicio++;
        }

        // Verifica se a string está vazia após remover zeros
        if (resultado[inicio] == '\0') {
            printf("0\n");
        } else {
            printf("%s\n", resultado + inicio);
        }
    }
    return 0;
}
