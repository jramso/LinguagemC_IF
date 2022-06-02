#include <stdio.h>;
#include "tadlista.h";
#include <stdlib.h>


/**********************************
*
***IMPLEMENTAÇÃO DA INTERFACE DO TADLISTA
*
****************************/

Lista criaLista(){
    Lista lista = (tcabec *)malloc(sizeof(tcabec)); //cria a variavel 'lista' e aloca memoria pra uma lista do tamanho de um cabeçalho lista 
    lista->primeiro =NULL;//elementos 'primeiro' e 'ultimo' recebem nulo
    lista->ultimo=NULL;
    lista->tamanho=0;//'tamanho' da 'lista' é 0 sem elementos ate então
    return lista; //retorna a 'lista'

};
Lista appendLista(Lista lst,tdado dado){
        pnoh novoNo = (pnoh)malloc(sizeof(tnode));//crio um novo no do tamanho de um tnode
        novoNo->proximo=NULL;//proximo do "ultimo novo" dado recebe null
        novoNo->dado=dado;//recebe um dado informado
    if (lst->tamanho==0){//se nao tem elementos na lista
        lst->primeiro=novoNo;// 'primeiro' e 'ultimo' recebem o elemento inseridos no 'Append'
        lst->ultimo=novoNo;
        lst->tamanho++;//acrescento 1 ao tamanho
    }else{
        lst->ultimo->proximo = novoNo;
        lst->ultimo=novoNo;
    }
    lst->tamanho++;//acrescenta +1 ao tamanho
    return lst;

};//
Lista insertLista(Lista lst,int pos,tdado dado){
    if  ((lst->tamanho)+1<pos){//se tentar inserir num tamanho maior que a 'lista+1' exibir um erro por estar fora de alcance e retornar nulo;
        printf("var 'i' out of index");
        return NULL;
    }
    else{  //caso nao
        pnoh novoNo;
        novoNo->dado=dado;
        novoNo->proximo=NULL;
        if (lst->tamanho==0){ // Se a lista é vazia 'primeiro' e 'ultimo' sao o 'novoNo', e o proximo de 'novoNo' aponta pra 'NULL'
            lst->primeiro=novoNo;
            lst->ultimo=novoNo;
        }else{//caso nao
            if (pos==(lst->tamanho+1)){//se for o ultimo ja tenho o 'appendLista()' entao chamo o append
                appendLista(lst,dado);
            }
            else{//se for pra inserir em qualquer lugar entre 2 nós
                pnoh auxNo;
                auxNo=lst->primeiro;//crio um no auxiliar
                for (int j=0;j<pos;j++){ //se j for menor do que onde eu quero colocar
                    auxNo=auxNo->proximo;//no auxiliar recebe o proximo no 1
                    if (j==pos-1){
                        novoNo->proximo=auxNo->proximo; // 'novoNo->proximo' recebe o valor de proximo do nó atual encadeando a lista pra frente 
                        auxNo->proximo=novoNo; //(nó atual)'auxNo->proximo' recebe como proximo o 'novoNo' encadeando a parte de tras da lista
                    }
                }//cheguei no no que eu queria
            }
        }
        lst->tamanho+=1; //aumento em um o tamanho
        return lst; 
    }
};//insere um dado na lista

tdado removeLista(Lista lst,int i){
    //Remover um elo e unir anterior com o próximo
    if (i<=lst->tamanho){
        pnoh auxNo=(pnoh)malloc(sizeof(tnode));
        auxNo=lst->primeiro;
        for(int j=0; j<i;j++){
            auxNo=auxNo->proximo;
            if(j==(i-1)){
                
            }
        }

    }else{
        printf("var %d out of index",i);
        return NULL;
    }


};//remove um dado da lista

int lenLista(Lista lst){
    return lst->tamanho;
};//informa o tamanho de elementos da lista

tdado dadoLista(Lista lst,int i){
    if (lst->tamanho<i){
        printf("var 'i' out of index");
        return NULL;
    }else{
        //declarando var
        int aux=0;
        pnoh dadoLst=lst->primeiro;
        while (aux<i)
        {
            dadoLst=dadoLst->proximo;
            aux++;
        }
       return dadoLst->dado;
    }
};//retorna o dado da lista na posiçao i para sexta-feira 27/05
tdado dadoListaProf(Lista lst,int i){
    int contpulos; 
    pnoh no_corrente;
    if ((lst==NULL) || (i<0) || (i>= lst->tamanho)){
        return NULL;
    }
    contpulos=0;
    no_corrente=lst->primeiro;
    while (contpulos!=i)
    {
        /* code */
        contpulos++;
        no_corrente=no_corrente->proximo;
    }
    return no_corrente->dado;
}//dadoLista desenvolvido pelo Professor

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