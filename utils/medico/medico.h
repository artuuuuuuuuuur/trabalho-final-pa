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
void cadastrarMedico(int currentId, FILE *medicos);
void deletarMedico(FILE *arquivoOriginal);
void atualizarMedico(FILE *arquivoOriginal);
void consultarMedicos(FILE *medicos);
void consultarMedicosGeral(FILE *medicos);
void consultarMedicoPorID(FILE *medicos);
int checarPacientesDoMedico(FILE *pacientes, int idmed, FILE *arquivoDestino);

#endif