#include <stdio.h>
#include <string.h>
#include "tadLista2.h"



/***********
*   Ler os arquivos e colocar numa lista
*   NOMES.TXT   - STRING
*   CPS.TXT     -   INT
*   IDADES.TXT     -    INT
*   ALTURAS.TXT     -   FLOAT
********/

typedef struct pessoacad
{
    /* data */
    char *nome; //malloc
    char   *cpf; //malloc
    int idade;
    float  altura;
}*tpessoa;


void cadastraPessoa(char *nome,char *cpf,int idade,float altura){
    tpessoa pessoa=(tpessoa *)malloc(sizeof(tpessoa));
    pessoa->nome=nome;
    pessoa->cpf=cpf;
    pessoa->idade=idade;
    pessoa->altura=altura;

    return pessoa;
}

void leArq(char nomearq[100], Lista lst){
    tdado dado;
    FILE *pontarq;
    pontarq =fopen(nomearq,"r");
    while(fgetc(pontarq)!=EOF){
        fscanf(pontarq,"%s",dado);
        appendLista(lst,dado);
    }
    return lst;
}

void printElemLista(Lista l, int indice,char msg[]){
    char *pdata;
    pdata = dadoLista(l,indice);
    printf("%s %s\n",msg,*pdata);
}