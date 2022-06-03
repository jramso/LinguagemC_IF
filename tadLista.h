/*****************
** Estrutura de dados (prof: Ernani) Ifes Serra 2022
**
** BIBLIOTECA DE CABEÇALHOS PARA UMA LISTA DE QUALQUER TIPO DE DADO 'TAD' em linguagem C
** Josué Ramos Souza - Github: @Jramso
** https://github.com/jramso/LinguagemC_IF
*******************/

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

/*
Interface TAD lista
*/

Lista criaLista();//cria a lista
Lista appendLista(Lista lst,tdado dado);//
Lista insertLista(Lista lst,int i,tdado dado);//insere um dado na lista
tdado removeLista(Lista lst,int i);//remove um dado da lista

int lenLista(Lista lst);//informa o tamanho de elementos da lista

tdado dadoLista(Lista lst,int i);//retorna o dado da lista
int indexLista(Lista lst,tdado dado);
Lista clearLista(Lista lst);
tdado primLista(Lista lst);//primeiro dado da Lista
tdado ultLista(Lista lst);//ultimo dado da Lista