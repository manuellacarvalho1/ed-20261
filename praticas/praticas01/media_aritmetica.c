#include <stdio.h>
#include <string.h>

float calcular_media(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

int main() {
    float resultado;

    resultado = calcular_media(7.0f, 7.0f, 7.0f);
    printf("notas 7, 7, 7, media = %.1f => %i\n", resultado, resultado == 7.0f);

    resultado = calcular_media(5.0f, 8.0f, 11.0f);
    printf("notas 5, 8, 11, media = %.1f => %i\n", resultado, resultado == 8.0f);

    resultado = calcular_media(4.0f, 5.0f, 3.0f);
    printf("notas 4, 5, 3, media = %.1f => %i\n", resultado, resultado < 6.0f);

    return 0;
}