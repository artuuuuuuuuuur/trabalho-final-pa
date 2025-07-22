#ifndef GESTAOMEDICOSEPACIENTES_H
#define GESTAOMEDICOSEPACIENTES_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void menu(FILE *pacientes, FILE *medicos);
int checkID(FILE *arquivo);
int isMedicoExistente(char idInput[]);
void gerarRelatorio(FILE *medicos, FILE *pacientes);
int registerCount(FILE *arquivo, int estadoInput);

#endif