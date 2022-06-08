#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intersecao(int *vetA,int a,int *vetB,int b,int *vetC,int c){
    vetA=(int*)malloc(a*sizeof(int));//vetor A
    vetB=(int*)malloc(b*sizeof(int));//vetor B
    vetC=(int*)malloc(c*sizeof(int));//vetor Intersecao
    int tami;
    tami=0;

    srand(time(NULL));
    for (int i=0;i<10;i++){
        vetA[i]=rand()%50;//gerando numeros aleatorios entre 0 e 100
    }
    for (int i=0;i<10;i++){
        vetB[i]=rand()%50;
        printf("A: %d",vetA[i]);
        printf("    B: %d\n",vetB[i]);
    }
    printf("\n");
    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(vetA[i]==vetB[j]){
                vetC[tami]=vetA[i];
                tami++;
            }
        }
    }
    for (int i=0;i<tami;i++){
        printf("I: %d\n",vetC[i]);
    }
    free(vetA);
    free(vetB);
    vetA=NULL;
    vetB=NULL;
}



int main(){
    //vetores declarados como ponteiros para que possam ser
    // de um tamanho informado pelo usuario em usos futuros
    int *vet_A;
    int *vet_B;
    int *vet_I;

    intersecao(vet_A,10,vet_B,10,vet_I,10);

    return 0;
}