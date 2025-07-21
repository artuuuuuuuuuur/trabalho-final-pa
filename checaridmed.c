#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int checkid(char med[]){
    int buffer = 0;
    int buffer2 = 0;
    int buffer3 = 0;
    int buffer4;
    int num = 0;
    char strnum[50];
    int numret;
    //Primeiro loop pra passar pela checagem do numero do medico
    for(int i = 0;i<500;i++)
    {
        buffer++;
        if(isdigit(med[i])){
            while(isdigit(med[buffer])){
                buffer++;
            }
            i=500;
        }
    }
    buffer+=5;
    buffer2=buffer;
    //Segundo loop pra checar o id
    for(int i = buffer;i<500;i++)
    {
        if(isdigit(med[i])){
            while(isdigit(med[buffer2])){
                buffer2++;
            }
        }
        buffer2++;
        i=500;
    }
    buffer2++;
    buffer3=buffer2;
    //Terceiro loop pra checar a idade do paciente
    for(int i = buffer2;i<500;i++)
    {
        if(isdigit(med[i])){
            while(isdigit(med[buffer3])){
                buffer3++;
            }
            break;
        }
        buffer3++;
    }
    buffer3++;
    buffer4=buffer3;
    //O QUARTO LOOP PEGA O IDMED DO PACIENTE
    for(int i = buffer3;i<500;i++)
    {
        if(isdigit(med[i])){
            while(isdigit(med[buffer4])){
                strnum[num]=med[buffer4];
                num++;
                buffer4++;
            }
            numret=atoi(strnum);
            return numret;
        }
        buffer4++;
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
