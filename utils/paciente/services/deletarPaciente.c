#include "deletarPaciente.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void deletarPaciente(FILE *arquivoOriginal)
{

  // fecha o arquivo original para evitar bugs
  fclose(arquivoOriginal);

  char linha[100];
  char idDigitado[100];
  bool isPacienteEncontrado = false;
  bool response = false;

  while (!isPacienteEncontrado)
  {
    FILE *pacientes;
    pacientes = fopen("pacientes.csv", "r");

    if (pacientes == NULL)
    {
      printf("Erro ao abrir arquivo temporário.");
    }

    FILE *temp;
    temp = fopen("pacientes_temp.csv", "w");

    if (temp == NULL)
    {
      printf("Erro ao abrir arquivo temporário.");
    }
    // Voltar o ponteiro do arquivo para o início
    rewind(pacientes);
    printf("Digite o ID do paciente que deseja deletar: ");
    setbuf(stdin, NULL);
    gets(idDigitado);

    printf("-----------------------------------------------------------------------\n\n");
    // Lê linha por linha
    while (fgets(linha, sizeof(linha), pacientes) != NULL)
    {
      char linhaCompleta[100];
      strcpy(linhaCompleta, linha);
      char id[100];
      strcpy(id, strtok(linha, ","));

      int pacienteEncontrado = strcmp(id, idDigitado);

      if (pacienteEncontrado == 0)
      {
        isPacienteEncontrado = true;
      }
      else
      {
        if (strcmp(linhaCompleta, "\n") != 0)
        {
          fprintf(temp, linhaCompleta);
        }
      }
    }

    if (fclose(pacientes) != 0)
      perror("Erro ao fechar pacientes.csv");
    if (fclose(temp) != 0)
      perror("Erro ao fechar pacientes_temp.csv");

    if (remove("pacientes.csv") != 0)
    {
      perror("Erro ao remover pacientes.csv");
    }
    else
    {
      printf("Arquivo removido com sucesso.\n");
    }

    if (rename("pacientes_temp.csv", "pacientes.csv") != 0)
    {
      perror("Erro ao renomear pacientes_temp.csv para pacientes.csv");
    }
    else
    {
      printf("Arquivo renomeado com sucesso.\n");
    }

    if (isPacienteEncontrado == false)
    {
      printf("Paciente não encontrado. Tente novamente.\n");
    }

    fclose(pacientes);
    fclose(temp);
    // remove("pacientes_temp.csv");

    response = false;
    while (!response)
    {
      setbuf(stdin, NULL);
      char res;
      printf("Deseja procurar por outro ID? (S / N)");
      res = getc(stdin);

      if (res == 'S' || res == 's')
      {
        isPacienteEncontrado = false;
        response = true;
        break;
      }
      else if (res == 'N' || res == 'n')
      {
        isPacienteEncontrado = true;
        response = true;
        break;
      }

      else
      {
        printf("Opção inválida. Digite S (Sim) ou N (Não)\n");
      }
    }
  }
}