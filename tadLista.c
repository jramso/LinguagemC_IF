#include <stdio.h>
#include "tadlista.h"
#include <stdlib.h>


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
        pnoh limpaNo=(pnoh)malloc(sizeof(tnode));
        auxNo=lst->primeiro;//dado 0
        if(i==0 && i==lst->tamanho){//se so tiver 1 dado
            free(auxNo);
            lst->primeiro=NULL;
            lst->ultimo=NULL;
            lst->tamanho=0;
            auxNo=NULL;
        }else{
            for(int j=0; j<i;j++){ //casos lista>0
                auxNo=auxNo->proximo;// dado 1
                limpaNo=lst->primeiro->proximo;//dado num 1 (0,->1,2)
                if(i==1){//caso especifico do dado 1
                    lst->primeiro->proximo=auxNo->proximo;
                    break;
                }
                if(j==(i-1)){
                    if(i==lst->tamanho){ //remover o ultimo dado
                        limpaNo=auxNo->proximo; //dado a ser limpo
                        auxNo->proximo=NULL;    //penultimo dado vira ultimo
                        lst->ultimo=auxNo;      //posição ultimo atualizada
                        break;
                    }else{//qualquer outro dado
                        limpaNo=auxNo->proximo;//dado a ser excluido 9->10
                        auxNo->proximo=auxNo->proximo->proximo;// 9->10=9->11 (desencadeia o no)
                    }
                }
            }
        }
        free(limpaNo);
        free(auxNo);
        limpaNo=NULL;
        auxNo=NULL;
        return lst;
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
    for(int i=0;i<=lst->tamanho;i++){
        removeLista(lst,i);
    }
};//limpa todos os dados da Lista
tdado primLista(Lista lst){
    return lst->primeiro->dado;
};// retorna primeiro dado da Lista
tdado ultLista(Lista lst){
    return lst->ultimo->dado;
};//ultimo dado da Lista