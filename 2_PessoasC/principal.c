#include <stdio.h>
#include <stdlib.h>
#include "tadlista.c"

/*****************
** Definindo struct tpessoa
************/
typedef struct pessoa
{
   char *nome;
   char *cpf;
   float *altura;
   int *idade;
}*tpessoa;

/**************************************************
** função do tipo Lista (Retorna uma lista)
***************************************************/

Lista listaPessoa(Lista lN,Lista lC,Lista lI,Lista lA){
    Lista lst=criaLista();
    int i=0;
    tpessoa pNCIA;
    while(i < lC->tamanho-1){
        pNCIA=(tpessoa)malloc(sizeof(tdado)*4);
        //aloco memória pra receber os dados
        pNCIA->nome=(char *)malloc(sizeof(tdado));
        pNCIA->cpf=(char *)malloc(sizeof(tdado));
        pNCIA->idade=(int *)malloc(sizeof(tdado));
        pNCIA->altura=(float *)malloc(sizeof(tdado));
        //recebo os dados nas variaveis da pessoa
        pNCIA->nome=dadoListaProf(lN,i);
        pNCIA->cpf=dadoListaProf(lC,i);
        pNCIA->idade=dadoListaProf(lI,i);
        pNCIA->altura=dadoListaProf(lA,i);
        //preenche a lista de tpessoas
        appendLista(lst,pNCIA->nome);
        appendLista(lst,pNCIA->cpf);
        appendLista(lst,pNCIA->idade);
        appendLista(lst,pNCIA->altura);
        i++;
    }
    return lst;
}

/**********************************************
** funçoes do tipo Void (Sem retorno)
***********************************************/
//cria um arquivo e preenche o arquivo com os dados de uma lista
void arqPessoa(Lista lst){
    FILE *pont_arq;
    pont_arq = fopen("bdpessoas.txt","w");
    char *Linha;
    for (int i=0;i<=lst->tamanho;i++){
        Linha=(char *)malloc(sizeof(tdado));
        Linha=dadoListaProf(lst,i);
        if(Linha!=NULL){
            if(i<lst->tamanho-3){ //boa e velha gambiarra por falta de "\n" suficientes dos arquivos
                fprintf(pont_arq,"%s",Linha);
            }else{
                fprintf(pont_arq,"\n%s",Linha);        
            }
        }
    }
    fclose(pont_arq);
}//FIM ARQPESSOA

//Exibe os dados de uma Lista (apenas para auxiliar)
// void printCharLista(Lista l, int indice){
//     char *pnum;
//     pnum=(char *)malloc(sizeof(tdado)); //aloca tdado em um ponteiro pra char para ler qualquer lista
//     pnum=dadoListaProf(l,indice);
//     printf("%s\n",pnum);
// }//FIM printCharLista

//Função que carrega os dados do arquivo para uma lista.
void arqCarregaDados(char arq[],Lista lst){
    int i=0;//auxiliar
    FILE *pontarq; //ponteiro pro arquivo
    pontarq = fopen(arq,"r");
    while(!feof(pontarq)){//enquanto nao for o fim do arquivo
        char *dado=NULL;
        dado=(char *)malloc(sizeof(tdado));//aloca tamanho de TDADO: 'dado'
        fgets(dado,150,pontarq);//escreve ate 150 caracteres ou \n o dado
        if(dado!=NULL){ //se o dado nao for nulo insere na lista
            insertLista(lst,i,dado);
            i++;
        }
    }
    fclose(pontarq);//por algum motivo o tadlista gera uma lista com 1 a mais acho que ele duplica o ultimo ou algo assim.
}//Essa função le as linhas de um arquivo e preenche uma lista com cada linha
//FIM arqCarregaDados


int main(){
    //Criando Listas
    Lista lstNomes=criaLista();
    Lista lstCpf=criaLista();
    Lista lstIdade=criaLista();
    Lista lstAlturas=criaLista();
    
    //Carregando os qrquivos pra listas
    arqCarregaDados("bdnomes.txt",lstNomes);//Carrega os dados do arquivo "bdnomes.txt" para a lista de nomes
    arqCarregaDados("bdcpfs.txt",lstCpf);//Carrega os dados do arquivo "bdcpfs.txt" para a lista de cpfs
    arqCarregaDados("bdidades.txt",lstIdade);//Carrega os dados do arquivo "bdidades.txt" para a lista de idades
    arqCarregaDados("bdalturas.txt",lstAlturas);//Carrega os dados do arquivo "bdalturass.txt" para a lista de alturas

    //criando a lista de Pessoas
    Lista lstPessoas=listaPessoa(lstNomes,lstCpf,lstIdade,lstAlturas);//cria uma lista de tpessoas a partir dos dados das listas anteriores;
    //Criando arquivo a partir da lista de pessoas.
    arqPessoa(lstPessoas);//cria o arquivo "bdpessoas.txt" e preenche com os dados da lista lstPessoas (lista de pessoas)


    return 0 ;//FIM
}