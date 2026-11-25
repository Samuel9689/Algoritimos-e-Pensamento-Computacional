
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 4
#define MAX 100

typedef struct {
    char nome[50];
    int idade;
    long double id;
    float valores[MAX];
    float media;
} Participante;

// Calcular fatorial
long double fatorial(int n) {
    long double fat = 1;
    int i;

    for(i = 1; i <= n; i++) {
        fat *= i;
    }

    return fat;
}

// Verificar se o ID ja existe
int idExiste(Participante p[], int qtd, long double id) {
    int i;

    for(i = 0; i < qtd; i++) {
        if(p[i].id == id) {
            return 1;
        }
    }

    return 0;
}

// Calcular media ponderada
float mediaPonderada(float valores[], int qtd) {
    float soma = 0;
    int somaPesos = 0;
    int i;

    for(i = 0; i < qtd; i++) {
        int peso = i + 1;

        soma += valores[i] * peso;
        somaPesos += peso;
    }

    return soma / somaPesos;
}

int main() {

    Participante p[N];

    int i, j, qtd;
    int encontrados = 0;

    float lados[2];
    float diagonal;

    // Cadastro dos participantes
    for(i = 0; i < N; i++) {

        printf("\nNome do participante: ");
        scanf(" %49[^\n]", p[i].nome);

        do {
            printf("Idade (1 a 20): ");
            scanf("%d", &p[i].idade);

        } while(p[i].idade < 1 || p[i].idade > 20);

        // ID inicial
        p[i].id = fatorial(p[i].idade) / 2;
    }

    // Quantidade de valores
    do {
        printf("\nQuantidade de valores (1 a 100): ");
        scanf("%d", &qtd);

    } while(qtd < 1 || qtd > MAX);

    // Verificar IDs duplicados
    for(i = 0; i < N; i++) {

        if(idExiste(p, i, p[i].id)) {

            p[i].id = powl(
                fatorial(p[i].idade / 2), qtd
            );

            // Garantir ID exclusivo
            while(idExiste(p, i, p[i].id)) {
                p[i].id += 1;
            }
        }

        printf("\nID de %s: %.0Lf\n",
               p[i].nome, p[i].id);
    }

    // Captura dos valores
    for(i = 0; i < N; i++) {

        printf("\nValores de %s:\n", p[i].nome);

        for(j = 0; j < qtd; j++) {

            printf("Valor %d: ", j + 1);
            scanf("%f", &p[i].valores[j]);

            // Encontrar os dois primeiros valores nao negativos
            if(p[i].valores[j] >= 0 && encontrados < 2) {

                lados[encontrados] = p[i].valores[j];
                encontrados++;
            }
        }

        // Calcular media ponderada
        p[i].media = mediaPonderada(p[i].valores, qtd);
    }

    // Ordenar participantes por ordem alfabetica
    for(i = 0; i < N - 1; i++) {

        for(j = i + 1; j < N; j++) {

            if(strcmp(p[i].nome, p[j].nome) > 0) {

                Participante aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }

    // Calcular diagonal do retangulo
    if(encontrados == 2) {

        diagonal = sqrt(
            lados[0] * lados[0] +
            lados[1] * lados[1]
        );

        printf("\nDiagonal do retangulo: %.2f\n", diagonal);

    } else {

        printf("\nNao foi possivel calcular a diagonal.\n");
    }

    // Apresentar participantes e classificacoes
    printf("\n===== CLASSIFICACAO FINAL =====\n");

    for(i = 0; i < N; i++) {

        printf("\nNome: %s\n", p[i].nome);
        printf("ID: %.0Lf\n", p[i].id);

        printf("Media ponderada: %.2f\n", p[i].media);

        if(encontrados == 2) {

            if(p[i].media > diagonal) {

                printf("Classificacao: Acima da diagonal\n");

            } else if(p[i].media < diagonal) {

                printf("Classificacao: Abaixo da diagonal\n");

            } else {

                printf("Classificacao: Sobre a diagonal\n");
            }
        }
    }

    return 0;
}
