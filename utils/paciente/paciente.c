#include <stdlib.h>
#include <stdio.h>
#include "paciente.h"
#include <string.h>
#include "../gestaoMedicosEPacientes.h"

void gestaoPacientes(FILE *pacientes, FILE *medicos)
{
    system("cls");
    int num;
    bool res = false;
    int currentID = checkID(pacientes);
    printf("Você escolheu gestão de pacientes! Escolha o que deseja fazer\n\n 1 -- CADASTRAR PACIENTE\n 2 -- CONSULTAR PACIENTES\n 3 -- ATUALIZAR PACIENTE\n 4 -- EXCLUIR PACIENTE\n 5 -- VOLTAR PARA O MENU ANTERIOR\n");
    scanf("%d", &num);
    while (!res)
    {
        switch (num)
        {
        case 1:
            cadastrarPaciente(currentID, pacientes);
            res = true;
            break;
        case 2:
            consultarPacientes(pacientes);
            res = true;
            break;
        case 3:
            atualizarPaciente(pacientes);
            res = true;
            break;
        case 4:
            deletarPaciente(pacientes);
            res = true;
            break;
        case 5:
            menu(pacientes, medicos);
            res = true;
            break;
        default:
            printf("Opção inválida, tente novamente.");
            break;
        }
    }
}