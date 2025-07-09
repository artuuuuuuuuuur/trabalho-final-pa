#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "medico.h"
#include <stdlib.h>

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
  switch (num)
  {
  case 1:
    printf("----- Cadastro de Médicos -------");
    for (int i = 1; i < 4; i++)
    {
      medico medico;
      medico.id = currentId + i;
      bool isPlantao = false;
      char plantao[1];
      printf("---- Médico %d -----\n", i);

      printf("NOME: ");
      getchar();
      fgets(medico.nome, 100, stdin);
      medico.nome[strcspn(medico.nome, "\n")] = 0;

      printf("CRM: ");
      scanf("%d", &medico.crm);

      while (!isPlantao)
      {
        printf("\nEstá de Plantão? (S / N): ");
        scanf(" %1s", plantao);
        if (plantao[0] == 'S' || plantao[0] == 's' || plantao[0] == 'N' || plantao[0] == 'n')
        {
          if (plantao[0] == 'S' || plantao[0] == 's')
          {
            medico.plantao = true;
            isPlantao = true;
          }
          else if (plantao[0] == 'N' || plantao[0] == 'n')
          {
            medico.plantao = false;
            isPlantao = true;
          }
        }
        else
        {
          printf("Opção inválida. Digite S (Sim) ou N (Não)");
        }
      }

      fprintf(medicos, "\n%d, %s, %d, %s", medico.id, medico.nome, medico.crm,  (medico.plantao == 1 ? "true" : "false"));
    }
  default:
    break;
  }
}