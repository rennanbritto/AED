#include <string.h>
#include <stdio.h>

int main() {
    char string[1001];
    int i, tam, parenteses;

    while (scanf("%s\n", &string) != EOF) {
        parenteses = 0;
        tam = strlen(string);

        for (i = 0; i < tam; ++i) {
            if (string[i] == '(') {
                ++parenteses;
            } else if (string[i] == ')') {
                if (parenteses > 0) {
                    --parenteses;
                } else {
                    break;
                }
            }
        }

        if (i == tam && parenteses == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
