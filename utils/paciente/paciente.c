#include <stdlib.h>
#include <stdio.h>
#include "paciente.h"
#include <string.h>
#include "../gestaoMedicosEPacientes.h"

void gestaoPacientes(FILE *pacientes)
{
    int num;
    int currentID = checkID(pacientes);
    printf("Você escolheu gestão de pacientes! Escolha o que deseja fazer\n\n 1 -- CADASTRAR PACIENTE\n 2 -- CONSULTAR PACIENTES\n 3 -- ATUALIZAR PACIENTE\n 4 -- EXCLUIR PACIENTE\n");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        cadastrarPaciente(currentID, pacientes);
        break;
    case 2:
        consultarPacientes(pacientes);
        break;
    case 3:
        atualizarPaciente(pacientes);
        break;
    case 4:
        deletarPaciente(pacientes);
        break;
    default:
        break;
    }
}