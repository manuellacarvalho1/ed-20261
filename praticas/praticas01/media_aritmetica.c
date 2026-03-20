#include <stdio.h>
#include <string.h>

int main() {

    int n;
    float numero, soma = 0, media;
    printf("Informe quantos números serão utilizados para o cálculo da média (máx. 100): ");
    scanf("%d", &n);
    
    if(n <= 0 || n >= 100) {
        printf("Quantidade de números inválida.");
    }

    for(int i = 1; i <= n; i++) {
        printf("Digite o número %d: ", i);
        scanf("%f", &numero);
        soma = soma + numero;
    }

    media = soma / n;
    printf("O resultado da média é: %.2f", media);
}