#include "tadfila.h"

Fila criaFila(){
    return criaLista;
}

tdado enfileira(Fila fila,tdado dado){
    return appendLista(fila,dado);
}
tdado desenfileira(Fila fila){
    return removeLista(fila,0);
}
tdado cabecaFila(Fila fila){
    return primLista(fila);
}
tdado caudaFila(Fila fila){
    return ultLista(fila);
}
int tamFila(Fila fila){
    return lenLista(fila);
}
int vaziaFila(Fila fila){
    return lenLista(fila)==0;
}
Lista fila2lista(Fila fila){
    Lista lst=criaLista();
    tdado aux;
    while(!vaziaFila(fila)){
        aux=desenfileira(fila);
        appendLista(lst,aux);
    }
    return lst;

}