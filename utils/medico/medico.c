#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "medico.h"
#include "../gestaoMedicosEPacientes.h"
#include <windows.h>

void gestaoMedicos(FILE *medicos, FILE *pacientes)
{
  system("cls");
  int num, currentId;
  bool res = false;
  currentId = checkID(medicos);
  printf("Você escolheu gestão de médicos! Escolha o que deseja fazer\n\n 1 -- CADASTRAR MÉDICO\n 2 -- CONSULTAR MÉDICO\n 3 -- ATUALIZAR MÉDICO\n 4 -- EXCLUIR MÉDICO\n 5 -- VOLTAR PARA O MENU ANTERIOR\n\n");
  scanf("%d", &num);

  while (!res)
  {
    switch (num)
    {
    case 1:
      cadastrarMedico(currentId, medicos);
      res = true;
      break;
    case 2:
      consultarMedicos(medicos);
      res = true;
      break;
    case 3:
      atualizarMedico(medicos);
      res = true;
      break;
    case 4:
      deletarMedico(medicos);
      res = true;
      break;
    case 5:
      menu(pacientes, medicos);
      res = true;
      break;
    default:
      printf("Opção inválida.");
      break;
    }
  }
}