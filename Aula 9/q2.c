
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Funcionario {
    int id;
    char cargo[30];
    float salario;
};

int main() {

    struct Funcionario *funcionario;
    struct Funcionario *backup;

    funcionario = malloc(sizeof(struct Funcionario));
    backup = malloc(sizeof(struct Funcionario));

    if(funcionario == NULL || backup == NULL) {
        printf("Erro na alocacao de memoria!");
        free(funcionario);
        free(backup);
        return 1;
    }

    printf("Digite o ID: ");
    scanf("%d", &funcionario->id);

    printf("Digite o cargo: ");
    scanf(" %29[^\n]", funcionario->cargo);

    printf("Digite o salario: ");
    scanf("%f", &funcionario->salario);

    memcpy(backup, funcionario, sizeof(struct Funcionario));

    FILE *arquivo = fopen("backup_rh.bin", "wb");

    if(arquivo == NULL) {
        printf("Erro ao abrir arquivo!");
        free(funcionario);
        free(backup);
        return 1;
    }

    fwrite(backup, sizeof(struct Funcionario), 1, arquivo);

    fclose(arquivo);

    printf("\nBackup salvo com sucesso!");

    free(funcionario);
    free(backup);

    return 0;
}
