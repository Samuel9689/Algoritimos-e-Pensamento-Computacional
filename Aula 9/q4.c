
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Professor {
    int registro;
    int horas_aula;
};

struct Professor* lerArquivo(int *quantidade) {

    FILE *arquivo = fopen("folha.dat", "rb");

    if(arquivo == NULL) {
        printf("Erro ao abrir arquivo!");
        return NULL;
    }

    fread(quantidade, sizeof(int), 1, arquivo);

    struct Professor *professores;

    professores = malloc(*quantidade * sizeof(struct Professor));

    if(professores == NULL) {
        printf("Erro na memoria!");
        fclose(arquivo);
        return NULL;
    }

    fread(professores, sizeof(struct Professor),
          *quantidade, arquivo);

    fclose(arquivo);

    return professores;
}

int main() {

    int n;

    printf("Quantos professores deseja cadastrar? ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("Quantidade invalida!");
        return 1;
    }

    struct Professor *professores;

    professores = malloc(n * sizeof(struct Professor));

    if(professores == NULL) {
        printf("Erro na alocacao!");
        return 1;
    }

    for(int i = 0; i < n; i++) {

        printf("\nProfessor %d\n", i + 1);

        printf("Registro: ");
        scanf("%d", &professores[i].registro);

        printf("Horas aula: ");
        scanf("%d", &professores[i].horas_aula);
    }

    int tamanho = n * sizeof(struct Professor);

    void *buffer = malloc(tamanho);

    if(buffer == NULL) {
        printf("Erro no buffer!");
        free(professores);
        return 1;
    }

    memcpy(buffer, professores, tamanho);

    FILE *arquivo = fopen("folha.dat", "wb");

    if(arquivo == NULL) {
        printf("Erro ao criar arquivo!");
        free(professores);
        free(buffer);
        return 1;
    }

    fwrite(&n, sizeof(int), 1, arquivo);

    fwrite(buffer, tamanho, 1, arquivo);

    fclose(arquivo);

    printf("\nDados salvos com sucesso!");

    free(professores);
    free(buffer);

    // Recuperando os dados

    int quantidade;

    struct Professor *recuperados =
        lerArquivo(&quantidade);

    if(recuperados != NULL) {

        printf("\n\n===== PROFESSORES RECUPERADOS =====\n");

        for(int i = 0; i < quantidade; i++) {

            printf("\nRegistro: %d",
                   recuperados[i].registro);

            printf("\nHoras aula: %d\n",
                   recuperados[i].horas_aula);
        }

        free(recuperados);
    }

    return 0;
}
