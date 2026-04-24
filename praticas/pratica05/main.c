#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "selecao.h"

void preencher_aleatorio(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 1000;
    }
}

int main() {
    int n = 100;
    int k = 10; 
    int vetor[n], copia[n];
    srand(time(NULL));

    preencher_aleatorio(vetor, n);
    
    memcpy(copia, vetor, n * sizeof(int));
    clock_t inicio = clock();
    int res1 = linear_search(copia, n, k);
    clock_t fim = clock();
    printf("Linear Search: Elemento na pos %d e %d (Tempo: %f)\n", k, res1, (double)(fim - inicio) / CLOCKS_PER_SEC);

    memcpy(copia, vetor, n * sizeof(int));
    inicio = clock();
    int res2 = quick_select(copia, n, k);
    fim = clock();
    printf("Quick Select:  Elemento na pos %d e %d (Tempo: %f)\n", k, res2, (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}