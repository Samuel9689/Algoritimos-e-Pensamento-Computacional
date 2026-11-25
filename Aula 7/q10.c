#include <stdio.h>

float calcularTotal(float vendas[]) {

    float total = 0;

    for (int i = 0; i < 5; i++) {
        total += vendas[i];
    }

    return total;
}

float calcularMedia(float total, int quantidade) {

    return total / quantidade;

}

int contarVendasAcimaDaMedia(float vendas[], float media) {

    int contador = 0;

    for (int i = 0; i < 5; i++) {

        if (vendas[i] > media) {
            contador++;
        }

    }

    return contador;
}

int main() {

    float vendas[5];
    float total, media;
    int quantidade;

    quantidade = 5;

    for (int i = 0; i < 5; i++) {

        printf("Digite a venda do dia %d: ", i + 1);
        scanf("%f", &vendas[i]);

    }

    total = calcularTotal(vendas);

    media = calcularMedia(total, quantidade);

    printf("\nTotal vendido: R$ %.2f\n", total);

    printf("Media diaria: R$ %.2f\n", media);

    printf("Dias acima da media: %d\n",
    contarVendasAcimaDaMedia(vendas, media));

    return 0;
}