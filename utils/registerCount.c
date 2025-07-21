#include <stdio.h>
#include <string.h>

int registerCount(FILE *arquivo, int estadoInput)
{
    rewind(arquivo);
    char linha[500];
    int nume = 0;

    fgets(linha, sizeof(linha), arquivo);
    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (estadoInput >= 0)
        {
            char *id = strtok(linha, ",");
            char *nome = strtok(NULL, ",");
            char *cpf = strtok(NULL, ",");
            char *idade = strtok(NULL, ",");
            char *idmed = strtok(NULL, ",");
            char *estado = strtok(NULL, "\n");

            if (!estado)
                continue;

            estado[strcspn(estado, "\r\n")] = '\0';

            char alvo[4];
            sprintf(alvo, "%d", estadoInput);

            if (strcmp(alvo, estado) == 0)
            {
                nume++;
            }
        }
        else
        {
            nume++;
        }
    }

    return nume;
}
