#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../../medico.h"

void consultarMedicos(FILE *medicos)
{
    printf("------ CONSULTAR MÉDICOS ------");

    bool response = false;

    while (!response)
    {
        setbuf(stdin, NULL);
        printf("\nEscolha a opção desejada: ");
        printf("\n  [1] Consultar médico por ID\n  [2] Consultar lista completa\n\n");
        int res;
        scanf("%d", &res);
        switch (res)
        {
        case 1:
            consultarMedicoPorID(medicos);
            response = true;
            break;
        case 2:
            consultarMedicosGeral(medicos);
            response = true;
            break;
        default:
            setbuf(stdin, NULL);
            printf("Opção inválida. Digite novamente.");
            break;
        }
    }
}