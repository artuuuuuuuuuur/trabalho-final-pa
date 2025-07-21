#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils/paciente/paciente.h"
#include "utils/medico/medico.h"
#include "utils/gestaoMedicosEPacientes.h"

/*
    A fazer:
    1. Formatar texto do terminal (Biblioteca de caracteres com acento);
    2. Formatar texto para o arquivo .csv (Interpretar caracteres com acento);
    3. Adicionar chatbot;
    4. Criar funções de retornar ao menu anterior;
    5. Criar validador de CRM (se já existe um CRM no sistema)
    6. Mudar tipo do CRM para STRING

*/

int main()
{
    FILE *medicos;

    medicos = fopen(("%s", "medicos.csv"), "a+");
    if (medicos == NULL) {
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
        gestaoMedicos(medicos);
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

    gerarRelatorio(medicos, pacientes);
    fclose(medicos);
    fclose(pacientes);
    return 0;
}