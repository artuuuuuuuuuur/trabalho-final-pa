#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils/gestaoMedicosEPacientes.h"
#include <locale.h>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    bool repetir = true;

    while (repetir)
    {
        system("cls");

        FILE *medicos = fopen("medicos.csv", "a+");
        if (medicos == NULL)
        {
            printf("Erro ao abrir lista de médicos.\n");
            return 1;
        }

        FILE *pacientes = fopen("pacientes.csv", "a+");
        if (pacientes == NULL)
        {
            printf("Erro ao abrir lista de pacientes.\n");
            fclose(medicos);
            return 1;
        }

        menu(pacientes, medicos); // chama o menu em loop

        gerarRelatorio(medicos, pacientes);

        fclose(medicos);
        fclose(pacientes);

        printf("\nDeseja reiniciar o sistema? (1 = sim, 0 = não): ");
        scanf("%d", &repetir);
        getchar(); // consome o '\n' do scanf
    }

    printf("\nSistema encerrado.\n");
    return 0;
}
