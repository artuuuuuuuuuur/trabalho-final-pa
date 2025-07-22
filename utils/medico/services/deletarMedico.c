#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../medico.h"
#include <windows.h>

int checkIdMed(char id[])
{

  // Abre o arquivo pacientes.csv
  FILE *arquivoPacientes = fopen("pacientes.csv", "r");

  // Testa se abriu corretamente
  if (arquivoPacientes == NULL)
  {
    printf("Erro ao abrir arquivo de pacientes.");
  }

  // Cria uma variável para armazenar uma linha do arquivo
  char linha[100];

  // É verdadeiro caso um paciente com o IDMED igual ao ID recebido seja encontrado
  bool isPacienteEncontrado = false;

  while (fgets(linha, sizeof(linha), arquivoPacientes) != NULL)
  {
    if (strcmp(linha, "id,nome,cpf,idade,idmed,estado\n") != 0)
    {
      char idPaciente[100];
      char nome[100];
      char cpf[100];
      char idade[100];
      char idmed[100];
      char estado[100];
      strcpy(idPaciente, strtok(linha, ","));
      strcpy(nome, strtok(NULL, ","));
      strcpy(cpf, strtok(NULL, ","));
      strcpy(idade, strtok(NULL, ","));
      strcpy(idmed, strtok(NULL, ","));
      strcpy(estado, strtok(NULL, ","));

      int medicoEncontrado = strcmp(idmed, id);

      if (medicoEncontrado == 0)
      {
        printf("Você não pode deletar o médico %s, pois precisa alterar o médico responsável por esses pacientes: \n", id);
        printf("[%s]\n  Nome: %s\n  CPF: %s\n  ESTADO: %s\n", idPaciente, nome, cpf, estado);
        printf("----------------------------------------------------------------------\n");
        isPacienteEncontrado = true;
        printf("Vá para a gestão de pacientes e altere os médicos responsáveis.\n");
      }
      else
      {
      }
    }
  }
  if (isPacienteEncontrado == false)
  {
    printf("\nProsseguindo para a deleção...\n");
    fclose(arquivoPacientes);
    return 0;
  }
  else
  {
    fclose(arquivoPacientes);
    return 1;
  }
}

void deletarMedico(FILE *arquivoOriginal)
{
  system("cls");

  // fecha o arquivo original para evitar bugs
  fclose(arquivoOriginal);

  char linha[100];
  char idDigitado[100];
  bool isMedicoEncontrado = false;
  bool response = false;

  while (!isMedicoEncontrado)
  {
    FILE *medicos;
    medicos = fopen("medicos.csv", "r");

    if (medicos == NULL)
    {
      printf("Erro ao abrir arquivo temporário.");
    }

    FILE *temp;
    temp = fopen("medicos_temp.csv", "w");

    if (temp == NULL)
    {
      printf("Erro ao abrir arquivo temporário.");
    }
    // Voltar o ponteiro do arquivo para o início
    rewind(medicos);
    printf("Digite o ID do médico que deseja deletar: ");
    setbuf(stdin, NULL);
    gets(idDigitado);

    if (checkIdMed(idDigitado) == 0)
    {
      printf("-----------------------------------------------------------------------\n\n");
      // Lê linha por linha
      while (fgets(linha, sizeof(linha), medicos) != NULL)
      {
        char linhaCompleta[100];
        strcpy(linhaCompleta, linha);
        char id[100];
        strcpy(id, strtok(linha, ","));

        int medicoEncontrado = strcmp(id, idDigitado);

        if (medicoEncontrado == 0)
        {
          isMedicoEncontrado = true;
        }
        else
        {
          if (strcmp(linhaCompleta, "\n") != 0)
          {
            fprintf(temp, linhaCompleta);
          }
        }
      }

      rewind(medicos);
      while (fgets(linha, sizeof(linha), medicos) != NULL)
      {
        char linhaCompleta[100];
      }

      fclose(medicos);
      fclose(temp);

      if (fclose(medicos) != 0)
        perror("Erro ao fechar medicos.csv");
      if (fclose(temp) != 0)
        perror("Erro ao fechar medicos_temp.csv");

      if (remove("medicos.csv") != 0)
      {
        perror("Erro ao remover medicos.csv");
      }
      else
      {
        printf("Arquivo removido com sucesso.\n");
      }

      if (rename("medicos_temp.csv", "medicos.csv") != 0)
      {
        perror("Erro ao renomear medicos_temp.csv para medicos.csv");
      }
      else
      {
        printf("Arquivo renomeado com sucesso.\n");
      }

      if (isMedicoEncontrado == false)
      {
        printf("Médico não encontrado. Tente novamente.\n");
      }
    }
    else
    {
      fclose(medicos);
      fclose(temp);
      remove("medicos_temp.csv");
    }
    response = false;
    while (!response)
    {
      setbuf(stdin, NULL);
      char res;
      printf("Deseja procurar por outro ID? (S / N)");
      res = getc(stdin);

      if (res == 'S' || res == 's')
      {
        isMedicoEncontrado = false;
        response = true;
        break;
      }
      else if (res == 'N' || res == 'n')
      {
        isMedicoEncontrado = true;
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