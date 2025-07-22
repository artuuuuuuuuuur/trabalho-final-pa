#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils/gestaoMedicosEPacientes.h"
#include <locale.h>
#include <windows.h>

int main()
{
    system("cls");

    setlocale(LC_ALL, "pt_BR.UTF-8");

    FILE *medicos;

    medicos = fopen(("%s", "medicos.csv"), "a+");
    if (medicos == NULL)
    {
        printf("Erro ao abrir lista de medicos");
        return 0;
    }

    FILE *pacientes;

    pacientes = fopen(("%s", "pacientes.csv"), "a+");
    if (pacientes == NULL)
    {
        printf("Erro ao abrir lista de medicos");
        return 0;
    }

    menu(pacientes, medicos);

    gerarRelatorio(medicos, pacientes);
    fclose(medicos);
    fclose(pacientes);

    system("pause");
    return 0;
}