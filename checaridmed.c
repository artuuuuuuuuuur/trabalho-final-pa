#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Função de checar ID
int checkid(char pac[]){
    int buffer = 0;
    int buffer2;
    int buffer3;
    int num = 0;
    char strnum[50];
    int numret;
    //Primeiro loop pra passar pela checagem do numero do medico
    for(int i = 0;i<500;i++)
    {
        buffer=i;
        if(isdigit(pac[i])){
            while(isdigit(pac[buffer])){
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
        if(isdigit(pac[i])){
            while(isdigit(pac[buffer2])){
                buffer2++;
            }
        }
        i=500;
    }
    buffer2++;
    //Terceiro loop pra checar o id do médico
    for(int i = buffer2;i<500;i++)
    {
        buffer3=i;
        if(isdigit(pac[i])){
            while(isdigit(pac[buffer3])){
                strnum[num]=pac[buffer3];
                num++;
                buffer3++;
            }
            numret=atoi(strnum);
            return numret;
        }
    }
}
void main(){
    FILE *fptr;
    int num;
    fptr = fopen("paciente","r");
    char nome[500];
    while(fgets(nome,500,fptr)){
        num=checkid(nome);
        printf("%d\n",num);
    }
    fclose(fptr);  
}
