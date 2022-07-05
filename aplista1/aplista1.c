/***********************************
** Josué Ramos Souza - Github: @Jramso
** https://github.com/jramso/LinguagemC_IF
*******************************/
#include <stdio.h>
#include <stdlib.h>
#include "tadlista.c"
#include <string.h>

/*****************
** Definindo struct tpessoa
************/
typedef struct pessoa
{
   char nome[250];
   char cpf[15];
   float altura;
   int idade;
}tpessoa;

/**************************************************
** função do tipo Lista (Retorna uma lista)
***************************************************/

Lista listaPessoa(Lista lN,Lista lC,Lista lI,Lista lA){
    Lista lst=criaLista();
    int i=0;
    tpessoa *pNCIA;
    char aux[6];
    while(i < lC->tamanho-1){
        pNCIA=(tpessoa*)malloc(sizeof(tpessoa));
        //recebo os dados nas variaveis da pessoa
        strcpy(pNCIA->nome,(char*)dadoLista(lN,i));
        strcpy(pNCIA->cpf,(char*)dadoLista(lC,i));
        strcpy(aux,(char*)dadoLista(lI,i));
        pNCIA->idade=(int)atoi(aux);
        strcpy(aux,(char*)dadoLista(lA,i));
        pNCIA->altura=(strtof(aux,NULL));
        //preenche a lista de tpessoas
        appendLista(lst,pNCIA);
        i++;
    }
    return lst;
}

/**********************************************
** funçoes do tipo Void (Sem retorno)
***********************************************/
//cria um arquivo e preenche o arquivo com os dados de uma lista
Lista arqPessoa(Lista lst,char arqnome[]){
    FILE *pont_arq;
    pont_arq = fopen(arqnome,"w");
    tpessoa *pessoaX;
    for (int i=0;i<=lst->tamanho;i++){
        pessoaX=(tpessoa*)malloc(sizeof(tpessoa));
        pessoaX=dadoListaProf(lst,i);
        if(pessoaX!=NULL){
            if(i<lst->tamanho-1){ //boa e velha gambiarra por falta de "\n" suficientes dos arquivos
                fprintf(pont_arq,"%s,%s,%.2f,%d\n",pessoaX->nome,pessoaX->cpf,pessoaX->altura,pessoaX->idade);
            }else{
                fprintf(pont_arq,"%s,%s,%.2f,%d",pessoaX->nome,pessoaX->cpf,pessoaX->altura,pessoaX->idade);      
            }
        }
    }
    fclose(pont_arq);
    return lst;
}//FIM ARQPESSOA


//Função que carrega os dados do arquivo para uma lista.
void arqCarregaDados(char arq[],Lista lst,int flag){
    int i=0;//auxiliar
    FILE *pontarq; //ponteiro pro arquivo
    pontarq = fopen(arq,"r");
    while(!feof(pontarq)){//enquanto nao for o fim do arquivo
        char *dado=NULL;
        dado=(char *)malloc(sizeof(tdado));//aloca tamanho de TDADO: 'dado'
        fgets(dado,150,pontarq);//escreve ate 150 caracteres ou \n o dado
        if(dado!=NULL){ //se o dado nao for nulo insere na lista
            dado[strcspn(dado, "\n")] = 0; //Remove o \n da string dado
            if (flag==1){
                insertLista(lst,i,dado);
            }else if(flag==2){
                insertLista(lst,i,(int*)dado);
            }else if(flag==3){
                insertLista(lst,i,(float*)dado);
            }
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
    //flag = 1 (char), flag = 2(int), flag=3(float)
    arqCarregaDados("bdnomes.txt",lstNomes,1);//Carrega os dados do arquivo "bdnomes.txt" para a lista de nomes
    arqCarregaDados("bdcpfs.txt",lstCpf,1);//Carrega os dados do arquivo "bdcpfs.txt" para a lista de cpfs
    arqCarregaDados("bdidades.txt",lstIdade,2);//Carrega os dados do arquivo "bdidades.txt" para a lista de idades
    arqCarregaDados("bdalturas.txt",lstAlturas,3);//Carrega os dados do arquivo "bdalturass.txt" para a lista de alturas

    //criando a lista de Pessoas
    Lista lstPessoas=listaPessoa(lstNomes,lstCpf,lstIdade,lstAlturas);//cria uma lista de tpessoas a partir dos dados das listas anteriores;
    //Criando arquivo a partir da lista de pessoas.
    arqPessoa(lstPessoas,"bdpessoas.txt");//cria o arquivo "bdpessoas.txt" e preenche com os dados da lista lstPessoas (lista de pessoas)
    return 0 ;//FIM
}