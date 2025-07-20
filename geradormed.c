#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int medcount ()
{
   char num[500];
   int nume = 0;
   FILE *fptr;
   fptr = fopen("medico","r");
   while(fgets(num,500,fptr)){
    nume++;
   }
   fclose(fptr);
   return nume;
}
void main ()    
{
   int  nummed = medcount();
   int id = 1000+nummed;
   int idade;
   printf("%d",nummed);
   FILE *fptr;
   fptr = fopen("medico","a");
   for (int i = 1; i <= 10; ++i )
   {
      nummed++;
      idade = rand()%99+1;
      fprintf(fptr,"MEDICO%d: ID:%d,NOME:Jose,IDADE:%d\n",nummed,id,idade);
      id++;
   }
   fclose(fptr);
}
