#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no {

    int valor;
    struct no *anterior;
    struct no *proximo;
} no_t;

struct lista {
    no_t *primeiro;
    no_t *ultimo;
};

Lista *lista_criar() {
    Lista *nova = (Lista*) malloc(sizeof(Lista));
    if (nova != NULL) {
        nova->primeiro = NULL;
        nova->ultimo = NULL;
    }
    return nova;
}

int lista_esta_vazia(Lista *l) {
    if (l == NULL) return 1;
    return (l->primeiro == NULL);
}

int lista_inserir(Lista *l, int valor) {
    if (l == NULL) return 0;
    
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;
    
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;
    
    if (lista_esta_vazia(l)) {
        l->primeiro = novo;
        l->ultimo = novo;
    } else {
        l->ultimo->proximo = novo;
        novo->anterior = l->ultimo;
        l->ultimo = novo;
    }
    return 1;
}

int lista_buscar(Lista *l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return 0;
    
    no_t *atual = l->primeiro;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; 
        }
        atual = atual->proximo;
    }
    return 0; 
}

int lista_remover(Lista *l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return 0;
    
    no_t *atual = l->primeiro;
    
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }
    
    if (atual == NULL) return 0;
    
    if (atual == l->primeiro) { 
        l->primeiro = atual->proximo;
        if (l->primeiro != NULL) {
            l->primeiro->anterior = NULL;
        } else {
            l->ultimo = NULL; 
        }
    } else if (atual == l->ultimo) { 
        l->ultimo = atual->anterior;
        l->ultimo->proximo = NULL;
    } else {
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }
    
    free(atual);
    return 1;
}

void lista_exibir(Lista *l) {
    if (l == NULL || lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
    
    no_t *atual = l->primeiro;
    printf("Lista: ");
    while (atual != NULL) {
        printf("[%d] <-> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void lista_destruir(Lista *l) {
    if (l == NULL) return;
    
    no_t *atual = l->primeiro;
    while (atual != NULL) {
        no_t *aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    free(l);
}