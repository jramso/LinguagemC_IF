#include <stdio.h>
#include <stdlib.h>

typedef struct A{
    char *cpf;
    char *nome;
    char *email;
    int *tel;
}proprietario;

typedef struct B{
    char *placa;
    char *modelo;
    char *marca;
    char *donoCpf;
    int *quilometragem;

}veiculo;

int main(){
    Lista listProp = criaLista();
    Lista listVeic = criaLista();

    return 0;
}