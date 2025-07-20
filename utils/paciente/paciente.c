#include <stdlib.h>
#include <stdio.h>
#include "paciente.h"
#include "services/cadastrarPaciente.h"
#include "services/consultarPacientes/consultarpacientes.h"
#include <string.h>
#include "../checkID.h"

void gestaoPacientes(FILE *pacientes)
{
    int num;
    int currentID = checkID(pacientes);
    printf("Você escolheu gestão de pacientes! Escolha o que deseja fazer\n\n 1 -- CADASTRAR PACIENTE\n 2 -- CONSULTAR PACIENTES\n 3 -- ATUALIZAR PACIENTE\n 4 -- EXCLUIR PACIENTE");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        cadastrarPaciente(currentID, pacientes);
    case 2:
        consultarPacientes(pacientes);

    default:
        break;
    }
}