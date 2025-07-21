#include "../filaDeAtendimento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int extrairEstado(char *linha)
{
    int estado;
    char copia[200];
    strcpy(copia, linha);
    char *token = strtok(copia, ",");
    int i = 0;
    while (token != NULL && i < 6)
    {
        if (i == 5)
        {
            estado = atoi(token);
            break;
        }
        token = strtok(NULL, ",");
        i++;
    }
    return estado;
}