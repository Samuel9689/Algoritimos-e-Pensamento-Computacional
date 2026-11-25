
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
} Produto;

int main() {
    int vet[12], pares[12];
    int qtdPares = 0;
    int visitado[12] = {0};
    int i, j, cont, totalProdutos = 0;

    printf("Digite 12 numeros:\n");

    for(i = 0; i < 12; i++) {
        scanf("%d", &vet[i]);
    }

    // Contar ocorrencias e calcular quantidade de produtos
    for(i = 0; i < 12; i++) {
        if(visitado[i] == 1)
            continue;

        cont = 0;

        for(j = 0; j < 12; j++) {
            if(vet[i] == vet[j]) {
                cont++;
                visitado[j] = 1;
            }
        }

        if(cont % 2 == 0) {
            pares[qtdPares++] = vet[i];
        } else if(vet[i] > 0) {
            totalProdutos += vet[i];
        }
    }

    Produto *produtos = malloc(totalProdutos * sizeof(Produto));

    if(totalProdutos > 0 && produtos == NULL) {
        printf("Erro de memoria.\n");
        return 1;
    }

    // Cadastrar produtos
    int pos = 0;

    for(i = 0; i < 12; i++) {
        if(visitado[i] == 0)
            continue;

        // Verificar se e a primeira ocorrencia
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

        for(j = 0; j < 12; j++) {
            if(vet[i] == vet[j])
                cont++;
        }

        if(cont % 2 != 0 && vet[i] > 0) {
            for(j = 0; j < vet[i]; j++) {
                printf("\nProduto %d:\n", pos + 1);

                printf("Nome: ");
                scanf(" %49[^\n]", produtos[pos].nome);

                printf("Preco: ");
                scanf("%f", &produtos[pos].preco);

                pos++;
            }
        }
    }

    // Ordenar produtos alfabeticamente
    for(i = 0; i < pos - 1; i++) {
        for(j = i + 1; j < pos; j++) {
            if(strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                Produto temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }

    // Ordenar numeros pares em ordem decrescente
    for(i = 0; i < qtdPares - 1; i++) {
        for(j = i + 1; j < qtdPares; j++) {
            if(pares[i] < pares[j]) {
                int temp = pares[i];
                pares[i] = pares[j];
                pares[j] = temp;
            }
        }
    }

    // Mostrar vetor original
    printf("\nVetor original:\n");

    for(i = 0; i < 12; i++) {
        printf("%d ", vet[i]);
    }

    // Mostrar ocorrencias
    printf("\n\nOcorrencias:\n");

    for(i = 0; i < 12; i++) {
        int primeira = 1;

        for(j = 0; j < i; j++) {
            if(vet[i] == vet[j]) {
                primeira = 0;
                break;
            }
        }

        if(primeira) {
            cont = 0;

            for(j = 0; j < 12; j++) {
                if(vet[i] == vet[j])
                    cont++;
            }

            printf("%d aparece %d vezes.\n", vet[i], cont);
        }
    }

    // Mostrar produtos
    printf("\nProdutos em ordem alfabetica:\n");

    for(i = 0; i < pos; i++) {
        printf("%s - R$ %.2f\n",
               produtos[i].nome, produtos[i].preco);
    }

    // Mostrar segundo vetor
    printf("\nNumeros com ocorrencia par:\n");

    for(i = 0; i < qtdPares; i++) {
        printf("%d ", pares[i]);
    }

    free(produtos);

    return 0;
}
