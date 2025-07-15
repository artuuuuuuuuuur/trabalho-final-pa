#include "deletarMedico.h"
#include <stdbool.h> 
#include <string.h> 
#include <stdlib.h> 
#include <stdio.h> 


void deletarMedico(FILE *medicos) {
  FILE *temp;
  temp = fopen("medicos_temp.csv", "w");
  
  if (temp == NULL) {
    printf("Erro ao abrir arquivo temporário.");
  }
  

  char linha[100];
  char idDigitado[100];
  bool isMedicoEncontrado = false;
  bool response = false;

  while (!isMedicoEncontrado)
  {
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
        printf("Médico encontrado:\n");
        printf("----------------------------------------------------------------------\n");
        isMedicoEncontrado = true;
      } else {
          fprintf(temp, linhaCompleta);
          remove("medicos.csv");
          rename("medicos_temp.csv", "medicos.csv");
        }
      
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

    fclose(temp);
}