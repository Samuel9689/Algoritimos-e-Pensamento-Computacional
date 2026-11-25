#include <stdio.h>

int ehPrimo(int numero) {

    if (numero < 2) {
        return 0;
    }

    for (int i = 2; i <= numero / i; i++) {

        if (numero % i == 0) {
            return 0;
        }

    }

    return 1;
}

int main() {

    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (ehPrimo(numero) == 1) {
        printf("O numero e primo!\n");
    } else {
        printf("O numero nao e primo!\n");
    }

    return 0;
}