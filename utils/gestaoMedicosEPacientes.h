#ifndef GESTAOMEDICOSEPACIENTES_H
#define GESTAOMEDICOSEPACIENTES_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int checkID(FILE *arquivo);
int isMedicoExistente(char idInput[]);
void gerarRelatorio(FILE *medicos, FILE *pacientes);
int registerCount(FILE *arquivo, int estadoInput);

#endif