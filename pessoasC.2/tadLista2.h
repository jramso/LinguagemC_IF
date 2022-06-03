#include <stdio.h>
#include <stdlib.h>

/*
Estrutura da Lista
*/
typedef void *tdado;

typedef struct tnoh{
    tdado dado; // ponteiro para void *tdado
    struct tnoh *proximo;
}tnode;

typedef tnode* pnoh; //nós da lista com o dado e endereço do proximo dado

typedef struct{
    pnoh primeiro;
    pnoh ultimo;
    int tamanho;
}tcabec;//struc de cabecalho da lista

typedef tcabec* Lista; //lista um ponteiro do tipo tcabec*

/**********************************
*
***IMPLEMENTAÇÃO DA INTERFACE DO TADLISTA
*
*
****************************/

Lista criaLista(){
    Lista lista = (tcabec *)malloc(sizeof(tcabec)); //cria a variavel 'lista' e aloca memoria pra uma lista do tamanho de um cabeçalho lista 
    lista->primeiro =NULL;//elementos 'primeiro' e 'ultimo' recebem nulo
    lista->ultimo=NULL;
    lista->tamanho=0;//'tamanho' da 'lista' é 0 sem elementos ate então
    return lista; //retorna a 'lista'

};//Função que cria uma lista

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

};//função que insere um dado no Final da Lista
Lista insertLista(Lista lst,int pos,tdado dadonovo){
    if  ((lst->tamanho)+1<pos){//se tentar inserir num tamanho maior que a 'lista+1' exibir um erro por estar fora de alcance e retornar nulo;
        printf("var 'pos' out of index");
        return NULL;
    }
    else{  //caso nao
        
        pnoh novoNo=(pnoh)malloc(sizeof(tnode));
        (novoNo->dado)=dadonovo;
        novoNo->proximo=NULL;

        if ((lst->tamanho==0) || (pos==(lst->tamanho+1))){ // Se a lista é vazia 'primeiro' e 'ultimo' sao o 'novoNo', e o proximo de 'novoNo' aponta pra 'NULL'
            appendLista(lst,dadonovo);}
        else{//caso nao seja primeiro ou ultimo elemento da lista
                pnoh auxNo=(pnoh)malloc(sizeof(tnode));
                int contpulos=0;
                auxNo=lst->primeiro;//crio um no auxiliar e coloco o primeiro elemento nele
                while (contpulos<pos-1){
                        auxNo=auxNo->proximo;
                        contpulos++;
                }
                novoNo->proximo=auxNo->proximo; // 'novoNo->proximo' recebe o valor de proximo do nó atual encadeando a lista pra frente 
                auxNo->proximo=novoNo; //cheguei no no que eu queria
            }
        }
        lst->tamanho+=1; //aumento em um o tamanho
        return lst; 
};//função que insere um dado na lista

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


};//função que remove um dado da lista

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
}//função 'dadoLista' desenvolvido pelo Professor

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