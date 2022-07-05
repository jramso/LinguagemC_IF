#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadLista.h"

typedef struct {
  char nome[120];
  char cpf[11];
  int idade;
  float altura;

}tpessoas;

Lista preencheLstStrs(char *nomearq) {
  FILE *arq = fopen(nomearq, "rt");
  char *linha;
  Lista lst = criaLista();

  while(!feof(arq)) {
    linha = (char *)malloc(sizeof(char) * 120);
    fgets(linha, 2000, arq);
    linha[strlen(linha)-1] = '\0';
    appendLista(lst, linha);
  }

  fclose(arq);
  return lst;
}

Lista preencheLstInts(char *nomearq) {
  FILE *arq = fopen(nomearq, "rt");
  char *linha = (char *)malloc(sizeof(char) * 128);
  // ou char linha[1000]
  int *dadoint;
  Lista lst = criaLista();

  while(!feof(arq)) {
    fgets(linha, 2000, arq);
    linha[strlen(linha)-1] = '\0';

    dadoint = (int*)malloc(sizeof(int));
    //*dadoint = atoi(linha);
    fscanf(arq,"%d",dadoint);
    appendLista(lst, dadoint);
  }

  fclose(arq);
  free(linha);
  return lst;
}

Lista preencheLstFloats(char *nomearq) {
  FILE *arq = fopen(nomearq, "rt");
  char *linha = (char *)malloc(sizeof(char) * 120);
  // ou char linha[1000]
  float *dadofloat;
  Lista lst = criaLista();

  while(!feof(arq)) {
    //linha[strlen(linha)-1] = '\0';
    dadofloat = (float*)malloc(sizeof(float));
    fscanf(arq,"%f", dadofloat); //fgets(linha, 2000, arq);
    //dadofloat* = atoi(linha);
    appendLista(lst, dadofloat);
  }

  fclose(arq);
  free(linha);
  return lst;
  
}

Lista preencheLstPessoas(Lista lstnomes, Lista lstcpfs, Lista lstidades, Lista lstalturas) {
  tpessoas *pessoa;
  Lista lst = criaLista();
  int quantidade = lenLista(lstnomes);

  for(int i=0; i < quantidade; i++) {
    pessoa = (tpessoas*)malloc(sizeof(tpessoas));
    strcpy(pessoa->nome, (char*)dadoLista(lstnomes, i));
    strcpy(pessoa->cpf, (char*)dadoLista(lstcpfs, i));
    pessoa->idade = *((int*)dadoLista(lstidades, i));
    pessoa->altura = *((float *)dadoLista(lstalturas, i));
    appendLista(lst, pessoa);
  }

  return lst;
}

Lista salvaLstPessoas(Lista lstpessoas, char *nomearq) {
  tpessoas *pessoa;
  FILE *arq = fopen(nomearq,"wt");
  int quantidade = lenLista(lstpessoas);

  for(int i=0; i < quantidade; i++) {
    pessoa = (tpessoas*)dadoLista(lstpessoas, i);
    fprintf(arq, "%s, %s, %d, %.2f\n", pessoa->nome, pessoa->cpf, pessoa->idade, pessoa->altura);
  }
  
  fclose(arq);
  return lstpessoas;
}


int main(void) {

  Lista lstnomes;
  Lista lstcpfs;
  Lista lstidades;
  Lista lstalturas;
  Lista lstpessoas;

  lstnomes = preencheLstStrs("bdnomes.txt");
  lstcpfs = preencheLstStrs("bdcpfs.txt");
  lstidades = preencheLstInts("bdidades.txt");
  lstalturas = preencheLstFloats("bdalturas.txt");
  lstpessoas = preencheLstPessoas(lstnomes, lstcpfs, lstidades, lstpessoas);
  salvaLstPessoas(lstpessoas, "bdpessoas.txt");
  
  return 0;
}