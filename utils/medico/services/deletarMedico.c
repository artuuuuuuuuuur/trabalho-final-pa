#include "deletarMedico.h"
#include <stdbool.h> 
#include <string.h> 
#include <stdlib.h> 
#include <stdio.h> 

// A FAZER
//  - criar condicionais para deletar médico
//    EX.: verificar se o médico possui pacientes antes da deleção e não permitir que o user exclua se houver.

void deletarMedico(FILE *arquivoOriginal) {

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
    printf("Erro ao abrir arquivo temporário.");
  }
  
  FILE *temp;
  temp = fopen("medicos_temp.csv", "w");
  
  if (temp == NULL) {
    printf("Erro ao abrir arquivo temporário.");
  }
    // Voltar o ponteiro do arquivo para o início
    rewind(medicos);
    printf("Digite o ID do médico que deseja deletar: ");
    setbuf(stdin, NULL);
    gets(idDigitado);

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
      } else {
          if(strcmp(linhaCompleta, "\n") != 0) {
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
      printf("Médico não encontrado. Tente novamente.\n");
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