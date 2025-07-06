#ifndef MEDICO_H
#define MEDICO_H

typedef struct medico
{
  int id;
  char nome[100];
  int crm;
  bool plantao;
} medico;

void gestaoMedicos(medico medicos[]);

#endif 