#include <stdio.h>

int main() {
    int T, V[5], X = 0;
    
    scanf("%d", &T);

    for (int i = 0; i < 5; i++) {
        scanf("%d", &V[i]);
    }

    for (int i = 0; i < 5; i++) {
        if (V[i] == T) {
            X++;
        }
    }

    printf("%d\n", X);
    return 0;
}
