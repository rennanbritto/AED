#include <stdio.h>
#include <string.h>

void verifica_encaixe(char *a, char *b) {
    int tam_a = strlen(a);
    int tam_b = strlen(b);
    
    // Verifica se B é um sufixo de A
    if (tam_a >= tam_b && strcmp(a + (tam_a - tam_b), b) == 0) {
        printf("encaixa\n");
    } else {
        printf("nao encaixa\n");
    }
}

int main() {
    int n, i;
    char a[1001], b[1001];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%s %s", a, b);
        verifica_encaixe(a, b);
    }
    
    return 0;
}
