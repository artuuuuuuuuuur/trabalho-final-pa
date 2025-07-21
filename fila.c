#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACIENTES 500
#define LINHA_MAX 200

typedef struct
{
    char linha[LINHA_MAX];
    int estado;
} Paciente;

int paccount()
{
    FILE *fptr = fopen("pacientes.csv", "r");
    if (!fptr)
    {
        printf("Erro ao abrir pacientes.csv\n");
        exit(1);
    }

    int count = 0;
    char buffer[LINHA_MAX];
    while (fgets(buffer, LINHA_MAX, fptr))
    {
        count++;
    }
    fclose(fptr);
    return count;
}

int extrair_estado(char *linha)
{
    int estado;
    char copia[LINHA_MAX];
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

void ordenar_pacientes(Paciente *lista, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (lista[j].estado < lista[j + 1].estado)
            {
                Paciente temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void salvar_listas_em_arquivos(Paciente *alta, int count_alta, Paciente *espera, int count_espera)
{
    FILE *falta = fopen("pacientes_alta.csv", "w");
    FILE *ffila = fopen("pacientes_fila.csv", "w");

    if (!falta || !ffila)
    {
        printf("Erro ao criar arquivos de saída.\n");
        return;
    }

    for (int i = 0; i < count_alta; i++)
    {
        fputs(alta[i].linha, falta);
    }

    fprintf(ffila, "%s\n", "id,nome,cpf,idade,idmed,estado");
    for (int i = 0; i < count_espera; i++)
    {
        if (espera[i].estado == 3)
        {
            fprintf(ffila, "%s  (INTERNAÇÃO)\n", espera[i].linha);
        }
        else
        {
            fputs(espera[i].linha, ffila);
        }
    }

    fclose(falta);
    fclose(ffila);
}

void mostrar_listas()
{
    FILE *fptr = fopen("pacientes.csv", "r");
    if (!fptr)
    {
        printf("Erro ao abrir pacientes.csv\n");
        return;
    }

    Paciente alta[MAX_PACIENTES];
    Paciente espera[MAX_PACIENTES];
    int count_alta = 0, count_espera = 0;

    char linha[LINHA_MAX];
    while (fgets(linha, LINHA_MAX, fptr))
    {
        int estado = extrair_estado(linha);
        if (estado == 0)
        {
            strcpy(alta[count_alta].linha, linha);
            alta[count_alta].estado = estado;
            count_alta++;
        }
        else
        {
            strcpy(espera[count_espera].linha, linha);
            espera[count_espera].estado = estado;
            count_espera++;
        }
    }

    fclose(fptr);

    ordenar_pacientes(espera, count_espera);

    printf("\n\033[32m--- PACIENTES COM ALTA ---\033[0m\n");
    for (int i = 0; i < count_alta; i++)
    {
        printf("%s", alta[i].linha);
    }

    printf("\n\033[33m--- PACIENTES EM FILA ---\033[0m\n");
    for (int i = 0; i < count_espera; i++)
    {
        if (espera[i].estado == 3)
        {
            printf("\033[31mINTERNAÇÃO:\033[0m %s", espera[i].linha);
        }
        else
        {
            printf("%s", espera[i].linha);
        }
    }

    salvar_listas_em_arquivos(alta, count_alta, espera, count_espera);
    printf("\n\nListas também foram salvas em 'pacientes_alta.csv' e 'pacientes_fila.csv'.\n");
}

int main()
{
    mostrar_listas();
    return 0;
}
