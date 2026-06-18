#include <stdio.h>


float calcular_imc(float altura, float peso) {
        if(altura <= 0) return 0;
        return peso / (altura * altura);
    }

    int main() {
        float imc;
        
        imc = calcular_imc(1.75f, 0.0f);
        printf("altura = 1.75, peso = 0, imc = %.1f => %i\n", imc, imc == 0);

        imc = calcular_imc(1.75f, 50.0f);
        printf("altura = 1.75, peso = 50, imc = %.1f => %i\n", imc, imc < 18.5f);

        imc = calcular_imc(1.75f, 65.0f);
        printf("altura = 1.75, peso = 65, imc = %.1f => %i\n", imc, imc >= 18.5f && imc < 24.9f);

        return 0;
        
        }
    