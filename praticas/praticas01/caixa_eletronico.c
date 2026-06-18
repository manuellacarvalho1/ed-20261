#include <stdio.h>

  int calcular_notas(int *saque, int valor_nota) {
    int qtd = *saque / valor_nota;
    *saque = *saque % valor_nota;
    return qtd;
}

int main() {
    int valor_teste, qtd;

    valor_teste = 647;
    
    qtd = calcular_notas(&valor_teste, 200); 
    printf("Saque: 647\n notas de 200: %d => %i\n", qtd, qtd == 3);
    
    qtd = calcular_notas(&valor_teste, 100); 
    printf("notas de 100: %d => %i\n", qtd, qtd == 0);
    
    qtd = calcular_notas(&valor_teste, 50);  
    printf("notas de 50: %d => %i\n", qtd, qtd == 0);

    qtd = calcular_notas(&valor_teste, 20);  
    printf("notas de 20: %d => %i\n", qtd, qtd == 2);

    qtd = calcular_notas(&valor_teste, 10);
    printf("Notas de 10:  %d => %i\n", qtd, qtd == 0); 

    qtd = calcular_notas(&valor_teste, 5);
    printf("Notas de 5:   %d => %i\n", qtd, qtd == 1); 

    qtd = calcular_notas(&valor_teste, 2);
    printf("Notas de 2:   %d => %i\n", qtd, qtd == 1);
    
    return 0;
}
