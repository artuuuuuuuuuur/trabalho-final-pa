#ifndef MEDICO_H
#define MEDICO_H
#include <stdbool.h>
#include <stdio.h>

typedef struct medico
{
  int id;
  char nome[100];
  char crm[6];
  bool plantao;
} medico;

void gestaoMedicos(FILE *medicos);

#endif 