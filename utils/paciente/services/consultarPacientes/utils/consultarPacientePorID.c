#include "consultarPacientePorID.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Corrigir bugs: Deseja procurar por outro ID?

void consultarPacientePorID(FILE *pacientes)
{
    char linha[200];
    char idDigitado[20];
    bool isPacienteEncontrado = false;
    bool response = false;

    while (!isPacienteEncontrado)
    {
        rewind(pacientes); // volta o ponteiro do arquivo

        printf("Digite o ID do médico: ");
        getchar();
        gets(idDigitado);

        printf("-----------------------------------------------------------------------\n\n");

        while (fgets(linha, sizeof(linha), pacientes) != NULL)
        {
            if (strcmp(linha, "id,nome,cpf,idade,idmed,estado\n") != 0)
            {
                char id[20], nome[100], cpf[20], idade[10], idmed[20], estado[20];

                char *token = strtok(linha, ",");
                if (token)
                    strcpy(id, token);

                token = strtok(NULL, ",");
                if (token)
                    strcpy(nome, token);

                token = strtok(NULL, ",");
                if (token)
                    strcpy(cpf, token);

                token = strtok(NULL, ",");
                if (token)
                    strcpy(idade, token);

                token = strtok(NULL, ",");
                if (token)
                    strcpy(idmed, token);

                token = strtok(NULL, ",");
                if (token)
                    strcpy(estado, token);

                if (strcmp(id, idDigitado) == 0)
                {
                    printf("Médico encontrado:\n");
                    printf("[%s]\n  Nome: %s\n  CPF: %s\n  IDADE: %s\n  ID DO MÉDICO RESPONSÁVEL: %s\n  ESTADO: %s\n", id, nome, cpf, idade, idmed, estado);
                    printf("----------------------------------------------------------------------\n");
                    isPacienteEncontrado = true;
                }
            }
        }

        if (!isPacienteEncontrado)
        {
            printf("Paciente não encontrado. Tente novamente.\n");
        }
        response = false;
        while (!response)
        {
            setbuf(stdin, NULL);
            char res;
            printf("Deseja procurar por outro ID? (S / N)");
            res = getc(stdin);
    
            if (res == 'S' || res == 's')
            {
                isPacienteEncontrado = false;
                response = true;
                break;
            }
            else if (res == 'N' || res == 'n')
            {
                isPacienteEncontrado = true;
                response = true;
                break;
            }
            else
            {
                printf("Opção inválida. Digite S (Sim) ou N (Não)\n");
            }
        }
    }


}
