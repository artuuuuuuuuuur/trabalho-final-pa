#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
//Função que checa o número do médico
int checknum(char med[]){
    int buf = 0;
    int num = 0;
    char strnum[50];
    int numret;
    //A mágica é feita aqui
    for(int i = 0;i<500;i++)
    {
        buf=i;
        //Função isdigit() checa se é inteiro;
        if(isdigit(med[i])){
            //Vai checar se é inteiro até não ser;
            while(isdigit(med[i])){
                //Vai aplicar todos os inteiros á um array de char;
                strnum[num]=med[buf];
                num++;
                buf++;
            }
            //A função atoi vai converter a string em um inteiro, só que ela só funciona em Windows então precisa adicionar o código dela na função em OS diferente.
            numret=atoi(strnum);
            //Retorna a string convertida em inteiro
            return(numret);
        };
    }
}
void main(){
    FILE *fptr;
    //Abertura do arquivo,trocar apenas para "medico"
    fptr = fopen("C:\\Users\\Public\\Documents\\Trabalho\\Medicos\\medico","r");
    char nome[500];
    fgets(nome,500,fptr);
    //Só pode aplicar a função após o fgets ser feito,pois ela é dependente de uma string
    int num=checknum(medcu);
    fclose(fptr);  
    printf("%s",nome);
}
