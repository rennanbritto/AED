#include <stdio.h>
#include <string.h>

int calcular_leds(char digito) {
    switch (digito) {
        case '0': return 6;
        case '1': return 2;
        case '2': return 5;
        case '3': return 5;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 3;
        case '8': return 7;
        case '9': return 6;
        default: return 0;
    }
}

int main() {
    int n, i, j, total_leds;
    char numero[102]; // Até 100 dígitos + \0

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", numero);
        total_leds = 0;
        
        // Percorre cada dígito do número e soma a quantidade de LEDs
        for (j = 0; j < strlen(numero); j++) {
            total_leds += calcular_leds(numero[j]);
        }
        
        printf("%d leds\n", total_leds);
    }
    
    return 0;
}
