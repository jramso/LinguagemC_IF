#include <stdio.h>
#include <stdlib.h>
#include "tadLista.c"



void colocaNaLista(Lista l,int a){
    int *pnum=NULL;
    pnum=(int *)malloc(sizeof(int));
    *pnum=a;
    appendLista(l,pnum);
    return l;
}
void insereNaLista(Lista l,int i,int a){
    int *pnum=NULL;
    pnum=(int *)malloc(sizeof(int));
    *pnum=a;
    insertLista(l,i,pnum);
    return l;
}
void printElemLista(Lista l, int indice,char msg[]){
    int *pnum;
    pnum = dadoLista(l,indice);
    printf("%s %d\n",msg,*pnum);
}

int main(){
    Lista lst=criaLista();
    char msg[1000];
    for (int i=0; i<3;i++){
        int valor=(i*10);
        insereNaLista(lst,i,valor);
    }
    for (int i=0;i<3;i++){
        printElemLista(lst,i,"dado:");
    }
    /* SEM SUB-ROTINA
    int *pnum=NULL;
    //dado1
    pnum=(int *)malloc(sizeof(int));
    *pnum=10;
    appendLista(lst,pnum);
    //dado2
    pnum=(int *)malloc(sizeof(int));
    *pnum=20;
    appendLista(lst,pnum);
    //dado3
    pnum=(int *)malloc(sizeof(int));
    *pnum=30;
    appendLista(lst,pnum);

    //RECUPERANDO ELEMENTOS DA LISTA

    pnum=dadoLista(lst,0);
    printf("PRIMEIRO ELEMENTO DA LISTA: %d\n",*pnum);
    
    pnum=dadoLista(lst,1);
    printf("SEGUNDO ELEMENTO DA LISTA: %d\n",*pnum);

    pnum=dadoLista(lst,2);
    printf("TERCEIRO ELEMENTO DA LISTA: %d\n",*pnum);
    */

   return 0;
}

