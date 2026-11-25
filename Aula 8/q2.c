
#include <stdio.h>

int main() {
    int vet[10];
    int positivos[10], negativos[10];
    int qtdPos = 0, qtdNeg = 0;
    int i, j, temp;

    printf("Digite 10 numeros:\n");

    for(i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);

        if(vet[i] > 0 && vet[i] % 2 == 0) {
            positivos[qtdPos] = vet[i];
            qtdPos++;
        }

        if(vet[i] < 0 && vet[i] % 2 != 0) {
            negativos[qtdNeg] = vet[i];
            qtdNeg++;
        }
    }

    // Ordenar positivos pares
    for(i = 0; i < qtdPos - 1; i++) {
        for(j = i + 1; j < qtdPos; j++) {
            if(positivos[i] > positivos[j]) {
                temp = positivos[i];
                positivos[i] = positivos[j];
                positivos[j] = temp;
            }
        }
    }

    // Ordenar negativos impares
    for(i = 0; i < qtdNeg - 1; i++) {
        for(j = i + 1; j < qtdNeg; j++) {
            if(negativos[i] > negativos[j]) {
                temp = negativos[i];
                negativos[i] = negativos[j];
                negativos[j] = temp;
            }
        }
    }

    printf("\nPositivos e pares:\n");

    for(i = 0; i < qtdPos; i++) {
        printf("%d ", positivos[i]);
    }

    printf("\n\nNegativos e impares:\n");

    for(i = 0; i < qtdNeg; i++) {
        printf("%d ", negativos[i]);
    }

    return 0;
}
