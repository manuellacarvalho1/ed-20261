#include <stdio.h>
#include "lista_linear.h"

int main() {
    printf("--- Testando o TDA lista linear ---\n\n");
    
    Lista *minha_lista = lista_criar();
    
    if (lista_esta_vazia(minha_lista)) {
        printf("Confirmado: A lista foi criada e esta vazia.\n");
    }
    
    printf("\nInserindo elementos: 10, 20, 30, 40\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_inserir(minha_lista, 40);
    
    lista_exibir(minha_lista);
    
    printf("\nBuscando pelo valor 30: %s\n", lista_buscar(minha_lista, 30) ? "Encontrado!" : "Nao encontrado.");
    printf("Buscando pelo valor 99: %s\n", lista_buscar(minha_lista, 99) ? "Encontrado!" : "Nao encontrado.");
    
    printf("\nRemovendo os valores 20 e 40...\n");
    lista_remover(minha_lista, 20);
    lista_remover(minha_lista, 40);
    
    lista_exibir(minha_lista);
    
    printf("\nDestruindo a lista...\n");
    lista_destruir(minha_lista);
    printf("Concluido com sucesso!\n");
    
    return 0;
}