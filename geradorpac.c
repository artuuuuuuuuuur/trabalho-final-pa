#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int paccount ()
{
   char num[500];
   int nume = 0;
   FILE *fptr;
   fptr = fopen("paciente","r");
   while(fgets(num,500,fptr)){
    nume++;
   }
   fclose(fptr);
   return nume;
}
void main ()    
{
   int numpac = paccount();
   int id = 1000+numpac;
   int idade;
   int idmed = 1000+numpac;
   int estado;
   printf("%d",numpac);
   FILE *fptr;
   fptr = fopen("paciente","a");
   for (int i = 1; i <= 10; ++i )
   {
      numpac++;
      idade = rand()%99+1;
      estado = rand()%3+1;
      fprintf(fptr,"PACIENTE%d: ID:%d,NOME:Jose,IDADE:%d,IDMED:%d,ESTADO:%d\n",numpac,id,idade,idmed,estado);
      idmed++;
      id++;
   }
   fclose(fptr);
}
