#include <stdio.h>

void processar_respostas() {
    while (1) {
        int n;
        scanf("%d", &n);
        
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            int cinzas[5];
            for (int j = 0; j < 5; j++) {
                scanf("%d", &cinzas[j]);
            }
            
            // Contar quantas alternativas estão "marcadas"
            int marcadas = 0;
            int indice_marcado = -1;
            for (int j = 0; j < 5; j++) {
                if (cinzas[j] <= 127) {
                    marcadas++;
                    indice_marcado = j;
                }
            }
            
            if (marcadas == 1) {
                if (indice_marcado == 0) {
                    printf("A\n");
                } else if (indice_marcado == 1) {
                    printf("B\n");
                } else if (indice_marcado == 2) {
                    printf("C\n");
                } else if (indice_marcado == 3) {
                    printf("D\n");
                } else if (indice_marcado == 4) {
                    printf("E\n");
                }
            } else {
                // Se nenhuma ou mais de uma alternativa estiver marcada, imprimir "*"
                printf("*\n");
            }
        }
    }
}

int main() {
    processar_respostas();
    return 0;
}
