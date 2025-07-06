#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include "utils/paciente/paciente.h"

typedef struct medico
{
    int id;
    char nome[100];
    int crm;
    bool plantao;
} medico;

void gestaomed(medico medicos[])
{
    int num;
    printf("Você escolheu gestão de médicos! Escolha o que deseja fazer\n\n 1 -- CADASTRAR MÉDICO\n 2 -- CONSULTAR ID\n 3 -- ATUALIZAR MÉDICO\n 4 -- EXCLUIR MÉDICO");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        printf("----- Cadastro de Médicos -------");
        for (int i = 0; i < 2; i++)
        {
            medicos[i].id = i;
            bool isPlantao = false;
            char plantao[1];
            printf("---- Médico %d -----\n", i + 1);

            printf("NOME: ");
            getchar();
            fgets(medicos[i].nome, 100, stdin);
            medicos[i].nome[strcspn(medicos[i].nome, "\n")] = 0;

            printf("CRM: ");
            scanf("%d", &medicos[i].crm);

            while (!isPlantao)
            {
                printf("\nEstá de Plantão? (S / N): ");
                scanf(" %1s", plantao);
                if (plantao[0] == 'S' || plantao[0] == 's' || plantao[0] == 'N' || plantao[0] == 'n')
                {
                    if (plantao[0] == 'S' || plantao[0] == 's')
                    {
                        medicos[i].plantao = true;
                        isPlantao = true;
                    }
                    else if (plantao[0] == 'N' || plantao[0] == 'n')
                    {
                        medicos[i].plantao = false;
                        isPlantao = true;
                    }
                }
                else
                {
                    printf("Opção inválida. Digite S (Sim) ou N (Não)");
                }
            }
        }
    default:
        break;
    }
}


int main()
{

    paciente pacientes[2];


    medico medicos[2];
    
    int num;
    printf("Olá, escolha uma das opções ou feche o programa\n\n 1 -- GESTÃO DE PACIENTES\n 2 -- GESTÃO DE MÉDICOS\n 3 -- FILA DE ATENDIMENTO\n 4 -- SAIR DO SISTEMA\n");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        gestaoPacientes(pacientes);
        break;
    case 2:
        gestaomed(medicos);
        break;
    case 3:
        printf("Fila de Atendimento.\n");
        break;
    case 4:
        printf("Você saiu do sistema.\n");
        return 0;
        system("pause");
    default:
        printf("Número inválido!");
        break;
    }
    return 0;
}