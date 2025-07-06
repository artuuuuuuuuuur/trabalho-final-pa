#include <stdlib.h>
#include <stdio.h>
#include "paciente.h"
#include <string.h>

void gestaoPacientes(paciente pacientes[])
{
    int num;
    printf("Você escolheu gestão de pacientes! Escolha o que deseja fazer\n\n 1 -- CADASTRAR PACIENTE\n 2 -- CONSULTAR ID\n 3 -- ATUALIZAR PACIENTE\n 4 -- EXCLUIR PACIENTE");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        printf("----- Cadastro de pacientes -------");
        for (int i = 0; i < 2; i++)
        {
            pacientes[i].id = i;
            printf("---- Paciente %d -----\n", i + 1);

            printf("NOME: ");
            getchar();
            fgets(pacientes[i].nome, 100, stdin);
            pacientes[i].nome[strcspn(pacientes[i].nome, "\n")] = 0;

            printf("CPF: ");
            scanf("%d", &pacientes[i].cpf);
            printf("IDADE: ");
            scanf("%d", &pacientes[i].idade);
            printf("MÉDICO RESPONSÁVEL: ");
            scanf("%d", &pacientes[i].idmed);
            printf("ESTADO DO PACIENTE: ");
            scanf("%d", &pacientes[i].estado);
        }
    default:
        break;
    }
}