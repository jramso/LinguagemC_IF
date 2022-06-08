#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menor(int a, int b){
    if(a<=b){
        return a;
    }else{
        return b;
    }
}
int maior(int a, int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}

void intersecao(int *vetA,int a,int *vetB,int b,int *vetC,int c){
    //aloca memoria
    vetA=(int*)malloc(a*sizeof(int));//vetor A
    vetB=(int*)malloc(b*sizeof(int));//vetor B
    vetC=(int*)malloc(c*sizeof(int));//vetor Intersecao

    int tami;
    tami=0;
    //preenche vetA random seed
    srand(time(NULL));
    for (int i=0;i<a;i++){
        vetA[i]=rand()%50;//gerando numeros aleatorios entre 0 e 100
    }
    //preenche vetB random seed e exibe vetA e vetB
    for (int i=0;i<maior(a,b);i++){
        if(i<a){
            printf("A: %d ",vetA[i]);
        }else{printf("      ");}
        if(i<b){
            vetB[i]=rand()%50;
            printf("    B: %d\n",vetB[i]);
        }
    }

    printf("\n");
    //preenche vetC se o elemento existir em vetA e vetB
    for (int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(vetA[i]==vetB[j]){
                vetC[tami]=vetA[i];
                tami++;
            }
        }
    }
    //elimina duplicados
    for (int i=0;i<c;i++){
        for(int j=i+1;j<tami;){//incrementa j ao final
            //se existir o mesmo valor
            if(vetC[i]==vetC[i+1]){
                for(int l=j;l<tami;l++){
                    vetC[l]=vetC[l+1];//"tranforma" o duplicado em 1
                    tami--;//e diminui em 1 o tamanho
                }
            }else{
                j++;
            }
        }
    }
    //exibe vetorC
    if(tami!=0){
        for (int i=0;i<tami;i++){
            printf("I: %d\n",vetC[i]);
        }
    }else{
        printf("\nNao existem valores iguais entre os vetores");
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
    int tamA;
    int tamB;
    int tamI;

    printf("informe um tamanho para o vetor A:");
    scanf("%d",&tamA);
    printf("informe um tamanho para o vetor B:");
    scanf("%d",&tamB);
    tamI=menor(tamA,tamB);//nao tem como ter uma interseção maior que um dos vetores
    
    intersecao(vet_A,tamA,vet_B,tamB,vet_I,tamI);
    //FALTA TERMINAR
    return 0;
}