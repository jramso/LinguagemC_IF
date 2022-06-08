#include <stdio.h>

/*
Programa em C respectivo a Atividade
do livro do Farrer 1.12.13 (consumo de energia elétrica)
|20202BSI0292 | Josué Ramos Souza |
.Abril 2022 README.md
***********************************
** Josué Ramos Souza - Github: @Jramso
** https://github.com/jramso/LinguagemC_IF/tree/main/3_structs
************ 3_structs *********
*******************************/


//struct Consumidor
typedef struct consumidor_Cliente
{
    /* data */
    float precoKWh;
    int numconsum;
    double kwconsum;
    int tipocons;
    double totalconsumo[3];
    double mediaconsumo;
    double maiorconsumo;
    double menorconsumo;
    double consumido; 
}consumidor_Cliente;

struct consumidor_Cliente consumidor;//declaracao global de um consumidor


//struct consumidor_consumidor consumidor; //

void data_output(){
    printf("Maior consumo: %.2lf\n",consumidor.maiorconsumo);
    printf("Menor consumo: %.2lf\n",consumidor.menorconsumo);
    printf("Total consumido Residencial: %.2lf Kw/h\n",consumidor.totalconsumo[0]);
    printf("Total consumido Comercial: %.2lf Kw/h\n",consumidor.totalconsumo[1]);
    printf("Total consumido Industrial: %.2lf KW/h\n",consumidor.totalconsumo[2]);
    printf("Media geral entre os 3 tipos de consumidores: %.2lf KW/h\n",consumidor.mediaconsumo);
}//essa funcao EXIBE para o usuario ao final do programa
// o maior e menor consumo em kwh e o total consumido em KW/h por cada um dos tipos de consumidores

void calc_Consum(int i){
    //processing data
    //valor do consumo mensal
    consumidor.consumido=(consumidor.kwconsum*consumidor.precoKWh); //dados consumidos
    if(i==0){ //se for o primeiro consumidor menor e maior consumo = a consumo
        consumidor.menorconsumo=consumidor.kwconsum; 
        consumidor.maiorconsumo=consumidor.kwconsum;
    };

    //maior consumo KWh
    if(consumidor.kwconsum>consumidor.maiorconsumo){
        consumidor.maiorconsumo=consumidor.kwconsum;
    };

    // menor consumo KWh
    if(consumidor.kwconsum<consumidor.menorconsumo){
        consumidor.menorconsumo=consumidor.kwconsum;
    };

    //total de consumo
    consumidor.totalconsumo[consumidor.tipocons-1]=consumidor.totalconsumo[consumidor.tipocons-1]+consumidor.kwconsum;
    //media de consumo
    consumidor.mediaconsumo=(consumidor.totalconsumo[0]+consumidor.totalconsumo[1]+consumidor.totalconsumo[2])/3;

}

void data_entry(int i){

        //input data
        printf("informe o preço do KW/h: ");
        scanf("%f",&consumidor.precoKWh);
        printf("informe a quantidade de kwh consumidos no mês:");
        scanf("%lf",&consumidor.kwconsum);
        printf("informe o numero do tipo do consumidor:");
        printf("1-Residencial | 2-Comercial | 3-Industrial: \n ->");
        scanf("%d",&consumidor.tipocons);
        //processamento e calculos
        calc_Consum(i);

        //fast-output data
        printf("Consumo: %.2lf KW/h \n",consumidor.kwconsum);
        printf("Seu numero de consumidor e: %d \nTotal a pagar: R$ %.2lf\n",consumidor.numconsum,consumidor.consumido);
        printf("\ninforme o numero do consumidor: ");
        scanf("%d",&consumidor.numconsum);
}




//inicio do programa principal
int main(){
    int i=0; //auxiliar para conferir se e o primeiro dado do programa e ou contar quantidade de consumidor lidos
    printf("informe o numero do consumidor: \n");
    scanf("%d",&consumidor.numconsum);
    //loop com base na flag Numero do consumidor
    while(consumidor.numconsum!=0){
        //input data
        data_entry(i);
        i++;
    }
    //output data
    data_output();
    return 0;
};//fim
