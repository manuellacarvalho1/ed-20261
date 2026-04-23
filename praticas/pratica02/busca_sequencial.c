#include <stdio.h>


int main () {

    int vetor[100];
    int alvo;

    for (int i = 0; i < 100; i++) {
        vetor[i] = i + 1; 
    }

    printf("Digite o valor escolhido para buscar no vetor: ");
    scanf("%d", &alvo);

    int i =0;
    while(i < 100 && vetor[i] != alvo){
        i++;
    }

    if (i < 100) {
            printf("Valor encontrado no indice %d.\n", i);
        } else {
            printf("O valor não foi encontrado.\n");
        }

        return 0;
}

// complexidade assintótica: melhor caso = O(1), pior caso = O(n)