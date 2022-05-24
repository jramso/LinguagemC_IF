#include <stdio.h>;
#include "tadlista.h";
#include <stdlib.h>


/**********************************
*
***IMPLEMENTAÇÃO DA INTERFACE DO TADLISTA
*
****************************/

Lista criaLista(){
    Lista lista = (tcabec *)malloc(sizeof(tcabec));
    lista->primeiro =NULL;
    lista->ultimo=NULL;
    lista->tamanho=0;
    return lista;

};
Lista appendLista(Lista lst,tdado dado){
        pnoh novoNo = (pnoh)malloc(sizeof(tnode));//crio um novo no do tamanho de um tnode
        novoNo->proximo=NULL;//proximo do "ultimo novo" dado recebe null
        novoNo->dado=dado;//recebe um dado informado
    if (lst->tamanho==0){
        lst->primeiro=novoNo;
        lst->ultimo=novoNo;
        lst->tamanho++;//acrescento 1 ao tamanho
    }else{
        lst->ultimo->proximo = novoNo;
        lst->ultimo=novoNo;
    }

};//
Lista insertLista(Lista lst,int i,tdado dado){

};//insere um dado na lista
tdado removeLista(Lista lst,int i){

};//remove um dado da lista

int lenLista(Lista lst){
    return lst->tamanho;
};//informa o tamanho de elementos da lista

tdado dadoLista(Lista lst,int i){
    for (int j=0;j<=lenLista(lst);j++){
        
    }

};//retorna o dado da lista na posiçao i para sexta-feira 27/05
int indexLista(Lista lst,tdado dado){

};
Lista clearLista(Lista lst){

};
tdado primLista(Lista lst){
    return lst->primeiro->dado;
};// retorna primeiro dado da Lista
tdado ultLista(Lista lst){
    return lst->ultimo->dado;
};//ultimo dado da Lista