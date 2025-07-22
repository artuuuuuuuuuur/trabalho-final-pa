#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../medico.h"
#include <windows.h>

void atualizarMedico(FILE *arquivoOriginal)
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
      printf("Erro ao abrir arquivo original.");
    }

    FILE *temp;
    temp = fopen("medicos_temp.csv", "w");

    if (temp == NULL)
    {
      printf("Erro ao abrir arquivo temporário.");
    }
    // Voltar o ponteiro do arquivo para o início
    rewind(medicos);
    printf("Digite o ID do médico que deseja alterar: ");
    setbuf(stdin, NULL);
    gets(idDigitado);
    bool encontrouMedico = false;

    printf("-----------------------------------------------------------------------\n\n");
    // Lê linha por linha
    while (fgets(linha, sizeof(linha), medicos) != NULL)
    {
      char linhaCompleta[100];
      strcpy(linhaCompleta, linha);

      char id[100];
      char nome[100];
      char crm[100];
      char plantao[100];
      int plantaoAtualizado;

      strcpy(id, strtok(linha, ","));
      strcpy(nome, strtok(NULL, ","));
      strcpy(crm, strtok(NULL, ","));
      strcpy(plantao, strtok(NULL, ","));

      int medicoEncontrado = strcmp(id, idDigitado);

      if (medicoEncontrado == 0)
      {
        printf("Médico encontrado:\n");
        printf("[%s]\n  Nome: %s\n  CRM: %s\n  Plantão: %s\n", id, nome, crm, plantao);
        printf("----------------------------------------------------------------------\n");

        bool respostaCampo = false;
        int respostaOpcao;
        while (!respostaCampo)
        {
          printf("Escolha uma opção: \n  [1] -> Atualizar nome\n  [2] -> Atualizar Plantão\n");
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
            char novoPlantao;
            bool response = false;

            while (!response)
            {
              setbuf(stdin, NULL);
              printf("Atualização de plantão\n  O médico está de plantão? (S / N)\n");
              novoPlantao = fgetc(stdin);
              switch (novoPlantao)
              {
              case 'S':
                response = true;
                plantaoAtualizado = 1;
                break;
              case 'N':
                response = true;
                plantaoAtualizado = 0;
                break;
              case 's':
                response = true;
                plantaoAtualizado = 1;
                break;
              case 'n':
                response = true;
                plantaoAtualizado = 0;
                break;
              default:
                printf("Opção inválida. Digite (S -> SIM ou N -> NÃO).");
                break;
              }
            }
            respostaCampo = true;
          default:
            printf("\nOpção inválida. Tente novamente.\n");
            break;
          }
        }

        fprintf(temp, "%s,%s,%s,%s\n", id, nome, crm, (plantaoAtualizado == 1 ? "true" : "false"));
        encontrouMedico = true;
      }
      else
      {

        fprintf(temp, linhaCompleta);
      }
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

    if (encontrouMedico == false)
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