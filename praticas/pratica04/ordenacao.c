#include "ordenacao.h"
#include <stdlib.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(&v[j], &v[j + 1]);
            }
        }
    }
}

void selection_sort(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        troca(&v[i], &v[min]);
    }
}

void quick_sort_recursivo(int *v, int esq, int dir) {
    if (esq >= dir) {
        return;
    }
    
    int pivo = v[(esq + dir) / 2];
    int i = esq, j = dir;
    
    while (i <= j) {
        while (v[i] < pivo) {
            i++;
        }
        while (v[j] > pivo) {
            j--;
        }
        if (i <= j) {
            troca(&v[i], &v[j]);
            i++; 
            j--;
        }
    }
    
    quick_sort_recursivo(v, esq, j);
    quick_sort_recursivo(v, i, dir);
}

void quick_sort(int *v, int n) {
    quick_sort_recursivo(v, 0, n - 1);
}