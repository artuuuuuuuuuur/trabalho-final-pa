#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int checkidmed(char med[]){
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
    //Terceiro loop pra checar o id do médico
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
void main()
{
    FILE *fptr;
    fptr = fopen("paciente","r");
    char str[100];
    printf("Digite o id do medico que voce quer ver os pacientes alocados\n");
    int idmed;
    int idmedpos;
    char idpacs[4];
    char idmeds[5];
    scanf("%d",&idmed);
    itoa(idmed,idmeds,10);
    printf("Esse medico esta alocado aos pacientes:\n");
    while(fgets(str,100,fptr)){
        if(idmed==checkidmed(str)){
            printf("%s",str);
        }
    }
    fclose(fptr);
}
