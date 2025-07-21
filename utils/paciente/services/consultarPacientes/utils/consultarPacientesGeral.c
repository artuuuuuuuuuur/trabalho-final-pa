#include<stdio.h>
#include<string.h>
#include"../../../paciente.h"

void consultarPacientesGeral(FILE *pacientes) {
    char linha[100];

  // Voltar o ponteiro do arquivo para o início
  rewind(pacientes);


  printf("-------------------------- Lista Geral de Pacientes --------------------------\n\n");
  // Lê linha por linha
  while (fgets(linha, sizeof(linha), pacientes) != NULL) {
    if (strcmp(linha, "id,nome,cpf,idade,idmed,estado\n") != 0) {
        char id[100];
        char nome[100];
        char cpf[100];
        char idade[100];
        char idmed[100];
        char estado[100];
        strcpy(id,strtok(linha, ","));
        strcpy(nome, strtok(NULL, ","));
        strcpy(cpf, strtok(NULL, ","));
        strcpy(idade, strtok(NULL, ","));
        strcpy(idmed, strtok(NULL, ","));
        strcpy(estado, strtok(NULL, ","));

        printf("[%s]\n  Nome: %s\n  CPF: %s\n  IDADE: %s\n  ID DO MÉDICO RESPONSÁVEL: %s\n  ESTADO: %s\n", id, nome, cpf, idade, idmed, estado);
        printf("----------------------------------------------------------------------\n");
    }
  }
}