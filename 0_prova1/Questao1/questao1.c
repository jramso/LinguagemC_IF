#include <stdio.h>
#include <string.h>

//inicio STRUCT
typedef struct veiculos{
    /* data */
    char placa[10], modelo[20],marca[20];
    int quilometragem;
}tveiculo;//struct para dados de um veiculo
//FIM STRUCT

//Inicio funcao FILTRO
void filtro(tveiculo *Vauto, char arq[], int tam,char marca[20]){
    //data
    FILE *pont_arq_saida;
    pont_arq_saida=fopen(arq,"wt");
    int result;
    if(pont_arq_saida==NULL){ //se arquivo nao existir
        printf("Erro na abertura do arquivo %s",arq);
    }
    else{ //se existir o arquivo
        for (int i=0; i<tam+1;i++){
            result=strcmp(Vauto[i].marca,marca);
            if(result==0){
            fprintf(pont_arq_saida,"%s ",Vauto[i].placa);
            fprintf(pont_arq_saida,"%s ",Vauto[i].modelo);
            fprintf(pont_arq_saida,"%s ",Vauto[i].marca);
            fprintf(pont_arq_saida,"%d \n",Vauto[i].quilometragem);
            }
        }
    }
    fclose(pont_arq_saida);
    return;

}
//FIM funcao FILTRO

//INICIO FUNCAO PRINCIPAL
int main(){
    FILE *pont_arq;
    tveiculo vAuto[150];

    pont_arq = fopen("bdveiculos.txt","r");
    int i=0;
    while(fgetc(pont_arq)!=EOF){
        fscanf(pont_arq,"%s",vAuto[i].placa);
        fscanf(pont_arq,"%s",vAuto[i].modelo);
        fscanf(pont_arq,"%s",vAuto[i].marca);
        fscanf(pont_arq,"%d",&vAuto[i].quilometragem);
        i=i+1;
    }

    fclose(pont_arq);
    filtro(vAuto,"fiatSaida.txt",i,"FIAT");
    filtro(vAuto,"toyotaSaida.txt",i,"TOYOTA");
    filtro(vAuto,"fordSaida.txt",i,"FORD");
    filtro(vAuto,"renaultSaida.txt",i,"RENAULT");
    return (0);
}
//FIM FUNCAO PRINCIPAL