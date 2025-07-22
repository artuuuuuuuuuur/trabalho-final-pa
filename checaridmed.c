#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int checkidmed(char med[]){
    int buffer = 0;
    int count = 0;
    int num = 0;
    char strnum[50];
    int numret;
    //Primeiro loop pra passar pela checagem do numero do medico
    for(int i = 0;i<100;i++)
    {
        buffer++;
        if(isdigit(med[i])){
            //Quando count chegar no número desejado é porque significa que ele chegou no int que ele quer puxar
            if(count==3){
                while(isdigit(med[i])){
                    strnum[num]=med[i];
                    num++;
                    i++;
                }
                numret=atoi(strnum);
                return numret;
            }
            //Aqui é só aumento de buffer pra usar no array
            while(isdigit(med[buffer])){
                buffer++;
            }
            i=buffer;
            //A condição count serve como parâmetro pra checar a passagem pelos inteiros na string do paciente, em ordem de número, id, idade e idmed
            count++;
        }
    }
}
void main(){
    FILE *fptr;
    int num;
    fptr = fopen("paciente","r");
    char nome[100];
    while(fgets(nome,100,fptr)){
        num=checkidmed(nome);
    printf("%d\n",num);
    }
    fclose(fptr);  
}
