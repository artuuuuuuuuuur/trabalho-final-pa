#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils/paciente/paciente.h"
#include "utils/medico/medico.h"
#include "utils/gerarRelatorio.h"

int main()
{
    FILE *medicosFile;

    medicosFile = fopen(("%s", "medicos.csv"), "a+");
    if (medicosFile == NULL) {
        printf("Erro ao abrir lista de medicos");
        return 0;
    }

    paciente pacientes[2];

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
        break;
    default:
        printf("Número inválido!");
        break;
    }

    fclose(medicosFile);
    gerarRelatorio();
    return 0;
}