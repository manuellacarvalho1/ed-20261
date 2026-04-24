#include "selecao.h"
#include <stdlib.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int linear_search(int *v, int n, int k) {
    for (int i = 0; i <= k; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        troca(&v[i], &v[min]);
    }
    return v[k];
}

int particiona(int *v, int esq, int dir) {
    int pivo = v[dir];
    int i = esq;
    for (int j = esq; j < dir; j++) {
        if (v[j] <= pivo) {
            troca(&v[i], &v[j]);
            i++;
        }
    }
    troca(&v[i], &v[dir]);
    return i;
}

int quick_select_recursivo(int *v, int esq, int dir, int k) {
    if (esq == dir) {
        return v[esq];
    }
    
    int indice_pivo = particiona(v, esq, dir);
    
    if (k == indice_pivo) {
        return v[k];
    } else if (k < indice_pivo) {
        return quick_select_recursivo(v, esq, indice_pivo - 1, k);
    } else {
        return quick_select_recursivo(v, indice_pivo + 1, dir, k);
    }
}

int quick_select(int *v, int n, int k) {
    if (k >= 0 && k < n) {
        return quick_select_recursivo(v, 0, n - 1, k);
    }
    return -1;
}