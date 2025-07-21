#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../../checkID.h"
#include "../paciente.h"

void cadastrarPaciente(int currentID, FILE *pacientes)
{
  printf("----- Cadastro de Pacientes -------\n");
  bool cadastroBool = true;
  int i = 0;

  while (cadastroBool)
  {
    i++;
    paciente paciente;
    paciente.id = currentID + i;

    bool isEstado = false;
    bool cpf = false;

    printf("NOME: ");
    getchar();
    fgets(paciente.nome, 100, stdin);
    paciente.nome[strcspn(paciente.nome, "\n")] = 0;

    while (!cpf)
    {
      printf("CPF: ");
      char cpfInput[12];
      gets(cpfInput);

      if (strlen(cpfInput) != 11)
      {
        printf("\nErro: O CPF precisa ter exatamente 11 char. Tente novamente.\n");
        printf("%d\n", strlen(cpfInput));
        printf("%s\n", cpfInput);
      }
      else
      {
        strcpy(paciente.cpf, cpfInput);
        cpf = true;
      }
    }

    printf("IDADE: ");
    scanf("%d", &paciente.idade);

    bool idMedEncontrado = false;
    while (!idMedEncontrado)
    {
      printf("MÉDICO RESPONSAVEL: ");
      char linha[100];
      int idInput;
      char idString[100];
      scanf("%d", &idInput);

      sprintf(idString, "%d", idInput);

      if (idInput != NULL && isMedicoExistente(idString) == 0)
      {
        paciente.idmed = idInput;
        idMedEncontrado = true;
      }

      if (idMedEncontrado == false)
      {
        printf("Médico não encontrado. Tente novamente.\n");
      }
    }

    while (!isEstado)
    {
      printf("ESTADO DO PACIENTE: \n  [0] De Alta\n  [1] Leve\n  [2] Moderado\n  [3] Grave\n");
      int estado;
      scanf("%d", &estado);

      switch (estado)
      {
      case 0:
        paciente.estado = estado;
        isEstado = true;
        break;
      case 1:
        paciente.estado = estado;
        isEstado = true;
        break;
      case 2:
        paciente.estado = estado;
        isEstado = true;
        break;
      case 3:
        paciente.estado = estado;
        isEstado = true;
        break;

      default:
        printf("Opção inválida. Digite [0] -> Alta, [1] -> Leve, [2] -> Moderado, [3] -> Grave.");
        break;
      }
    }

    char cadastro[2];
    bool response = false;
    while (!response)
    {
      getchar();
      printf("\nDeseja cadastrar outro paciente? (S / N): ");
      scanf("%c", cadastro);
      if (cadastro[0] == 'S' || cadastro[0] == 's')
      {
        cadastroBool = true;
        response = true;
      }
      else if (cadastro[0] == 'N' || cadastro[0] == 'n')
      {
        cadastroBool = false;
        response = true;
      }
      else
      {
        printf("Opção inválida. Digite S (Sim) ou N (Não)");
      }
    }
    fprintf(pacientes, "%d,%s,%s,%d,%d,%d\n", paciente.id, paciente.nome, paciente.cpf, paciente.idade, paciente.idmed, paciente.estado);
  }
}