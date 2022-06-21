#ifndef TAD_FILA_H_
#define TAD_FILA_H_
#include "tadLista.h"
#endif
/*************************
***
*** CABECALHO TADFILA
***
*****************/

typedef Lista Fila;


Fila criaFila();
tdado enfileira(Fila fila,tdado dado);
tdado desenfileira(Fila fila);
tdado cabecaFila(Fila fila);
tdado caudaFila(Fila fila);
int tamFila(Fila fila);
int vaziaFila(Fila fila);
Lista fila2lista(Fila fila);