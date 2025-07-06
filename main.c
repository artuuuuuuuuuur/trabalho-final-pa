#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

typedef struct paciente
{
    int id;
    char nome[100];
    int cpf;
    int idade;
    int idmed;
    int estado;
} paciente;

void gestaopac(paciente pacientes[])
{
    int num;
    printf("Você escolheu gestão de pacientes! Escolha o que deseja fazer\n\n 1 -- CADASTRAR PACIENTE\n 2 -- CONSULTAR ID\n 3 -- ATUALIZAR PACIENTE\n 4 -- EXCLUIR PACIENTE");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        printf("----- Cadastro de pacientes -------");
        for (int i = 0; i < 2; i++)
        {
            pacientes[i].id = i;
            printf("---- Paciente %d -----\n", i + 1);

            printf("NOME: ");
            getchar();
            fgets(pacientes[i].nome, 100, stdin);
            pacientes[i].nome[strcspn(pacientes[i].nome, "\n")] = 0;

            printf("CPF: ");
            scanf("%d", &pacientes[i].cpf);
            printf("IDADE: ");
            scanf("%d", &pacientes[i].idade);
            printf("MÉDICO RESPONSÁVEL: ");
            scanf("%d", &pacientes[i].idmed);
            printf("ESTADO DO PACIENTE: ");
            scanf("%d", &pacientes[i].estado);
        }
    default:
        break;
    }
}

int main()
{

    paciente pacientes[2];

    int num;
    printf("Olá, escolha uma das opções ou feche o programa\n\n 1 -- GESTÃO DE PACIENTES\n 2 -- GESTÃO DE MÉDICOS\n 3 -- FILA DE ATENDIMENTO\n 4 -- SAIR DO SISTEMA\n");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        gestaopac(pacientes);
        break;
    case 2:
        printf("Gestão de médicos.\n");
        break;
    case 3:
        printf("Fila de Atendimento.\n");
        break;
    case 4:
        printf("Você saiu do sistema.\n");
        return 0;
        system("pause");
    default:
        printf("Número inválido!");
        break;
    }
    return 0;
}