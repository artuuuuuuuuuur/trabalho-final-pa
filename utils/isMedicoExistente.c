#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "gestaoMedicosEPacientes.h"

int isMedicoExistente(char idInput[])
{
    FILE *medicos = fopen("medicos.csv", "r");
    if (medicos == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    char linha[100];
    bool idMedEncontrado = false;

    while (fgets(linha, sizeof(linha), medicos) != NULL)
    {
        if (strcmp(linha, "id,nome,crm,plantao\n") != 0)
        {
            char *id = strtok(linha, ",");
            if (id != NULL && strcmp(id, idInput) == 0)
            {
                idMedEncontrado = true;
                break;
            }
        }
    }

    fclose(medicos);
    return (idMedEncontrado ? 0 : 1);
}
