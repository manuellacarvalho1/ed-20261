#include <stdio.h>
#include "pilha.h"

int main() {
    printf("--- Testando o TDA pilha ---\n\n");
    
    Pilha *minha_pilha = pilha_criar();
    
    printf("Empilhando: 10, 20, 30\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    
    pilha_exibir(minha_pilha);
    
    int valor_topo;
    if (pilha_topo(minha_pilha, &valor_topo)) {
        printf("Elemento no topo atual: %d\n\n", valor_topo);
    }
    
    int valor_removido;
    if (pilha_desempilhar(minha_pilha, &valor_removido)) {
        printf("Desempilhado: %d\n", valor_removido);
    }
    
    pilha_exibir(minha_pilha);
    
    printf("Destruindo a pilha...\n");
    pilha_destruir(minha_pilha);
    printf("Concluido\n");
    
    return 0;
}