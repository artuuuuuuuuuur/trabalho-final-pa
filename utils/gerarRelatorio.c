#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include "gestaoMedicosEPacientes.h"

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
  

  fclose(relatorio);
  printf("Relatório '%s' criado.", filename);
}
