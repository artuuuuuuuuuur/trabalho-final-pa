#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "medico.h"
#include "services/cadastrarmedico.h"
#include "services/consultarmedicos.h"

typedef struct medico
{
  int id;
  char nome[100];
  int crm;
  bool plantao;
} medico;

int checkID(FILE *medicos)
{
  char linha[100];
  char ultima_linha[100] = "";

  // Voltar o ponteiro do arquivo para o início
  rewind(medicos);

  // Lê linha por linha e guarda a última lida
  while (fgets(linha, sizeof(linha), medicos) != NULL)
  {
    strcpy(ultima_linha, linha);
  }

  // Lê a primeira coluna da última linha
  int id;
  sscanf(ultima_linha, "%d", &id);

  return id;
}

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
  default:
    break;
  }
}