#include <stdlib.h>
#include <stdio.h>
#include "../medico.h"
#include <stdbool.h>
#include <string.h>
#include "cadastrarmedico.h"

typedef struct medico
{
  int id;
  char nome[100];
  int crm;
  bool plantao;
} medico;


void cadastrarMedico(int currentId, FILE *medicos) {
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
}