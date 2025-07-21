#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct paciente
{
  int id;
  char nome[100];
  char cpf[12];
  int idade;
  int idmed;
  int estado;
} paciente;

void gestaoPacientes(FILE *pacientes);
void deletarPaciente(FILE *pacientes);
void atualizarPaciente(FILE *pacientes);
void consultarPacientes(FILE *pacientes);
void cadastrarPaciente(int currentID, FILE *pacientes);
void consultarPacientesGeral(FILE *pacientes);
void consultarPacientePorID(FILE *pacientes);

#endif