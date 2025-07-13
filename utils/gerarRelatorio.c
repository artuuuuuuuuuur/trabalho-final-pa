#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

void gerarRelatorio()
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
  
  fputs("Relatório Geral do Sistema XXXX\n", relatorio);
  fputs("- Total de Pacientes: \n", relatorio);
  fputs("- Total de Pacientes: ", relatorio);
  
  fclose(relatorio);
  printf("Relatório '%s' criado.", filename);
}
