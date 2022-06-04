#include <stdio.h>

void ordena(int *a, int *b,int *c){//6 combinacoes possiveis
    if (*a<=*b && *a<=*c){
        if (*b<=*c){
            printf("Valores ordenados:\n %d,  %d,  %d",*a,*b,*c);
        }else{
            printf("Valores ordenados:\n %d,  %d,  %d",*a,*c,*b);
        }
    }else if(*b<=*a && *b<=*c){
        if(a<=c){
            printf("Valores ordenados:\n %d,  %d,  %d",*b,*a,*c);
        }else{
        printf("Valores ordenados:\n %d,  %d,  %d",*b,*c,*a);
        }

    }else if(*c<=*b && *c<=*a){
        if(*a<=*b){
            printf("Valores ordenados:\n %d,  %d,  %d",*c,*a,*b);
        }else{
            printf("Valores ordenados:\n %d,  %d,  %d",*c,*b,*a);
        }

    }

}

int main(){
    int x;
    int y;
    int z;
    printf("informe o primeiro numero:\n");
    scanf("%d",&x);
    printf("informe o segundo numero:\n");
    scanf("%d",&y);
    printf("informe o terceiro numero:\n");
    scanf("%d",&z);
    ordena(&x,&y,&z);
    return 0;
}