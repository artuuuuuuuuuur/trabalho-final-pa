#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Função de checar ID
int checkid(char med[]){
    int buffer = 0;
    int buffer2;
    int num = 0;
    char strnum[50];
    int numret;
    //Primeiro loop pra passar pela checagem do numero do medico
    for(int i = 0;i<500;i++)
    {
        buffer=i;
        if(isdigit(med[i])){
            while(isdigit(med[buffer])){
                buffer++;
            }
            i=500;
        }
    }
    buffer++;
    //Segundo loop pra checar o id
    for(int i = buffer;i<500;i++)
    {
        buffer2=i;
        if(isdigit(med[i])){
            while(isdigit(med[buffer2])){
                strnum[num]=med[buffer2];
                num++;
                buffer2++;
            }
            numret=atoi(strnum);
            return numret;
        }
    }
}
void main(){
    FILE *fptr;
    int num;
    fptr = fopen("medico","r");
    char nome[500];
    while(fgets(nome,500,fptr)){
        num=checkid(nome);
        printf("%d\n",num);
    }
    fclose(fptr);  
}
