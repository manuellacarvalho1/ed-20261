#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ordenacao.h"

void preencher_aleatorio(int *v, int n) {
    for (int i = 0; i < n; i++) v[i] = rand() % 1000;
}

void medir_tempo(void (*algoritmo)(int*, int), int *v, int n, char *nome) {
    int *copia = malloc(n * sizeof(int));
    memcpy(copia, v, n * sizeof(int));

    clock_t inicio = clock();
    algoritmo(copia, n);
    clock_t fim = clock();

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("%s: %f segundos\n", nome, tempo);
    free(copia);
}

int main() {
    int n = 100;
    int vetor[n];
    srand(time(NULL));

    preencher_aleatorio(vetor, n);

    printf("Comparando algoritmos para n = %d:\n", n);
    medir_tempo(bubble_sort, vetor, n, "Bubble Sort");
    medir_tempo(selection_sort, vetor, n, "Selection Sort");
    medir_tempo(quick_sort, vetor, n, "Quick Sort");

    return 0;
}