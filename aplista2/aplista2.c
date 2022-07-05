
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadLista.c"


typedef struct A
{
    /* data */
    char cpf[13];
    char nome[150];
    char email[150];
    int tel;
}proprietario; //Letra A

typedef struct B
{
    /* data */
    char placa[8];
    char modelo[50];
    char marca[50];
    int quilometragem;
    char cpf[13];
}veiculo; //Letra A

typedef struct 
{
    /* data */
    char cpf[13];
    char nome[150];
    char email[150];
    char placa[8];
    char modelo[50];
    char marca[50];
}tdono;// Letra D


Lista lPessoa(char arqnome[]){ //letra C
    Lista lst=criaLista();
    FILE *pontArq;
    proprietario *dono;
    pontArq = fopen(arqnome,"r");
    while (!feof(pontArq))
    {
        /* code */
        char aux[250];
        char *ps;
        dono=(proprietario *)malloc(sizeof(proprietario));
        fgets(aux,250,pontArq);
        ps=strtok(aux,", ");
        if(ps){
            strcpy(dono->cpf,ps);
            ps=strtok(NULL,",");
            strcpy(dono->nome,ps);
            ps=strtok(NULL,",");
            strcpy(dono->email,ps);
            ps=strtok(NULL,",");
            dono->tel=atoi(ps);
        }
        //printf("%s,%s,%s,%d\n",dono->cpf,dono->nome,dono->email,dono->tel);
        appendLista(lst,dono);
    }
    fclose(pontArq);
    return lst;
}

Lista lVeiculo(char arqnome[]){
    Lista lst=criaLista();
    FILE *pontArq;
    veiculo *veic;
    pontArq = fopen(arqnome,"r");
    while (!feof(pontArq))
    {
        /* code */
        char aux[250];
        char *ps;
        char cor[10];
        veic=(veiculo *)malloc(sizeof(veiculo));
        fgets(aux,250,pontArq);
        ps=strtok(aux,",");
        if(ps){
            strcpy(veic->placa,ps);
            ps=strtok(NULL,", ");
            strcpy(veic->modelo,ps);
            ps=strtok(NULL,", ");
            strcpy(veic->marca,ps);
            ps=strtok(NULL,", ");
            veic->quilometragem=atoi(ps);
            ps=strtok(NULL,", ");
            strcpy(cor,ps);
            ps=strtok(NULL,", ");
            strcpy(veic->cpf,ps);
            ps=NULL;
        }
        printf("%s\n",veic->placa);
        //printf("%s,%s,%s,%d,%s\n",veic->placa,veic->modelo,veic->marca,veic->quilometragem,veic->cpf);
        appendLista(lst,veic);
    }
    fclose(pontArq);
    return lst;
} //Letra C

Lista lDonos(Lista lA,Lista lB){
    Lista lst=criaLista();
    tdono *donoV;
    veiculo *veic;
    proprietario *dono;
    int ret;

    for (int i=0;i<lA->tamanho;i++){
        donoV=(tdono*)malloc(sizeof(tdono));
        dono=(proprietario*)dadoListaProf(lA,i);

        for(int j=0;j<lB->tamanho;j++){
            veic=(veiculo*)dadoListaProf(lB,j);
            ret=strncmp(veic->cpf,dono->cpf,9);
            if(ret==0){
                strcpy(donoV->cpf,dono->cpf);
                strcpy(donoV->nome,dono->nome);
                strcpy(donoV->email,dono->email);
                strcpy(donoV->placa,veic->placa);
                strcpy(donoV->modelo,veic->modelo);
                strcpy(donoV->marca,veic->marca);
                printf("%s, ",donoV->cpf);                
                printf("%s, ",donoV->nome);                
                printf("%s, ",donoV->modelo);                
                printf("%s\n",donoV->placa); //debugando preenche normal
                appendLista(lst,donoV); // porem no final os modelos estao diferentes
            }

        }

    }
    return lst;
} //Letra E

void preencheDonos(Lista lD,char arqnome[]){
    tdono *dV;
    FILE *pontArqv;
    pontArqv = fopen(arqnome,"w");
    dV=(tdono*)malloc(sizeof(tdono));
    for(int i=0;i<lenLista(lD);i++){
        dV=(tdono*)dadoListaProf(lD,i);
        fprintf(pontArqv,"%s,%s,%s,%s,%s,%s\n",dV->cpf,dV->nome,dV->email,dV->placa,dV->modelo,dV->marca);//por algum motivo ta preenchendo repetido
    }
    fclose(pontArqv);
}

int main(){
    Lista listaA;// Letra B
    Lista listaB;//Letra B
    Lista donos;
    listaA=lPessoa("bdproprietarios.txt");
    printf("\n\n\n\n\n");
    listaB=lVeiculo("bdveiculos_donos.txt");
    donos=lDonos(listaA,listaB);
    preencheDonos(donos,"bd-donos-veiculos.txt");
    return 0;
}