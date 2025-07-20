#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int checknum(char med[]){
    int buffer = 0;
    int num = 0;
    char strnum[50];
    int numret;
    for(int i = 0;i<500;i++)
    {
        buffer=i;
        if(isdigit(med[i])){
            while(isdigit(med[i])){
                strnum[num]=med[buffer];
                num++;
                buffer++;
            }
            numret=atoi(strnum);
            return(numret);
        };
    }
}
void main(){
    FILE *fptr;
    int num;
    fptr = fopen("medico","r");
    char nome[500];
    fgets(nome,500,fptr);
    fclose(fptr);  
    num=checknum(nome);
    printf("%d\n",num);
}
