#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

#define TAMANHO_PADRAO 10


typedef struct no {
    int valor;
    struct no *proximo;
} no_t;

struct hash {
    no_t **tabela; 
    int tamanho;
};

int funcao_hash(int valor, int tamanho) {
    int pos = valor % tamanho;
    if (pos < 0) pos += tamanho; 
    return pos;
}

TabelaHash *hash_criar() {
    TabelaHash *h = (TabelaHash*) malloc(sizeof(TabelaHash));
    if (h == NULL) return NULL;
    
    h->tamanho = TAMANHO_PADRAO;
    h->tabela = (no_t**) malloc(h->tamanho * sizeof(no_t*));
    
    if (h->tabela == NULL) {
        free(h);
        return NULL;
    }
    
    for (int i = 0; i < h->tamanho; i++) {
        h->tabela[i] = NULL;
    }
    
    return h;
}

int hash_esta_vazia(TabelaHash *h) {
    if (h == NULL || h->tabela == NULL) return 1;
    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) return 0; 
    }
    return 1;
}

int hash_inserir(TabelaHash *h, int valor) {
    if (h == NULL) return 0;
    
    if (hash_buscar(h, valor)) return 0;

    int pos = funcao_hash(valor, h->tamanho);
    
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;
    
    novo->valor = valor;
    novo->proximo = h->tabela[pos]; 
    h->tabela[pos] = novo;          
    
    return 1;
}

int hash_buscar(TabelaHash *h, int valor) {
    if (h == NULL || hash_esta_vazia(h)) return 0;
    
    int pos = funcao_hash(valor, h->tamanho);
    no_t *atual = h->tabela[pos];
    
    while (atual != NULL) {
        if (atual->valor == valor) return 1;
        atual = atual->proximo;
    }
    return 0;
}

int hash_remover(TabelaHash *h, int valor) {
    if (h == NULL || hash_esta_vazia(h)) return 0;
    
    int pos = funcao_hash(valor, h->tamanho);
    no_t *atual = h->tabela[pos];
    no_t *anterior = NULL;
    
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL) return 0; 
    
    if (anterior == NULL) {
        h->tabela[pos] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    
    free(atual);
    return 1;
}

void hash_exibir(TabelaHash *h) {
    if (h == NULL) return;
    
    printf("--- Estado da Tabela Hash ---\n");
    for (int i = 0; i < h->tamanho; i++) {
        printf("Posicao [%d]: ", i);
        no_t *atual = h->tabela[i];
        if (atual == NULL) {
            printf("NULL\n");
        } else {
            while (atual != NULL) {
                printf("[%d] -> ", atual->valor);
                atual = atual->proximo;
            }
            printf("NULL\n");
        }
    }
    printf("-----------------------------\n");
}

void hash_destruir(TabelaHash *h) {
    if (h == NULL) return;
    
    for (int i = 0; i < h->tamanho; i++) {
        no_t *atual = h->tabela[i];
        while (atual != NULL) {
            no_t *aux = atual->proximo;
            free(atual);
            atual = aux;
        }
    }
    free(h->tabela);
    free(h);
}