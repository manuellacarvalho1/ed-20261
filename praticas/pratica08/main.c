#include <stdio.h>
#include "fila.h"

int main() {
    printf("--- Testando o TDA fila ---\n\n");
    
    Fila *minha_fila = fila_criar();
    
    printf("Enfileirando: 10, 20, 30\n");
    fila_enfileirar(minha_fila, 10);
    fila_enfileirar(minha_fila, 20);
    fila_enfileirar(minha_fila, 30);
    
    lista_exibir(minha_fila);
    
    int valor_inicio;
    if (fila_inicio(minha_fila, &valor_inicio)) {
        printf("Elemento no inicio atual: %d\n\n", valor_inicio);
    }
    
    int valor_removido;
    if (fila_desenfileirar(minha_fila, &valor_removido)) {
        printf("Desenfileirado (Saiu primeiro): %d\n", valor_removido);
    }
    
    lista_exibir(minha_fila);
    
    printf("\nDestruindo a fila...\n");
    fila_destruir(minha_fila);
    printf("Concluido\n");
    
    return 0;
}