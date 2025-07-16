#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "medico.h"
#include "services/cadastrarmedico.h"
#include "services/consultarMedicos/consultarmedicos.h"
#include "../checkID.h"
#include "services/deletarMedico.h"
#include "services/atualizarMedico.h"

void gestaoMedicos(FILE *medicos)
{

  int num, currentId;
  currentId = checkID(medicos);
  printf("Você escolheu gestão de médicos! Escolha o que deseja fazer\n\n 1 -- CADASTRAR MÉDICO\n 2 -- CONSULTAR MÉDICO\n 3 -- ATUALIZAR MÉDICO\n 4 -- EXCLUIR MÉDICO");
  scanf("%d", &num);
  switch (num)
  {
  case 1:
    cadastrarMedico(currentId, medicos);
    break;
  case 2:
    consultarMedicos(medicos);
    break;
  case 3:
    atualizarMedico(medicos);
    break;
  case 4:
    deletarMedico(medicos);
    break;
  default:
    printf("Opção inválida.");
    break;
  }
}