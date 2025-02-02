#include <stdio.h>
#include <ctype.h>
#include <string.h>

void transformar_dancante(char *sentenca) {
    int i, maiuscula = 1; // Começa com a primeira maiúscula
    for (i = 0; sentenca[i] != '\0'; i++) {
        if (isalpha(sentenca[i])) { // Vê se é letra
            if (maiuscula) {
                sentenca[i] = toupper(sentenca[i]);
            } else {
                sentenca[i] = tolower(sentenca[i]);
            }
            maiuscula = !maiuscula; // Alterna entre maiúscula e minúscula
        }
    }
}

int main() {
    char sentenca[51];
    
    while (fgets(sentenca, sizeof(sentenca), stdin)) {
        transformar_dancante(sentenca);
        printf("%s", sentenca);
    }
    
    return 0;
}
