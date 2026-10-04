#ifndef ARVORE_BINARY_H
#define ARVORE_BINARY_H

typedef struct arvore Arvore;

Arvore *arvore_criar();
int arvore_esta_vazia(Arvore *a);
int arvore_inserir(Arvore *a, int valor);
void arvore_exibir_pre_ordem(Arvore *a);
void arvore_exibir_em_ordem(Arvore *a);
void arvore_exibir_pos_ordem(Arvore *a); 
void arvore_destruir(Arvore *a);

#endif