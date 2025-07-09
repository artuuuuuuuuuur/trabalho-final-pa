#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "medico.h"
#include "services/cadastrarmedico.h"

typedef struct medico
{
  int id;
  char nome[100];
  int crm;
  bool plantao;
} medico;

int medCount (FILE *medicos) {
   char num[500];
   int nume = 0;
   while(fgets(num,500,medicos)){
    nume++;
   }
   return nume-1;
}

void gestaoMedicos(FILE *medicos) {

  int num, currentId;
  currentId = medCount(medicos);
  printf("Você escolheu gestão de médicos! Escolha o que deseja fazer\n\n 1 -- CADASTRAR MÉDICO\n 2 -- CONSULTAR ID\n 3 -- ATUALIZAR MÉDICO\n 4 -- EXCLUIR MÉDICO");
  scanf("%d", &num);
  switch (num) {
  case 1: 
    cadastrarMedico(currentId, medicos);
    break;
  default:
    break;
  }
}