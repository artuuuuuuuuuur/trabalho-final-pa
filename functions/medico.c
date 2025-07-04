#include <stdbool.h>

typedef struct medico {
    int id;
    char nome[30];
    int crm;
    bool plantao;
}MEDICO;

void gestaomed(MEDICO medicos[]){
    int num;
    printf("Você escolheu gestão de médicos! Escolha o que deseja fazer\n\n 1 -- CADASTRAR MÉDICO\n 2 -- CONSULTAR ID\n 3 -- ATUALIZAR MÉDICO\n 4 -- EXCLUIR MÉDICO");
    switch (num)
    {
    case 1:
        break;
    
    default:
        break;
    }
}