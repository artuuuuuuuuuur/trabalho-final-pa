#include <stdio.h>
#include <stdbool.h>
#include "paciente/paciente.h"
#include "medico/medico.h"
#include "filaDeAtendimento/filaDeAtendimento.h"
#include <windows.h>

void menu(FILE *pacientes, FILE *medicos)
{

    bool res = false;
    while(!res) {
    system("cls");
    int num;
    printf("Olá, escolha uma das opções ou feche o programa\n\n 1 -- GESTÃO DE PACIENTES\n 2 -- GESTÃO DE MÉDICOS\n 3 -- FILA DE ATENDIMENTO\n 4 -- SAIR DO SISTEMA\n");
    scanf("%d", &num);
    
        switch (num)
        {
        case 1:
            gestaoPacientes(pacientes, medicos);
            res = true;
            break;
        case 2:
            gestaoMedicos(medicos, pacientes);
            res = true;
            break;
        case 3:
            filaDeAtendimento(pacientes, medicos);
            res = true;
            break;
        case 4:
            printf("Você saiu do sistema.\n");
            res = true;
            break;
        default:
            printf("Número inválido!");
            break;
        }
    }
}