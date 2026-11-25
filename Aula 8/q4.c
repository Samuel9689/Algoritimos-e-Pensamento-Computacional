
#include <stdio.h>
#include <string.h>

#define N 5

long long fibonacci(int n) {
    long long a = 0, b = 1, soma = 0, temp;
    int i;

    for(i = 0; i < n; i++) {
        soma += a;

        temp = a + b;
        a = b;
        b = temp;
    }

    return soma;
}

int primo(long long n) {
    long long i;

    if(n < 2)
        return 0;

    for(i = 2; i <= n / i; i++) {
        if(n % i == 0)
            return 0;
    }

    return 1;
}

int main() {
    char nomes[N][50];
    long long resultados[N];
    int numeros[N];
    int premiado[N] = {0};

    int i;
    int primeiro = -1;
    int segundo = -1;
    int terceiro = -1;

    long long maior;
    double media, soma = 0;

    // Cadastro
    for(i = 0; i < N; i++) {
        printf("\nNome do apostador: ");
        scanf(" %49[^\n]", nomes[i]);

        do {
            printf("Digite um numero positivo (ate 90): ");
            scanf("%d", &numeros[i]);
        } while(numeros[i] < 1 || numeros[i] > 90);

        resultados[i] = fibonacci(numeros[i]);

        soma += resultados[i];
    }

    // Calcular media
    media = soma / N;

    // Primeiro lugar: maior resultado primo
    maior = -1;

    for(i = 0; i < N; i++) {
        if(primo(resultados[i]) && resultados[i] > maior) {
            maior = resultados[i];
            primeiro = i;
        }
    }

    if(primeiro != -1)
        premiado[primeiro] = 1;

    // Segundo lugar: maior resultado par
    maior = -1;

    for(i = 0; i < N; i++) {
        if(!premiado[i] &&
           resultados[i] % 2 == 0 &&
           resultados[i] > maior) {

            maior = resultados[i];
            segundo = i;
        }
    }

    if(segundo != -1)
        premiado[segundo] = 1;

    // Terceiro lugar: maior resultado acima da media
    maior = -1;

    for(i = 0; i < N; i++) {
        if(!premiado[i] &&
           resultados[i] > media &&
           resultados[i] > maior) {

            maior = resultados[i];
            terceiro = i;
        }
    }

    // Mostrar vencedores
    printf("\n===== RESULTADO FINAL =====\n");

    if(primeiro != -1)
        printf("1 lugar: %s\n", nomes[primeiro]);
    else
        printf("1 lugar: Sem vencedor\n");

    if(segundo != -1)
        printf("2 lugar: %s\n", nomes[segundo]);
    else
        printf("2 lugar: Sem vencedor\n");

    if(terceiro != -1)
        printf("3 lugar: %s\n", nomes[terceiro]);
    else
        printf("3 lugar: Sem vencedor\n");

    return 0;
}
