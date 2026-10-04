#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    printf("--- Testando o TDA arvore binaria ---\n\n");

    Arvore *minha_arvore = arvore_criar();

    printf("Inserindo elementos: 50, 30, 70, 20, 40, 60, 80\n\n");
    arvore_inserir(minha_arvore, 50);
    arvore_inserir(minha_arvore, 30);
    arvore_inserir(minha_arvore, 70);
    arvore_inserir(minha_arvore, 20);
    arvore_inserir(minha_arvore, 40);
    arvore_inserir(minha_arvore, 60);
    arvore_inserir(minha_arvore, 80);

    printf("Exibicao em Pre-ordem (Raiz-Esq-Dir):\n");
    arvore_exibir_pre_ordem(minha_arvore);

    printf("\nExibicao em Em-ordem (Esq-Raiz-Dir -> Ordenado):\n");
    arvore_exibir_em_ordem(minha_arvore);

    printf("\nExibicao em Pos-ordem (Esq-Dir-Raiz):\n");
    arvore_exibir_pos_ordem(minha_arvore);

    printf("\nDestruindo a arvore...\n");
    arvore_destruir(minha_arvore);
    printf("Concluido\n");

    return 0;
}