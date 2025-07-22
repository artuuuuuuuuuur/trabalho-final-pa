#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../medico.h"

int extrairIdMedico(char linha[])
{
    char linhaCopia[200];
    strcpy(linhaCopia, linha);

    char *token = strtok(linhaCopia, ","); // id
    token = strtok(NULL, ",");             // nome
    token = strtok(NULL, ",");             // cpf
    token = strtok(NULL, ",");             // idade
    token = strtok(NULL, ",");             // idMedico

    if (token != NULL)
        return atoi(token);
    else
        return -1;
}

void imprimirPacienteFormatado(char linha[], FILE *arquivoDestino)
{
    char copia[200];
    strcpy(copia, linha);

    char *id = strtok(copia, ",");
    char *nome = strtok(NULL, ",");
    char *cpf = strtok(NULL, ",");
    char *idade = strtok(NULL, ",");
    char *idmed = strtok(NULL, ",");
    char *estado = strtok(NULL, "\n");

    fprintf(arquivoDestino, "┌──────────────────────────────────────────────┐\n");
    fprintf(arquivoDestino, "│ ID       : %-34s │\n", id);
    fprintf(arquivoDestino, "│ Nome     : %-34s │\n", nome);
    fprintf(arquivoDestino, "│ CPF      : %-34s │\n", cpf);
    fprintf(arquivoDestino, "│ Idade    : %-34s │\n", idade);
    fprintf(arquivoDestino, "│ ID Méd.  : %-34s │\n", idmed);
    fprintf(arquivoDestino, "│ Estado   : %-34s │\n", estado ? estado : "N/A");
    fprintf(arquivoDestino, "└──────────────────────────────────────────────┘\n\n");
}

int checarPacientesDoMedico(FILE *pacientes, int idmed, FILE *arquivoDestino)
{
    char str[200];
    int encontrou = 0;

    fprintf(arquivoDestino, "\n📋 Pacientes do médico com ID %d:\n\n", idmed);

    // Ignora o cabeçalho, se existir
    fgets(str, sizeof(str), pacientes);

    while (fgets(str, sizeof(str), pacientes))
    {
        int idNaLinha = extrairIdMedico(str);
        if (idmed == idNaLinha)
        {
            imprimirPacienteFormatado(str, arquivoDestino);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        fprintf(arquivoDestino, "⚠️  Nenhum paciente foi encontrado para esse médico.\n");
    }

    fclose(pacientes);
    return 0;
}
