#include <stdio.h>
#include <stdlib.h>
#include "tadLista.h"
#include "tadLista2.h"
#include "arquivos.c"

int main(){
    Lista lstNomes;
    Lista lstCpf;
    Lista lstIdade;
    Lista lstAlturas;
    Lista lstPessoas;
     /*
     CRIAR FUNÇÃO QUE CARREGA DADOS PARA LISTAS 
     */
    leArq("bdnomes.txt",lstNomes);
    for (int i=0;i<10;i++){
        printElemLista(lstNomes,i,"dado:");
    }
    // lstCpf = carregaDados();
    // lstIdade = carregaDados();
    // lstAlturas = carregaDados();

    //lstPessoas = criaListPessoa(lstNomes,lstCpf,lstIdade,lstAlturas);

    //sLstPessoas(lstPessoas,"bdpessoas.txt");
    return 0;
}