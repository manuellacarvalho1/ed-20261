#include <stdio.h>

int main() {

    int num = 5;
    int fatorial = 1; 

    //complexidade assintótica: tempo = O(n), espaço = O(1)
    for(int i = 1; i <= num; i++) {
     fatorial = fatorial * i;
    }

    printf("Fatorial de %d é = %d.\n", num, fatorial);

    return 0;
}
