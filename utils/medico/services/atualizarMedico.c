#include "atualizarMedico.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../medico.h"

// A FAZER
// - exibir informações do médico desejado (para confirmação) antes de alterar
// - retornar "Plantão já é 'false' ou 'true'" caso o user digite o mesmo valor do original
// - implementar alteração de nome

void atualizarMedico(FILE *arquivoOriginal) {
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
  
  if (medicos == NULL) {
    printf("Erro ao abrir arquivo original.");
  }
  
  FILE *temp;
  temp = fopen("medicos_temp.csv", "w");
  
  if (temp == NULL) {
    printf("Erro ao abrir arquivo temporário.");
  }
    // Voltar o ponteiro do arquivo para o início
    rewind(medicos);
    printf("Digite o ID do médico que deseja alterar: ");
    setbuf(stdin, NULL);
    gets(idDigitado);

    printf("-----------------------------------------------------------------------\n\n");
    // Lê linha por linha
    while (fgets(linha, sizeof(linha), medicos) != NULL)
    {
      medico medicoAtualizado;
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
        char res;
        bool response = false;
        
        while (!response) {
          setbuf(stdin, NULL);
          printf("Atualização de plantão\n  O médico está de plantão? (S / N)\n");
          res = fgetc(stdin);
          switch (res) {
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
        
        fprintf(temp, "%s,%s,%s,%s\n", id, nome, crm, (plantaoAtualizado == 1 ? "true" : "false"));
        
      } else {
          if(strcmp(linhaCompleta, "\n") != 0) {
            fprintf(temp, linhaCompleta);
          } 
        }
      
    }
    

    fclose(medicos);
    fclose(temp);
    
    
  if (fclose(medicos) != 0) perror("Erro ao fechar medicos.csv");
if (fclose(temp) != 0) perror("Erro ao fechar medicos_temp.csv");

if (remove("medicos.csv") != 0) {
    perror("Erro ao remover medicos.csv");
} else {
    printf("Arquivo removido com sucesso.\n");
}

if (rename("medicos_temp.csv", "medicos.csv") != 0) {
    perror("Erro ao renomear medicos_temp.csv para medicos.csv");
} else {
    printf("Arquivo renomeado com sucesso.\n");
}


    if (isMedicoEncontrado == false)
    {
      printf("Médico alterado com sucesso.\n");
    }

    response = false;

    while (!response)
    {
      setbuf(stdin, NULL);
      char res;
      printf("Deseja procurar por outro ID? (S / N)");
      res = getc(stdin);

      if (res == 'S' || res == 's' || res == 'N' || res == 'n')
      {
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
      }
      else
      {
        printf("Opção inválida. Digite S (Sim) ou N (Não)\n");
      }
    }
    }
}