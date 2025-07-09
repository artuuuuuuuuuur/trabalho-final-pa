#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
//Struct que eu ainda não usei e tá montada errada
typedef struct medico
{
    int id;
    char nome[30];
    int idade;
    int idmed;
    int estado;
}MEDICO;
//Função de contar a quantidade de médicos
int medcount ()
{
   char num[500];
   int nume = 0;
   FILE *fptr;
    //Trocar nome para só "medico" porque isso tá apontando pra um diretório no meu pc
   fptr = fopen("C:\\Users\\Public\\Documents\\Trabalho\\Medicos\\medico","r");
   while(fgets(num,500,fptr)){
    nume++;
   }
   fclose(fptr);
   return nume;
}
//Função principal
void main()
{
    char str[100];
    MEDICO medico[1000];
    int nummed = medcount();
    FILE *fptr;
     //Trocar nome para só "medico" porque isso tá apontando pra um diretório no meu pc
    fptr = fopen("C:\\Users\\Public\\Documents\\Trabalho\\Medicos\\medico","r");
    //Função muito ineficiente para postar os médicos por ordem de estado mas foi a única coisa que consegui pensar
    for(int i=0;i<nummed;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-2;
        if(str[strle]=='3'){
            printf("INTERNACAO IMEDIATA! --> %s",str);
        }
    }
    fclose(fptr);
    fptr = fopen("C:\\Users\\Public\\Documents\\Trabalho\\Medicos\\medico","r");
    for(int i=0;i<nummed;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-2;
        if(str[strle]=='2'){
            printf("%s",str);
        }
    }
    fclose(fptr);
    fptr = fopen("C:\\Users\\Public\\Documents\\Trabalho\\Medicos\\medico","r");
    for(int i=0;i<nummed;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-2;
        if(str[strle]=='1'){
            printf("%s",str);
        }
    }
    fclose(fptr);
}
