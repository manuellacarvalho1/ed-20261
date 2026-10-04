#include <stdio.h>
#include "tabela_hash.h"

int main() {
    printf("--- Testando o TDA tabela hash ---\n\n");
    
    TabelaHash *minha_tabela = hash_criar();
    
    printf("Inserindo elementos: 5, 12, 22, 35, 42\n\n");
    hash_inserir(minha_tabela, 5);
    hash_inserir(minha_tabela, 12);
    hash_inserir(minha_tabela, 22);
    hash_inserir(minha_tabela, 35);
    hash_inserir(minha_tabela, 42);
    
    hash_exibir(minha_tabela);
    
    printf("\nBuscando pelo valor 22: %s\n", hash_buscar(minha_tabela, 22) ? "Encontrado!" : "Nao encontrado.");
    printf("Buscando pelo valor 99: %s\n", hash_buscar(minha_tabela, 99) ? "Encontrado!" : "Nao encontrado.");
    
    printf("\nRemovendo o valor 22...\n\n");
    hash_remover(minha_tabela, 22);
    
    hash_exibir(minha_tabela);
    
    printf("\nDestruindo a tabela hash...\n");
    hash_destruir(minha_tabela);
    printf("Concluido\n");
    
    return 0;
}