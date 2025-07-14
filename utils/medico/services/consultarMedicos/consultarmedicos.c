#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "consultarmedicos.h"
#include "utils/consultarMedicosGeral.h"
#include "utils/consultarMedicoPorID.h"

void consultarMedicos(FILE *medicos) {
    printf("------ CONSULTAR MÉDICOS ------");
    int res;
    printf("\nEscolha a opção desejada: ");
    printf("\n  [1] Consultar médico por ID\n  [2] Consultar lista completa");
    scanf("%d", &res);

    switch (res)
    {
    case 1:
        consultarMedicoPorID(medicos);
        break;
    case 2:
        consultarMedicosGeral(medicos);
        break;
    default:
        printf("Opção inválida.");
        break;
    }

}