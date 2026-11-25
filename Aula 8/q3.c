
#include <stdio.h>
#include <string.h>

int primo(int n) {
    int i;

    if(n < 2)
        return 0;

    for(i = 2; i <= n / i; i++) {
        if(n % i == 0)
            return 0;
    }

    return 1;
}

int main() {
    int vet[15];
    int visitado[15] = {0};
    int i, j, cont, soma;
    int totalAnimais = 0;

    char animais[500][50];

    printf("Digite 15 numeros:\n");

    for(i = 0; i < 15; i++) {
        scanf("%d", &vet[i]);
    }

    // Identificar numeros distintos
    for(i = 0; i < 15; i++) {

        if(visitado[i])
            continue;

        cont = 0;

        for(j = 0; j < 15; j++) {
            if(vet[i] == vet[j]) {
                cont++;
                visitado[j] = 1;
            }
        }

        if(cont > 1) {
            printf("\nNumero %d aparece %d vezes.\n",
                   vet[i], cont);
        }

        // Primo com ocorrencia impar
        if(primo(vet[i]) && cont % 2 != 0) {

            soma = vet[i] * cont;

            if(soma > 500 - totalAnimais) {
                printf("Quantidade de animais excede o limite.\n");
                return 1;
            }

            printf("Cadastre %d animais:\n", soma);

            for(j = 0; j < soma; j++) {
                printf("Animal %d: ", totalAnimais + 1);
                scanf(" %49[^\n]", animais[totalAnimais]);
                totalAnimais++;
            }
        }
    }

    // Correspondencia dos numeros com frequencia par
    printf("\nCorrespondencias:\n");

    for(i = 0; i < 15; i++) {

        if(visitado[i] == 0)
            continue;

        // Somente primeira ocorrencia
        int primeira = 1;

        for(j = 0; j < i; j++) {
            if(vet[i] == vet[j]) {
                primeira = 0;
                break;
            }
        }

        if(!primeira)
            continue;

        cont = 0;

        for(j = 0; j < 15; j++) {
            if(vet[i] == vet[j])
                cont++;
        }

        if(cont % 2 == 0) {
            int posicao = i;

            printf("%d. ", posicao + 1);

            if(posicao < totalAnimais) {
                printf("%s\n", animais[posicao]);
            } else {
                printf("Nao existe correspondencia.\n");
            }
        }
    }

    return 0;
}
