#include <stdio.h>

//complexidade assintótica: tempo = O(n), espaço = O(n)
int calcularFatorial(int n) {
    if (n <=1) {
        return 1;
    }
    return n * calcularFatorial(n - 1);
}

int main() {

    int num = 5;
    int res;

    res = calcularFatorial(num);

    printf("Fatorial de %d é = %d.\n", num, res);

    return 0;
}