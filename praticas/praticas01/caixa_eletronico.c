#include <stdio.h>

int main() {

    int saque, notas;
    printf("Valor a ser sacado: ");
    scanf("%d", &saque);

    if(saque < 20 || saque > 1000) {
        printf("Entrada inválida. Insira um valor entre 20 e 1000 reais.");
    } 

    notas = saque / 200;
    saque = saque % 200;

    if(notas > 0) {
        printf("Qntd. notas de 200: %d\n", notas);
    }

    notas = saque / 100;
    saque = saque % 100;

    if(notas > 0) {
        printf("Qntd. notas de 100: %d\n", notas);
    }

    notas = saque / 50;
    saque = saque % 50;

    if(notas > 0) {
        printf("Qntd. notas de 50: %d\n", notas);
    }
    
    notas = saque / 20;
    saque = saque % 20;

    if(notas > 0) {
        printf("Qntd. notas de 20: %d\n", notas);
    }

    notas = saque / 10;
    saque = saque % 10;

    if(notas > 0) {
        printf("Qntd. notas de 10: %d\n", notas);
    }

    notas = saque / 5;
    saque = saque % 5;

    if(notas > 0) {
        printf("Qntd. notas de 5: %d\n", notas);
    }

    notas = saque / 2;
    saque = saque % 2;

    if(notas > 0) {
        printf("Qntd. notas de 2: %d\n", notas);
    }

}
