#include <stdio.h>
#include "cadastrarPaciente.h"
#include "../paciente.h"
#include <stdbool.h>
#include <string.h>

void cadastrarPaciente(int currentID, FILE *pacientes) {
  printf("----- Cadastro de Pacientes -------\n");
  bool cadastroBool = true;
  int i = 0;
  bool isEstado = false;
  int estado;
  while (cadastroBool) {
    i++;
    paciente paciente;
    paciente.id = currentID + i;

    printf("NOME: ");
    getchar();
    fgets(paciente.nome, 100, stdin);
    paciente.nome[strcspn(paciente.nome, "\n")] = 0;

    printf("CPF: ");
    scanf("%d", &paciente.cpf);
    
    printf("IDADE: ");
    scanf("%d", &paciente.idade);
    
    printf("MÉDICO RESPONSAVEL: ");
    scanf("%d", &paciente.idmed);
   
    while (!isEstado)
    { 
        printf("ESTADO DO PACIENTE: \n  [1] Leve\n  [2] Moderado\n  [3] Grave");
        scanf("%d", &estado);
      
        switch (estado)
        {
        case 1:
            paciente.estado = estado;
            isEstado = true;
            break;
        case 2:
            paciente.estado = estado;
            isEstado = true;
            break;
        case 3:
            paciente.estado = estado;
            isEstado = true;
            break;
        
        default:
            printf("Opção inválida. Digite [1] -> Leve, [2] -> Moderado, [3] -> Grave.");
            break;
        }
      }
    

   char cadastro;
   bool response = false;
   while (!response) {
     getchar();
     printf("\nDeseja cadastrar outro paciente? (S / N): ");
     scanf("%c", cadastro);
     if (cadastro == 'S' || cadastro == 's' || cadastro == 'N' || cadastro == 'n')
     {
       if (cadastro == 'S' || cadastro == 's')
       {
         cadastroBool = true;
         response = true;
       }
       else if (cadastro == 'N' || cadastro == 'n')
       {
         cadastroBool = false;
         response = true;
       }
     }
     else
     {
       printf("Opção inválida. Digite S (Sim) ou N (Não)");
     }
   }

    fprintf(pacientes, "\n%d,%s,%d,%d,%d,%d", paciente.id, paciente.nome, paciente.cpf, paciente.idade, paciente.idmed, paciente.estado);
  }
}