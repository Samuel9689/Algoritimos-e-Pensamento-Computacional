
#include <stdio.h>
#include <stdlib.h>

struct Cliente {
    int conta_corrente;
    char nome[50];
    float saldo;
};

int main() {

    struct Cliente cliente;

    int conta, opcao;
    float valor;

    FILE *arquivo = fopen("clientes.bin", "rb+");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }

    printf("Digite o numero da conta: ");
    scanf("%d", &conta);

    printf("1 - Deposito\n");
    printf("2 - Saque\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    printf("Digite o valor: ");
    scanf("%f", &valor);

    while(fread(&cliente, sizeof(struct Cliente), 1, arquivo) == 1) {

        if(cliente.conta_corrente == conta) {

            if(opcao == 1) {
                cliente.saldo += valor;
            }
            else if(opcao == 2) {
                if(valor > cliente.saldo || valor < 0) {
                    printf("Saldo insuficiente ou valor invalido!");
                    fclose(arquivo);
                    return 1;
                }

                cliente.saldo -= valor;
            }
            else {
                printf("Opcao invalida!");
                fclose(arquivo);
                return 1;
            }

            fseek(arquivo, -(long)sizeof(struct Cliente), SEEK_CUR);

            fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);

            printf("\nSaldo atualizado: R$ %.2f", cliente.saldo);

            fclose(arquivo);
            return 0;
        }
    }

    printf("\nConta nao encontrada!");

    fclose(arquivo);

    return 0;
}
