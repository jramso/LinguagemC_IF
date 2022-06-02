Lista tadLista.c 31/5

# LinguagemC_IF
IFES atividades de Ernani

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
    }else{
        lst->ultimo->proximo = novoNo;
        lst->ultimo=novoNo;
    }
    lst->tamanho++;//acrescento 1 ao tamanho
    return lst;

};//
Lista insertLista(Lista lst,int i,tdado dado){
    if ((lst->tamanho)+1<i){//se tentar inserir num tamanho maior que a 'lista+1' exibir um erro por estar fora de alcance e retornar nulo;
        printf("var 'i' out of index");
        return NULL;
    }else{  //caso nao
        pnoh novoNo =(pnoh)malloc(sizeof(tnode));
        novoNo->dado=dado;
        if (lst->tamanho==0){ // Se a lista é vazia 'primeiro' e 'ultimo' sao o 'novoNo', e o proximo de 'novoNo' aponta pra 'NULL'
            novoNo->proximo=NULL;
            lst->primeiro=novoNo;
            lst->ultimo=novoNo;
        }else{//caso nao
            pnoh auxNo=lst->primeiro;//crio um no auxiliar
            for (int j=0;j<i;j++){ //se j for menor do que onde eu quero colocar
                auxNo=auxNo->proximo;//no auxiliar recebe o proximo no
            }//cheguei no no que eu queria
            novoNo->proximo=auxNo->proximo; // 'novoNo->proximo' recebe o valor de proximo do nó atual encadeando a lista pra frente 
            auxNo->proximo=novoNo; //(nó atual)'auxNo->proximo' recebe como proximo o 'novoNo' encadeando a parte de tras da lista
        }
        lst->tamanho+=1; //aumento em um o tamanho independente do que aconteça
        return lst;
        
    }
    

};//insere um dado na lista

tdado removeLista(Lista lst,int i){

};//remove um dado da lista

int lenLista(Lista lst){
    return lst->tamanho;
};//informa o tamanho de elementos da lista

tdado dadoLista(Lista lst,int i){
    if ((lst->tamanho<i) || (lst->tamanho>i)){
        printf("var 'i' out of index");
        return NULL;
    }
    //declarando var
    int aux=0;
    pnoh dadoLst=NULL;
    pnoh dadoLst=lst->primeiro;
    while (aux<i){
        dadoLst=dadoLst->proximo;
        aux++;
    }
    return dadoLst->dado;
    
};//retorna o dado da lista na posiçao i para sexta-feira 27/05

tdado dadoListaProf(Lista lst,int i){
    int contpulos;
    pnoh no_corrente;
    if ((lst==NULL) || (i<0) || (i>= lst->tamanho)){
        return NULL;
    }
}
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
