#include "consultarMedicoPorID.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void consultarMedicoPorID(FILE *medicos)
{
    char linha[100];
    char idDigitado[100];
    bool isMedicoEncontrado = false;

    while (!isMedicoEncontrado) {
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
        if (isMedicoEncontrado == false)
        {
            printf("Médico não encontrado. Tente novamente.\n");
        }

        bool response = false;
        while (!response)
        {
            printf("Deseja procurar por outro ID? (S / N)");
            char res[2];
            scanf("%c", res[0]);

            if (res[0] == 'S' || res[0] == 's' || res[0] == 'N' || res[0] == 'n')
            {
                if (res[0] == 'S' || res[0] == 's')
                {
                    isMedicoEncontrado = false;
                }
                else if (res[0] == 'N' || res[0] == 'n')
                {
                    isMedicoEncontrado = true;
                    break;
                }
            }
            else
            {
                printf("Opção inválida. Digite S (Sim) ou N (Não)");
            }
        }
    }
}