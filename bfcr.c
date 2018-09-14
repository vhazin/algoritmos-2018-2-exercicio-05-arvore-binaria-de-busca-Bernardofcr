//
//  main.c
//  Hazin 13 9
//
//  Created by Bernardo Russo on 13/09/18.
//  Copyright © 2018 Bernardo Russo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct no{//definição de estrutura de nó
    int id;
    struct no *direita;
    struct no *esquerda;
    struct no *origem;
}No;

struct no *criarArvore(int add,No *esq, No *dir){//função para criar arvore(raiz da arvore)
    No *raiz=malloc(sizeof(No));
    raiz->id=add;//grava valor no id do nó
    raiz->esquerda=esq;//grava raiz a esquerda
    raiz->direita=dir;//grava raiz a direita
    return raiz;//envia valor de raiz
}

struct no *addArvore (No *arv, int add){
    if (arv==NULL){
        arv=criarArvore(add,NULL,NULL);//quando chegar num ponto nulo
    }else if(add<arv->id){//analisa se valor é maior que ponto inicial da
        arv->esquerda=addArvore(arv->esquerda,add);//joga valor para ponteiro esquerdo
        arv->esquerda->origem=arv;
    }else{
        arv->direita=addArvore(arv->direita,add);//joga valor para ponteiro na direito
        arv->direita->origem=arv;
    }
    return arv;//retorna nova arvore com incremento
}

void preOrdem(struct no *arv){
    if (arv!=NULL){
        printf(" %d",arv->id);//printa origem
        preOrdem(arv->esquerda);//faz prints dos ponto a esquerda
        preOrdem(arv->direita);//faz prints dos ponto a direita
    }
}

void inOrdem(No *arv){
    if (arv!=NULL){
        inOrdem(arv->esquerda);//puxa ponto a esquerda para print/o ponto mais a esquerda vai ser primeiro print
        printf(" %d",arv->id);//faz print de ponto
        inOrdem(arv->direita);//puxa ponto a direita para print
    }
}

void posOrdem(No *arv){
    if (arv!=NULL){
        posOrdem(arv->esquerda);//puxa ponto a esquerda para print/o ponto mais a esquerda vai ser o primeiro print
        posOrdem(arv->direita);//puxa ponto a direita para print/printa ponto do lado direito, na mesma altura do ultimo ponto
        printf(" %d",arv->id);//faz print de ponteiro/ ultimo a ser printado vai ser origem
    }
}

int main(void) {
    int c,i=0,j=0,add=0;
    scanf("%d",&c);//leitura de repetições
    int n[c];//definição do numero de entrada/array
    No *arvore[c];//definição de arvore como array para gravar multiplos valores de raiz
    while (i<c){
        scanf("%d",&n[i]);//leitura do numero de entradas para um caso
        while(j<n[i]){
            scanf("%d",&add);//leitura de valor a ser adicionado na lista
            arvore[i]=addArvore(arvore[i],add);//agrega valor a lista
            j++;//incremento
        }
        i++;//incremento
        j=0;//reinicia j para rodar novamente no while e/ou rodar função while abaixo 
    }
    while (j<c){
        printf("Case %d:",(j+1));//print de ordenagem
        printf("\nPre.:");//ord
        preOrdem(arvore[j]);//puxa comando de print
        printf("\nIn..:");//print
        inOrdem(arvore[j]);//ord
        printf("\nPost:");
        posOrdem(arvore[j]);
        printf("\n\n");
        j++;
    }
    return 0;
}
