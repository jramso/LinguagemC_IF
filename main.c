#include <stdio.h>
#include <stdlib.h>
#include "tadLista.h"

int main(){
    Lista lstNomes;
    Lista lstCpf;
    Lista lstIdade;
    Lista lstAlturas;
    Lista lstPessoas;
     /*
     CRIAR FUNÇÃO QUE CARREGA DADOS PARA LISTAS 
     */
    lstNomes = carregaDados();
    lstCpf = carregaDados();
    lstIdade = carregaDados();
    lstAlturas = carregaDados();

    lstPessoas = criaListPessoa(lstNomes,lstCpf,lstIdade,lstAlturas);

    sLstPessoas(lstPessoas,"bdpessoas.txt");
    return 0;
}