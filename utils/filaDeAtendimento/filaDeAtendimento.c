#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDeAtendimento.h"

void filaDeAtendimento()
{
    FILE *fptr = fopen("pacientes.csv", "r");
    if (!fptr)
    {
        printf("Erro ao abrir pacientes.csv\n");
        return;
    }

    char alta[500][200];
    int estados_alta[500];

    char espera[500][200];
    int estados_espera[500];

    int count_alta = 0, count_espera = 0;

    char linha[200];
    while (fgets(linha, sizeof(linha), fptr))
    {
        if (strstr(linha, "ID") != NULL)
            continue; // Ignora cabeçalho

        int estado = extrairEstado(linha);

        if (estado == 0)
        {
            strcpy(alta[count_alta], linha);
            estados_alta[count_alta] = estado;
            count_alta++;
        }
        else
        {
            strcpy(espera[count_espera], linha);
            estados_espera[count_espera] = estado;
            count_espera++;
        }
    }
    fclose(fptr);

    // Ordenar espera por estado decrescente
    for (int i = 0; i < count_espera - 1; i++)
    {
        for (int j = 0; j < count_espera - i - 1; j++)
        {
            if (estados_espera[j] < estados_espera[j + 1])
            {
                char tempLinha[200];
                int tempEstado;

                strcpy(tempLinha, espera[j]);
                strcpy(espera[j], espera[j + 1]);
                strcpy(espera[j + 1], tempLinha);

                tempEstado = estados_espera[j];
                estados_espera[j] = estados_espera[j + 1];
                estados_espera[j + 1] = tempEstado;
            }
        }
    }

    // Mostrar alta
    printf("\n\033[32m--- PACIENTES COM ALTA ---\033[0m\n");
    for (int i = 0; i < count_alta; i++)
    {
        char linhaLocal[200];
        strcpy(linhaLocal, alta[i]);
        char *id = strtok(linhaLocal, ",");
        char *nome = strtok(NULL, ",");
        char *cpf = strtok(NULL, ",");
        char *idade = strtok(NULL, ",");
        char *idmed = strtok(NULL, ",");
        char *estado = strtok(NULL, "\n");
        
        if(strcmp(id, "id") != 0) 
        printf("ID: %s | Nome: %s | CPF: %s | Idade: %s | Médico: %s | Estado: %s\n", id, nome, cpf, idade, idmed, estado);

    }

    // Mostrar fila
    printf("\n\033[33m--- PACIENTES EM FILA ---\033[0m\n");
    for (int i = 0; i < count_espera; i++)
    {
        char linhaLocal[200];
        strcpy(linhaLocal, espera[i]);
        char *id = strtok(linhaLocal, ",");
        char *nome = strtok(NULL, ",");
        char *cpf = strtok(NULL, ",");
        char *idade = strtok(NULL, ",");
        char *idmed = strtok(NULL, ",");
        char *estado = strtok(NULL, "\n");

        int est = estados_espera[i];

        if (est == 3)
        {
            printf("\033[31mINTERNAÇÃO:\033[0m ");
        }

        printf("ID: %s | Nome: %s | CPF: %s | Idade: %s | Médico: %s | Estado: %s\n", id, nome, cpf, idade, idmed, estado);
    }

}
