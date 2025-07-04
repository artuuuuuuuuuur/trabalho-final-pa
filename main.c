#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

int main() {
    int num;
    printf("Olá, escolha uma das opções ou feche o programa\n\n 1 -- GESTÃO DE PACIENTES\n 2 -- GESTÃO DE MÉDICOS\n 3 -- FILA DE ATENDIMENTO\n 4 -- SAIR DO SISTEMA\n");
    scanf("%d",&num);
    while(true){
        switch (num) {
        case 1:
            printf("Gestão de pacientes.\n");
            break;
        case 2:
            printf("Gestão de médicos.\n");
            break;
        case 3:
            printf("Fila de Atendimento.\n");
            break;
        case 4:
            printf("Você saiu do sistema.\n");
            return 0;
            system("pause");
        default:
            printf("Número inválido!");
            break;
        }
    }
    return 0;
}