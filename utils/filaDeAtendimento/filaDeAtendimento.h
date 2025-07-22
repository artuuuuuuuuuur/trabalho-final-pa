#include<stdio.h>

#ifndef FILADEATENDIMENTO_H
#define FILADEATENDIMENTO_H

void filaDeAtendimento(FILE *pacientes, FILE *medicos);
int extrairEstado(char *linha);

#endif