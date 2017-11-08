/*
  Lab07: Painel de Controle de Programas
  Nome: Fabio Stori
  RA: 196631
  Nome: Adivair Satan Ramos
  RA: 193325
  Turma E - MC202
*/

#include<stdlib.h>
#include<stdio.h>

typedef struct Pasta{
  struct Pasta *dir;
  struct Pasta *esq;
  struct Pasta *pai;
  char programa[30];
}Pasta;

void inserir (Pasta *pasta, char programa[30]);

void alocar (Pasta *pasta, char programa[30]);

void imprimeInOrdem(Pasta *pasta);

void inicializaRaiz(Pasta *raiz);

int  main(){
  int op, P, i;
  Pasta *raiz = malloc(sizeof(Pasta));
  inicializaRaiz(raiz);
  scanf("%d", &P);
  
  char in-ordem[P][30], pre-ordem[P][30], programa[30];
  
  for(i=0;i<P;i++)
    scanf("%s", in-ordem[i]);
  for(i=0;i<P;i++)
    scanf("%s", pre-ordem[i]);
  
  while(scanf("%d", &op)!= EOF){    //ate o arquivo acabar...
    
    switch(op){     
      case(1):
        scanf("%s", programa);
        inserir(raiz, programa);    //raiz sera o no inicial que eu ainda nao criei nessa versao
      break;

      case(2):
      break;

      case(3): 
      break;

      case(4):           
      break;

      case(5):
      break;

      case(6):
      break;

      case(7):
        imprimeInOrdem(raiz);
      break;
    }
  }
  printf("\n");
  return 0;
}
void inicializaRaiz(Pasta *raiz){
  raiz->pai = NULL;
  raiz->dir = NULL;
  raiz->esq = NULL;
}
void inserir (Pasta *pasta, char programa[30]){
  if(pasta){
    int teste = strcmp(programa, pasta->programa);
    if(teste<0)
      inserir(pasta, programa);
    else
      inserir(pasta, programa);
  }else{
    alocar(pasta, programa);
  }
}

void alocar (Pasta *pasta, char programa[30]){
  Pasta *novo = malloc(sizeof(Pasta));
  novo->pai = pasta;
  strcpy(pasta->programa, programa);
  novo->dir = NULL;
  novo->esq = NULL;
}
void imprimeInOrdem(Pasta *pasta){
  if(pasta){
    imprimeInOrdem(pasta->esq);
    printf("Programa: %s", pasta->programa);
    imprimeInOrdem(pasta->dir);
  }
}

