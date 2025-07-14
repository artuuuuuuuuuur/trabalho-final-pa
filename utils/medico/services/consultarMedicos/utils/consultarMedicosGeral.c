#include"consultarMedicosGeral.h"
#include<stdio.h>
#include<string.h>
#include"../../../medico.h"

void consultarMedicosGeral(FILE *medicos) {
    char linha[100];

  // Voltar o ponteiro do arquivo para o início
  rewind(medicos);


  printf("-------------------------- Lista Geral de Médicos --------------------------\n\n");
  // Lê linha por linha
  while (fgets(linha, sizeof(linha), medicos) != NULL) {
    if (strcmp(linha, "id,nome,crm,plantao\n") != 0) {
        char id[100];
        char nome[100];
        char crm[100];
        char plantao[100];
        strcpy(id,strtok(linha, ","));
        strcpy(nome, strtok(NULL, ","));
        strcpy(crm, strtok(NULL, ","));
        strcpy(plantao, strtok(NULL, ","));

        printf("[%s]\n  Nome: %s\n  CRM: %s\n  Plantão: %s\n", id, nome, crm, plantao);
        printf("----------------------------------------------------------------------\n");
    }
  }
}