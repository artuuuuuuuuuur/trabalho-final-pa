#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../../../medico.h"
#include <stdlib.h>

// Corrigir bugs: Deseja procurar por outro ID?

void consultarMedicoPorID(FILE *medicos)
{
    char linha[100];
    char idDigitado[100];
    bool isMedicoEncontrado = false;
    bool response = false;

    while (!isMedicoEncontrado)
    {
        // Voltar o ponteiro do arquivo para o início
        rewind(medicos);
        printf("Digite o ID do médico: ");
        setbuf(stdin, NULL);
        gets(idDigitado);

        printf("-----------------------------------------------------------------------\n\n");
        // Lê linha por linha
        while (fgets(linha, sizeof(linha), medicos) != NULL)
        {
            if (strcmp(linha, "id,nome,crm,plantao\n") != 0)
            {
                char id[100];
                char nome[100];
                char crm[100];
                char plantao[100];
                strcpy(id, strtok(linha, ","));
                strcpy(nome, strtok(NULL, ","));
                strcpy(crm, strtok(NULL, ","));
                strcpy(plantao, strtok(NULL, ","));

                int medicoEncontrado = strcmp(id, idDigitado);

                
                if (medicoEncontrado == 0)
                {
                    printf("Médico encontrado:\n");
                    printf("[%s]\n  Nome: %s\n  CRM: %s\n  Plantão: %s\n", id, nome, crm, plantao);
                    printf("----------------------------------------------------------------------\n");
                    isMedicoEncontrado = true;
                }
            }
        }
        FILE *pacientes = fopen("pacientes.csv", "r");
        checarPacientesDoMedico(pacientes, atoi(idDigitado));
        fclose(pacientes);
        if (isMedicoEncontrado == false)
        {
            printf("Médico não encontrado. Tente novamente.\n");
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
                isMedicoEncontrado = false;
                response = true;
                break;
            }
            else if (res == 'N' || res == 'n')
            {
                isMedicoEncontrado = true;
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