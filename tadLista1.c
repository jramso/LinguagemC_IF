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

    int resposta;
    int *ptr_int;

    for(int i=0;i<20;i++){
        colocaNaLista(lst,i*10);
    }
    ptr_int =(int*)dadoLista(lst,13);
    resposta =indexLista(lst,ptr_int);
    if (resposta!=-1){
        printf("dado %d esta na lista",&ptr_int);
    }else{
        printf("dado nao esta na lista");
    }

    /****** ANOTHER TEST
    char msg[1000];
    int n=55;
    for (int i=0; i<3;i++){
        int valor=(i*10);
        insereNaLista(lst,i,valor);
    }
    insereNaLista(lst,2,n);
    for (int i=0;i<4;i++){
        printElemLista(lst,i,"dado:");
    }
    */

    /******** SEM SUB-ROTINA
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

