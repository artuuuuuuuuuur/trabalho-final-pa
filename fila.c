#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
//Checar quantidade de medicos
int medcount ()
{
   char num[500];
   int nummed = 0;
   FILE *fptr;
   fptr = fopen("paciente","r");
   while(fgets(num,500,fptr)){
    nummed++;
   }
   fclose(fptr);
   return nummed;
}
void main()
{
    char str[100];
    int nummed = medcount();
    FILE *fptr;
    FILE *forg;
    fptr = fopen("paciente","r");
    //Forg vai ser usado pra criar um novo arquivo de texto com os pacientes organizados em ordem de estado
    forg = fopen("pacienteorganizado","w");
    for(int i=0;i<nummed;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-2;
        if(str[strle]=='3'){
            printf("\033[31mINTERNACAO IMEDIATA! -->\033[0m %s",str);
            fprintf(forg,"INTERNAÇÃO IMEDIATA! %s",str);
        }
    }
    fclose(forg);
    fclose(fptr);
    forg = fopen("pacienteorganizado","a");
    fptr = fopen("paciente","r");
    for(int i=0;i<nummed;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-2;
        if(str[strle]=='2'){
            printf("%s",str);
            fprintf(forg,"%s",str);
        }
    }
    fclose(forg);
    fclose(fptr);
    forg = fopen("pacienteorganizado","a");
    fptr = fopen("paciente","r");
    for(int i=0;i<nummed;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-2;
        if(str[strle]=='1'){
            printf("%s",str);
            fprintf(forg,"%s",str);
        }
    }
    fclose(forg);
    fclose(fptr);
}
