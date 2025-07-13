#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void gerarRelatorio()
{
  FILE *relatorio;

  relatorio = fopen("relatorio.txt", "w");
  if (relatorio == NULL)
  {
    printf("NULOOO");
  }

  fputs("Hello World", relatorio);
  fclose(relatorio);
}
