
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Eleitor {
    char titulo[12];
    int zona;
};

struct Cedula {
    struct Eleitor eleitor;
    int numero_voto;
};

// Funcao para adicionar votos
void adicionarVoto(struct Cedula **votos, int *quantidade) {

    struct Cedula *temp;

    temp = realloc(*votos,
                   (*quantidade + 1) * sizeof(struct Cedula));

    if(temp == NULL) {
        printf("Erro na realocacao!");
        return;
    }

    *votos = temp;

    printf("\nTitulo eleitoral: ");
    scanf(" %11s", (*votos)[*quantidade].eleitor.titulo);

    printf("Zona eleitoral: ");
    scanf("%d", &(*votos)[*quantidade].eleitor.zona);

    printf("Numero do voto: ");
    scanf("%d", &(*votos)[*quantidade].numero_voto);

    (*quantidade)++;
}

// Funcao para recuperar os votos
struct Cedula* recuperarVotos(int *quantidade) {

    FILE *arquivo = fopen("urnas.bin", "rb");

    if(arquivo == NULL) {
        printf("Erro ao abrir arquivo!");
        return NULL;
    }

    fseek(arquivo, 0, SEEK_END);

    long tamanho = ftell(arquivo);

    if(tamanho < 0 || tamanho % sizeof(struct Cedula) != 0) {
        printf("Arquivo invalido!");
        fclose(arquivo);
        return NULL;
    }

    *quantidade = tamanho / sizeof(struct Cedula);

    if(*quantidade == 0) {
        fclose(arquivo);
        return NULL;
    }

    rewind(arquivo);

    struct Cedula *votos;

    votos = malloc(tamanho);

    if(votos == NULL) {
        printf("Erro na alocacao!");
        fclose(arquivo);
        return NULL;
    }

    if(fread(votos, sizeof(struct Cedula),
             *quantidade, arquivo) != (size_t)*quantidade) {

        printf("Erro na leitura!");

        free(votos);
        fclose(arquivo);

        return NULL;
    }

    fclose(arquivo);

    return votos;
}

int main() {

    struct Cedula *votos = NULL;

    int quantidade = 0;
    int opcao;

    do {

        printf("\n===== SISTEMA ELEITORAL =====\n");
        printf("1 - Adicionar voto\n");
        printf("2 - Finalizar cadastro\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        if(opcao == 1) {

            adicionarVoto(&votos, &quantidade);

        }
        else if(opcao != 2) {

            printf("Opcao invalida!\n");

        }

    } while(opcao != 2);

    // Salvando os votos

    FILE *arquivo = fopen("urnas.bin", "wb");

    if(arquivo == NULL) {

        printf("Erro ao criar arquivo!");

        free(votos);
        return 1;
    }

    if(quantidade > 0) {

        fwrite(votos, sizeof(struct Cedula),
               quantidade, arquivo);
    }

    fclose(arquivo);

    free(votos);

    printf("\nVotos salvos com sucesso!");

    // Recuperando os votos

    int total;

    struct Cedula *recuperados =
        recuperarVotos(&total);

    if(recuperados != NULL) {

        printf("\n\n===== VOTOS RECUPERADOS =====\n");

        for(int i = 0; i < total; i++) {

            printf("\nTitulo: %s",
                   recuperados[i].eleitor.titulo);

            printf("\nZona: %d",
                   recuperados[i].eleitor.zona);

            printf("\nNumero do voto: %d\n",
                   recuperados[i].numero_voto);
        }

        free(recuperados);
    }

    return 0;
}
