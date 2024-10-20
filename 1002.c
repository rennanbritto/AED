#include <stdio.h>
 
int main() {
    
    double raio = 0; 
    double area = 0;
    double pi = 3.14159;
    
    scanf("%lf", &raio);
 
    area = (raio*raio) * pi;
    
    printf("A=%.4f\n", area);
    
    return 0;
}
