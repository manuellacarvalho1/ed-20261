#include <stdio.h>

int calcular_potencia(int base, int expoente) {
    int res = 1;
    for (int i = 1; i <= expoente; i++) {
        res = res * base;
    }
    return res;
}

int main() {
    
    int resultado;

    resultado = calcular_potencia(2, 3);
    printf("base 2, expoente 3, resultado = %d => %i\n", resultado, resultado == 8);

    resultado = calcular_potencia(5, 2);
    printf("base 5, expoente 2, resultado = %d => %i\n", resultado, resultado == 25);
    
    resultado = calcular_potencia(10, 0);
    printf("base 10, expoente 0, resultado = %d => %i\n", resultado, resultado == 1);

    return 0;
}