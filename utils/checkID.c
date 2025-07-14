#include "checkID.h"

int checkID(FILE *arquivo) {
  char linha[100];
  char ultima_linha[100] = "";

  // Voltar o ponteiro do arquivo para o início
  rewind(arquivo);

  // Lê linha por linha e guarda a última lida
  while (fgets(linha, sizeof(linha), arquivo) != NULL)
  {
    strcpy(ultima_linha, linha);
  }

  // Lê a primeira coluna da última linha
  int id;
  sscanf(ultima_linha, "%d", &id);

  return id;
}