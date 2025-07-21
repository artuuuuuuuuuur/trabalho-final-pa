#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int checkidmed(char med[]){
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
        if(isdigit(med[i])){
            while(isdigit(med[buffer3])){
                strnum[num]=med[buffer3];
                num++;
                buffer3++;
            }
            numret=atoi(strnum);
            return numret;
        }
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
            while(idmed==checkidmed(str)){
                printf("%s",str);
                fgets(str,100,fptr);
            }
            break;
        }
    }
    fclose(fptr);
}
