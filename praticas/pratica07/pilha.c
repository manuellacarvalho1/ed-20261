#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    int valor;
    struct no *proximo;
} no_t;

struct pilha {
    no_t *topo;
};

Pilha *pilha_criar() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

int pilha_esta_vazia(Pilha *p) {
    if (p == NULL) return 1;
    return (p->topo == NULL);
}

int pilha_empilhar(Pilha *p, int valor) {
    if (p == NULL) return 0;
    
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;
    
    novo->valor = valor;
    novo->proximo = p->topo; 
    p->topo = novo;          
    
    return 1;
}

int pilha_desempilhar(Pilha *p, int *valor) {
    if (p == NULL || pilha_esta_vazia(p)) return 0;
    
    no_t *aux = p->topo;
    *valor = aux->valor;     
    p->topo = aux->proximo; 
    free(aux);
    
    return 1;
}

int pilha_topo(Pilha *p, int *valor) {
    if (p == NULL || pilha_esta_vazia(p)) return 0;
    *valor = p->topo->valor;
    return 1;
}


void pilha_exibir(Pilha *p) {
    if (p == NULL || pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    
    no_t *atual = p->topo;
    printf("Pilha (Topo -> Base):\n");
    while (atual != NULL) {
        printf(" [%d]\n  v\n", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}


void pilha_destruir(Pilha *p) {
    if (p == NULL) return;
    
    no_t *atual = p->topo;
    while (atual != NULL) {
        no_t *aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    free(p);
}