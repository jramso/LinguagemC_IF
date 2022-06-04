#include <stdio.h>
#include <stdlib.h>
#include "tadlista.c"


typedef struct pessoa
{
   char nome;
   char cpf;
   float altura;
   int idade;
}*tpessoa;

void arqPessoa(Lista lst,tpessoa p1){
    FILE *pont_arq;
    pont_arq = fopen("bdveiculos.txt","wa");
    for(int i=0;i<=lst->tamanho;i++){
        fprintf(pont_arq,"%s,%f,%s,%d\n",p1->nome,p1->altura,p1->cpf,p1->idade);
    }
    //CONTINUE ISSO AKI QUE NAO TA PRONTO
    //
    //
    //
    //
    
    fclose(pont_arq);
}

void printCharLista(Lista l, int indice){
    char *pnum;
    pnum=(char *)malloc(sizeof(tdado));
    pnum=dadoLista(l,indice);
    printf("%s",pnum);
}

void arqCarregaDados(char arq[],Lista lst){
    char dado[100];
    int i=0;
    FILE *pontarq;
    pontarq = fopen(arq,"r");
    while(!feof(pontarq)){
        fgets(dado,150,pontarq);
        appendLista(lst,dado);
        if(dado){
            printCharLista(lst,i);
            i++;
        }
    }
    printf("\n");
    fclose(pontarq);
}//Essa função le as linhas de um arquivo e preenche uma lista com cada linha
// depois exibe na tela os dados lidos e colocados na lista



int main(){
    Lista lstNomes=criaLista();
    Lista lstCpf=criaLista();
    Lista lstIdade=criaLista();
    Lista lstAlturas=criaLista();
    Lista lstPessoas=criaLista();

    arqCarregaDados("bdnomes.txt",lstNomes);
    arqCarregaDados("bdcpfs.txt",lstCpf);
    arqCarregaDados("bdidades.txt",lstIdade);
    arqCarregaDados("bdalturas.txt",lstAlturas);


    //arqCarregaDados("bdPessoas.txt",lstPessoas);

    // char dado[100],dado2[100];
    // int i=0;
    // FILE *pontarq;
    // pontarq = fopen("bdnomes.txt","r");
    // while(!feof(pontarq)){
    //     fgets(dado,150,pontarq);
    //     appendLista(lstNomes,dado);
    //     if(dado){
    //         printCharLista(lstNomes,i);
    //         i++;
    //     }
    // }
    // fclose(pontarq);


    // for (int i=0;i<4;i++){
    //     printElemLista(lstIdade,i,"dado:");
    // }
    // for (int i=0;i<10;i++){
    //    printElemLista(lstNomes,i,"dado:");
    // }
    //lstCpf = carregaDados();
    // lstIdade = carregaDados();
    // lstAlturas = carregaDados();

    //lstPessoas = criaListPessoa(lstNomes,lstCpf,lstIdade,lstAlturas);

    //sLstPessoas(lstPessoas,"bdpessoas.txt");
    return 0 ;
}