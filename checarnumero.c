#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
int checknum(char med[]){
    int buf = 0;
    int num = 0;
    char strnum[50];
    int numret;
    for(int i = 0;i<500;i++)
    {
        buf=i;
        if(isdigit(med[i])){
            while(isdigit(med[i])){
                strnum[num]=med[buf];
                num++;
                buf++;
            }
            numret=atoi(strnum);
            return(numret);
        };
    }
}
void main(){
    FILE *fptr;
    FILE *fbuffer;
    int num;
    fbuffer = fopen("C:\\Users\\Public\\Documents\\Trabalho\\Medicos\\medico","r");
    fptr = fopen("C:\\Users\\Public\\Documents\\Trabalho\\Medicos\\medico","r");
    char nome[500];
    char buffer[500];
    char medcu[500]="MEDICO10: ID:1009,NOME:Jose,IDADE:76,IDMED:1009,ESTADO:1";
    fgets(nome,500,fbuffer);
    fgets(buffer,500,fptr);
    fclose(fbuffer);
    fclose(fptr);  
    num=checknum(medcu);
    printf("%d\n",num);
    printf("%s",buffer);
    printf("%s",nome);
}