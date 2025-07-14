#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils/paciente/paciente.h"
#include "utils/medico/medico.h"

int main()
{
    FILE *medicosFile;

    medicosFile = fopen(("%s", "medicos.csv"), "a+");
    if (medicosFile == NULL) {
        printf("Erro ao abrir lista de medicos");
        return 0;
    }
    
    FILE *pacientes;

    pacientes = fopen(("%s", "pacientes.csv"), "a+");
    if (pacientes == NULL) {
        printf("Erro ao abrir lista de medicos");
        return 0;
    }

    int num;
    printf("Olá, escolha uma das opções ou feche o programa\n\n 1 -- GESTÃO DE PACIENTES\n 2 -- GESTÃO DE MÉDICOS\n 3 -- FILA DE ATENDIMENTO\n 4 -- SAIR DO SISTEMA\n");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        gestaoPacientes(pacientes);
        break;
    case 2:
        gestaoMedicos(medicosFile);
        break;
    case 3:
        printf("Fila de Atendimento.\n");
        break;
    case 4:
        printf("Você saiu do sistema.\n");
        return 0;
    default:
        printf("Número inválido!");
        break;
    }

    fclose(medicosFile);
    fclose(pacientes);
    return 0;
}