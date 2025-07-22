#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include "gestaoMedicosEPacientes.h"
#include "medico/medico.h"


void gerarRelatorio(FILE *medicos, FILE *pacientes)
{
  FILE *relatorio;
  time_t now = time(NULL);
  struct tm *t = localtime(&now);

  char year[5];
  char month[3];
  char day[3];

  sprintf(year, "%d", (t->tm_year + 1900));
  sprintf(month, "%d", (t->tm_mon + 1));
  sprintf(day, "%d", t->tm_mday);

  char filename[30] = "relatorio_";

  strcat(filename, day);
  strcat(filename, "-");
  strcat(filename, month);
  strcat(filename, "-");
  strcat(filename, year);

  strcat(filename, ".txt");

  relatorio = fopen(filename, "w");
  if (relatorio == NULL)
  {
    printf("Não foi possível executar a tarefa.");
  }

  fputs("Relatório Geral do Sistema FYKA Med\n", relatorio);
  fputs("\n- Total de Pacientes Cadastrados no Sistema: ", relatorio);
  fprintf(relatorio, "%d\n", registerCount(pacientes, -1));
  fputs("  - Internados: ", relatorio);
  fprintf(relatorio, "%d\n", registerCount(pacientes, 3));
  fputs("  - Em Alta: ", relatorio);
  fprintf(relatorio, "%d\n", registerCount(pacientes, 0));
  fputs("  - Atendidos: ", relatorio);
  fprintf(relatorio, "%d\n", (registerCount(pacientes, 2) + registerCount(pacientes, 1)));

  fputs("\n- Pacientes por Estado: \n", relatorio);
  fputs("  - Leve: ", relatorio);
  fprintf(relatorio, "%d\n", registerCount(pacientes, 1));
  fputs("  - Moderado: ", relatorio);
  fprintf(relatorio, "%d\n", registerCount(pacientes, 2));
  fputs("  - Grave (INTERNAÇÃO): ", relatorio);
  fprintf(relatorio, "%d\n", registerCount(pacientes, 3));

  fputs("\n- Total de Médicos Cadastrados no Sistema: ", relatorio);
  fprintf(relatorio, "%d\n", registerCount(medicos, -1));
  
  fputs("\n- Lista Completa de Médicos: ", relatorio);
  fputs("\n----------------------------------------\n\n", relatorio);
  rewind(medicos);
  char linhaMedico[200];
  while (fgets(linhaMedico, sizeof(linhaMedico), medicos) != NULL)
  {
    if (strcmp(linhaMedico, "id,nome,crm,plantao\n") != 0)
    {
      char id[100];
      char nome[100];
      char crm[100];
      char plantao[100];
      strcpy(id, strtok(linhaMedico, ","));
      strcpy(nome, strtok(NULL, ","));
      strcpy(crm, strtok(NULL, ","));
      strcpy(plantao, strtok(NULL, ","));

      fprintf(relatorio, "  ID %s,\n  Nome: %s,\n  CRM: %s,\n  Plantão: %s", id, nome, crm, plantao);
      FILE *pacientes = fopen("pacientes.csv", "r");
      checarPacientesDoMedico(pacientes, atoi(id), relatorio);
      fclose(pacientes);
      fprintf(relatorio, "  -----\n\n");
    }
  }

  fclose(relatorio);
  printf("Relatório '%s' criado.", filename);
}
