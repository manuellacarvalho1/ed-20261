#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

Pilha *pilha_criar();
int pilha_empilhar(Pilha *p, int valor);
int pilha_desempilhar(Pilha *p, int *valor); 
int pilha_topo(Pilha *p, int *valor);        
int pilha_esta_vazia(Pilha *p);
void pilha_exibir(Pilha *p);
void pilha_destruir(Pilha *p);

#endif