#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "consultarpacientes.h"
#include "utils/consultarPacientePorID.h"
#include "utils/consultarPacientesGeral.h"

void consultarPacientes(FILE *pacientes)
{
    printf("------ CONSULTAR PACIENTES ------");

    bool response = false;

    while (!response)
    {
        printf("\nEscolha a opção desejada: ");
        printf("\n  [1] Consultar paciente por ID\n  [2] Consultar lista completa");
        int res;
        scanf("%d", &res);
        switch (res)
        {
        case 1:
            consultarPacientePorID(pacientes);
            response = true;
            break;
        case 2:
            consultarPacientesGeral(pacientes);
            response = true;
            break;
        default:
            printf("Opção inválida. Digite novamente.");
        }
    }
}