#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int N, ano, mes, dia;
      scanf("%d", &N);
   
      ano = N/365;
      mes = (N%365)/30;
      dia = ((N%365)%30);
   
      printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dia);
   
      return 0;
}
