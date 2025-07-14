#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "consultarmedicos.h"
#include "utils/consultarMedicosGeral.h"

void consultarMedicos(FILE *medicos) {
    printf("------ CONSULTAR MÉDICOS ------");
    int res;
    printf("\nEscolha a opção desejada: ");
    printf("\n  [0] Consultar médico por ID\n  [1] Consultar lista completa");
    scanf("%d", &res);

    switch (res)
    {
    case 0:
        printf("Consultar médico por ID (A fazer)");
        break;
    case 1:
        consultarMedicosGeral(medicos);
        break;
    default:
        printf("Opção inválida.");
        break;
    }

}