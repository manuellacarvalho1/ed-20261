#include <stdio.h>
#include <time.h>

int main() {
    int matriz[10][10];
    clock_t inicio, fim;
    double tempo_aninhado, tempo_unico;

    //1) dois laços aninhados
    printf("Exibindo com dois laços:\n");
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            matriz[i][j] = i + j;
        }
    }

    inicio = clock();
    for(int i = 0; i< 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    fim = clock();
    tempo_aninhado = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("\n--------------------------\n\n");

    //2) apenas um laço
    printf("Exibindo com apenas um laço:\n");
    int *ptr = &matriz[0][0];

    inicio = clock();
    for (int i = 0; i < 100; i++) {
        printf("%d ", ptr[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    fim = clock();
    tempo_unico = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo (dois laços): %f segundos\n", tempo_aninhado);
    printf("Tempo (um laço): %f segundos\n", tempo_unico);

    return 0;

}

//complexidade assintótica: ambas as soluções apresentam a mesma classe de complexidade (O(n²), 
//porém a perormance com um laço é levemente mais rápida devido à localidade de referência).