#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct paciente
{
  int id;
  char nome[100];
  int cpf;
  int idade;
  int idmed;
  int estado;
} paciente;

void gestaoPacientes(paciente pacientes[]);

#endif