#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char linha[256];
    char nome[100];
    float nota1, nota2, media;
    float soma_geral_medias = 0.0;
    int contador_alunos = 0;

    arquivo = fopen("alunos.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo alunos.csv\n");
        return 1;
    }

    printf("--- Resultados Individuais ---\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // remove '\n' e '\r' do final
        size_t len = strlen(linha);
        while (len > 0 && (linha[len - 1] == '\n' || linha[len - 1] == '\r')) {
            linha[--len] = '\0';
        }

        char *token;
        float notas[2];
        int i = 0;

        // lê o nome (verifica se existe)
        token = strtok(linha, ",");
        if (token == NULL) continue;
        strncpy(nome, token, sizeof(nome) - 1);
        nome[sizeof(nome) - 1] = '\0';

        // lê as duas notas
        while ((token = strtok(NULL, ",")) != NULL && i < 2) {
            notas[i++] = (float)strtod(token, NULL);
        }

        // processa somente se leu 2 notas válidas
        if (i == 2) {
            nota1 = notas[0];
            nota2 = notas[1];
            media = (nota1 + nota2) / 2.0f;
            soma_geral_medias += media;
            contador_alunos++;

            printf("Aluno: %-20s Média: %.2f\n", nome, media);
        }
    }

    printf("------------------------------\n");

    if (contador_alunos > 0) {
        float media_geral = soma_geral_medias / contador_alunos;
        printf("Média Geral da Turma: %.2f\n", media_geral);
    } else {
        printf("Nenhum dado de aluno válido encontrado no arquivo.\n");
    }

    fclose(arquivo);

    return 0;
}