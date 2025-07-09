#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct medico
{
    int id;
    char nome[30];
    int idade;
    int idmed;
    int estado;
}MEDICO;
int medcount ()
{
   char num[500];
   int nume = 0;
   FILE *fptr;
   fptr = fopen("C:\\Users\\Public\\Documents\\Trabalho\\Medicos\\medico","r");
   while(fgets(num,500,fptr)){
    nume++;
   }
   fclose(fptr);
   return nume;
}
void main()
{
    char str[100];
    MEDICO medico[1000];
    int nummed = medcount();
    FILE *fptr;
    fptr = fopen("C:\\Users\\Public\\Documents\\Trabalho\\Medicos\\medico","r");
    for(int i=0;i<nummed;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-2;
        if(str[strle]=='3'){
            printf("%s",str);
        }
    }
    for(int i=0;i<nummed;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-2;
        if(str[strle]=='2'){
            printf("%s",str);
        }
    }
    for(int i=0;i<nummed;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-2;
        if(str[strle]=='1'){
            printf("%s",str);
        }
    }
    fclose(fptr);
}