#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} no_t;

struct arvore {
    no_t *raiz;
};

Arvore *arvore_criar() {
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    if (a != NULL) {
        a->raiz = NULL;
    }
    return a;
}

int arvore_esta_vazia(Arvore *a) {
    if (a == NULL) return 1;
    return (a->raiz == NULL);
}

no_t *inserir_recursivo(no_t *raiz, int valor, int *sucesso) {
    if (raiz == NULL) {
        no_t *novo = (no_t*) malloc(sizeof(no_t));
        if (novo != NULL) {
            novo->valor = valor;
            novo->esquerda = NULL;
            novo->direita = NULL;
            *sucesso = 1;
        }
        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_recursivo(raiz->esquerda, valor, sucesso);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_recursivo(raiz->direita, valor, sucesso);
    } else {
        *sucesso = 0; 
    }
    return raiz;
}

int arvore_inserir(Arvore *a, int valor) {
    if (a == NULL) return 0;
    int sucesso = 0;
    a->raiz = inserir_recursivo(a->raiz, valor, &sucesso);
    return sucesso;
}

void pre_ordem(no_t *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(no_t *raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(no_t *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void arvore_exibir_pre_ordem(Arvore *a) {
    if (a == NULL || arvore_esta_vazia(a)) {
        printf("Arvore vazia.");
    } else {
        pre_ordem(a->raiz);
    }
    printf("\n");
}

void arvore_exibir_em_ordem(Arvore *a) {
    if (a == NULL || arvore_esta_vazia(a)) {
        printf("Arvore vazia.");
    } else {
        em_ordem(a->raiz);
    }
    printf("\n");
}

void arvore_exibir_pos_ordem(Arvore *a) {
    if (a == NULL || arvore_esta_vazia(a)) {
        printf("Arvore vazia.");
    } else {
        pos_ordem(a->raiz);
    }
    printf("\n");
}

void destruir_recursivo(no_t *raiz) {
    if (raiz != NULL) {
        destruir_recursivo(raiz->esquerda);
        destruir_recursivo(raiz->direita);
        free(raiz);
    }
}

void arvore_destruir(Arvore *a) {
    if (a == NULL) return;
    destruir_recursivo(a->raiz);
    free(a);
}