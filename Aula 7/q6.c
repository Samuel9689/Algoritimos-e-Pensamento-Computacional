#include <stdio.h>

float somar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    return a / b;
}

int main() {

    float num1, num2;
    int opcao;

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    printf("\n1 - Adicao");
    printf("\n2 - Subtracao");
    printf("\n3 - Multiplicacao");
    printf("\n4 - Divisao");

    printf("\nEscolha uma operacao: ");
    scanf("%d", &opcao);

    switch (opcao) {

        case 1:
            printf("Resultado: %.2f", somar(num1, num2));
            break;

        case 2:
            printf("Resultado: %.2f", subtrair(num1, num2));
            break;

        case 3:
            printf("Resultado: %.2f", multiplicar(num1, num2));
            break;

        case 4:
            if (num2 != 0) {
                printf("Resultado: %.2f", dividir(num1, num2));
            } else {
                printf("Erro: divisao por zero!");
            }
            break;

        default:
            printf("Opcao invalida!");
    }

    return 0;
}