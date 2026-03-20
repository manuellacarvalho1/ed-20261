#include <stdio.h>
int main() {

    float peso, altura;
    printf("Digite o peso (em kg): ");
    scanf("%d", &peso);
    printf("Digite a sua altura (em m): ");
    scanf("%d", &altura);

    float imc = peso / (altura * altura);

    float abaixo = imc < 18.5;
    float normal = imc >= 18.5 && imc <= 24.9;
    float sobrepeso = imc >= 25.0 && imc <= 29.9;
    
    if (peso < 0) {
        printf("Não é permitido valores negativos.\n");
    }

    else if (abaixo) {
        printf("Você está abaixo do peso.\n");
    } else if (normal) {
        printf("Você está no peso normal.\n");
    } else if (sobrepeso) {
        printf("Você está acima do peso.\n");   
    } else {
        printf("Você está em nível de obesidade.\n");
    }
}