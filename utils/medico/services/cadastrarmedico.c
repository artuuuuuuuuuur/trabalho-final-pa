#include <stdlib.h>
#include <stdio.h>
#include "../medico.h"
#include <stdbool.h>
#include <string.h>
#include "cadastrarmedico.h"

void cadastrarMedico(int currentId, FILE *medicos)
{
  printf("----- Cadastro de Médicos -------\n");
  bool cadastroBool = true;
  int i = 0;
  while (cadastroBool)
  {
    i++;
    medico medico;
    medico.id = currentId + i;
    bool isPlantao = false;
    char plantao;
    bool crm = false;

    printf("NOME: ");
    getchar();
    fgets(medico.nome, 100, stdin);
    medico.nome[strcspn(medico.nome, "\n")] = 0;

    while (!crm) {
      printf("CRM: ");
      char crmInput[6];
      gets(crmInput);
      

      if(strlen(crmInput) != 5) {
        printf("\nErro: O número CRM precisa ter exatamente 5 char. Tente novamente.\n");
        printf("%d\n", strlen(crmInput));
        printf("%s\n", crmInput);
      } else {
        strcpy(medico.crm, crmInput);
        crm = true;
      }
    }

    while (!isPlantao)
    {
      printf("\nEstá de Plantão? (S / N): ");
      plantao = fgetc(stdin);
      if (plantao == 'S' || plantao == 's')
      {
        medico.plantao = true;
        isPlantao = true;
      } else if (plantao == 'N' || plantao == 'n') {
          medico.plantao = false;
          isPlantao = true;
        } else {
        printf("Opção inválida. Digite S (Sim) ou N (Não)");
        } 
    }

    char cadastro;
    bool response = false;
    while (!response)
    {
      getchar();
      printf("\nDeseja cadastrar outro médico? (S / N): ");
      cadastro = fgetc(stdin);
        if (cadastro == 'S' || cadastro == 's')
        {
          cadastroBool = true;
          response = true;
        }
        else if (cadastro == 'N' || cadastro == 'n')
        {
          cadastroBool = false;
          response = true;
        }
      else
      {
        printf("Opção inválida. Digite S (Sim) ou N (Não)");
      }
    }

    fprintf(medicos, "%d,%s,%s,%s\n", medico.id, medico.nome, medico.crm, (medico.plantao == 1 ? "true" : "false"));
  }
}