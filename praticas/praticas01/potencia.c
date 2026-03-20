#include <stdio.h>

int main () {

    int base = 4;
    int potencia = 5;
    int res = 1;

    printf("Calculadora de potência\n");

    for(int i = 1; i <= potencia; i++) 
    {
       res = res * base;
    }
    printf("Resultado de %d elevado a %d: %d\n", base, potencia, res); 
}