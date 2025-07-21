#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../paciente.h"
#include "../../checkID.h"

void atualizarPaciente(FILE *arquivoOriginal)
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
      printf("Erro ao abrir arquivo original.");
    }

    FILE *temp;
    temp = fopen("pacientes_temp.csv", "w");

    if (temp == NULL)
    {
      printf("Erro ao abrir arquivo temporário.");
    }
    // Voltar o ponteiro do arquivo para o início
    rewind(pacientes);
    printf("Digite o ID do paciente que deseja alterar: ");
    setbuf(stdin, NULL);
    gets(idDigitado);
    bool encontrouPaciente = false;

    printf("-----------------------------------------------------------------------\n\n");
    // Lê linha por linha
    while (fgets(linha, sizeof(linha), pacientes) != NULL)
    {
      char linhaCompleta[100];
      strcpy(linhaCompleta, linha);

      char id[100], nome[100], cpf[100], idade[100], idmed[100], estado[100];

      strcpy(id, strtok(linha, ","));
      strcpy(nome, strtok(NULL, ","));
      strcpy(cpf, strtok(NULL, ","));
      strcpy(idade, strtok(NULL, ","));
      strcpy(idmed, strtok(NULL, ","));
      strcpy(estado, strtok(NULL, ","));

      int medicoEncontrado = strcmp(id, idDigitado);

      if (medicoEncontrado == 0)
      {
        printf("Médico encontrado:\n");
        printf("[%s]\n  Nome: %s\n  CPF: %s\n  IDADE: %s\n  ID DO MÉDICO RESPONSÁVEL: %s\n  ESTADO: %s\n", id, nome, cpf, idade, idmed, estado);
        printf("----------------------------------------------------------------------\n");

        bool respostaCampo = false;
        int respostaOpcao;
        while (!respostaCampo)
        {
          printf("Escolha uma opção: \n  [1] -> Atualizar nome\n  [2] -> Atualizar Idade\n  [3] -> Alterar Médico Responsável\n  [4] -> Alterar Estado\n");
          scanf("%d", &respostaOpcao);

          switch (respostaOpcao)
          {
          case 1:
            char novoNome[100];

            setbuf(stdin, NULL);
            printf("Atualização de nome\n  Digite o nome desejado: ");
            setbuf(stdin, NULL);
            gets(novoNome);

            if (strcmp(novoNome, nome) == 0)
            {
              printf("Você não pode inserir o mesmo nome.");
            }
            else
            {
              strcpy(nome, novoNome);
              respostaCampo = true;
            }
            break;

          case 2:
            char novaIdade[100];
            printf("Atualização de idade\n  Digite a idade desejada: ");
            getchar();
            gets(novaIdade);

            if (strcmp(novaIdade, idade) == 0)
            {
              printf("Você não pode inserir a mesma idade.");
            }
            else
            {
              strcpy(idade, novaIdade);
              respostaCampo = true;
            }
            break;
          case 3:
            char novoIDMed[100];
            printf("Atualização de Médico Responsável\n  Digite o ID do Médico Responsável: ");
            getchar();
            gets(novoIDMed);

            if (strcmp(novoIDMed, idmed) == 0)
            {
              printf("Você não pode inserir o mesmo ID de Médico.");
            }
            else if (isMedicoExistente(novoIDMed) == 0)
            {
              strcpy(idmed, novoIDMed);
              respostaCampo = true;
            }
            else
            {
              printf("Medico não encontrado. Digite um ID válido.");
            }
            break;
          case 4:
            char novoEstado[2];
            printf("Atualização de estado\n  Digite o estado desejada: ");
            getchar();
            gets(novoEstado);

            if (strcmp(novoEstado, estado) == 0)
            {
              printf("Você não pode inserir o mesmo estado.");
            }
            else
            {
              strcpy(estado, novoEstado);
              respostaCampo = true;
            }
            break;
          default:
            printf("\nOpção inválida. Tente novamente.\n");
            break;
          }
        }

        fprintf(temp, "%s,%s,%s,%s,%s,%s", id, nome, cpf, idade, idmed, estado);
        encontrouPaciente = true;
      }
      else
      {
        linhaCompleta[strcspn(linhaCompleta, "\r\n")] = '\0';
        fprintf(temp, "%s\n", linhaCompleta);
      }
    }

    fclose(pacientes);
    fclose(temp);

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

    if (encontrouPaciente == false)
    {
      printf("Médico não encontrado no sistema.\n");
    }

    response = false;

    while (response == false)
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