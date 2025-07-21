#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Checar quantidade de medicos
int paccount ()
{
   char num[500];
   int numpac = 0;
   FILE *fptr;
   fptr = fopen("paciente","r");
   while(fgets(num,500,fptr)){
    numpac++;
   }
   fclose(fptr);
   return numpac;
}
//Essa função aqui vai receber um tipo FILE POINTER, que no caso é o que tá apontando pro arquivo de texto pra paciente
//É pra ver se o paciente recebeu alta ou não
void alta(FILE *fptr){
    FILE *falta;
    FILE *fatend;
    //Vai criar 2 arquivos de textos de pacientes com alta e sem alta
    falta = fopen("filalta","w");
    fatend = fopen("filatendido","w");
    int strle;
    char string[100];
    int numpac = paccount();
    //Ai vai rodar um for a partir da quantidade de pacientes com 2 ifs checando se tá em alta ou não e escreve lá no arquivo de texto específico
    for(int i=0;i<numpac;i++){
        fgets(string,100,fptr);
        strle=strlen(string)-2;
        if(string[strle]=='0'){
            fprintf(fatend,"%s",string);
        }
        else if(string[strle]=='1'){
            fprintf(falta,"%s",string);
        }
    }
    fclose(fptr);
    fclose(falta);
    fclose(fatend);
}
void fila(FILE *fptr){
    char str[100];
    int numpac = paccount();
    FILE *forg;
    //Forg vai ser usado pra criar um novo arquivo de texto com os pacientes organizados em ordem de estado
    forg = fopen("pacienteorganizado","w");
    //Botei 3 fors pra cada um checar 1 estado;
    for(int i=0;i<numpac;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-9;
        if(str[strle]=='3'){
            printf("\033[31mINTERNACAO IMEDIATA! -->\033[0m %s",str);
            fprintf(forg,"INTERNAÇÃO %s",str);
        }
    }
    fclose(forg);
    fclose(fptr);
    forg = fopen("pacienteorganizado","a");
    fptr = fopen("paciente","r");
    for(int i=0;i<numpac;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-9;
        if(str[strle]=='2'){
            printf("%s",str);
            fprintf(forg,"%s",str);
        }
    }
    fclose(forg);
    fclose(fptr);
    //Vai checando os 3 estados, tudo dando loop denovo e denovo no arquivo de texto de pacientes
    forg = fopen("pacienteorganizado","a");
    fptr = fopen("paciente","r");
    for(int i=0;i<numpac;i++){
        fgets(str,100,fptr);
        int strle = strlen(str)-9;
        if(str[strle]=='1'){
            printf("%s",str);
            fprintf(forg,"%s",str);
        }
    }
    fclose(forg);
    fclose(fptr);
}
//Execução de funções
void main()
{
    //Aqui é só execução das funções usando o tipo FILE POINTER que tá apontando pro arquivo de texto pacientes
    FILE *fptr;
    fptr = fopen("paciente","r");
    fila(fptr);
    fclose(fptr);
    fptr = fopen("paciente","r");
    alta(fptr);
    fclose(fptr);
}
