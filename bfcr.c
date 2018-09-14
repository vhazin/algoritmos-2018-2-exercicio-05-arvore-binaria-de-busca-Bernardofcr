//
//  main.c
//  Hazin 13 9
//
//  Created by Bernardo Russo on 13/09/18.
//  Copyright © 2018 Bernardo Russo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int id;
    struct no *direita;
    struct no *esquerda;
    struct no *origem;
}No;

struct no *criarArvore(int add){
    No *raiz=malloc(sizeof(No));
    raiz->id=add;
    raiz->esquerda=NULL;
    raiz->direita=NULL;
    return raiz;
}

struct no *addArvore (No *arv, int add){
    if (arv==NULL){
        arv=criarArvore(add);
    }else if(add<arv->id){
        arv->esquerda=addArvore(arv->esquerda,add);
        arv->esquerda->origem=arv;
    }else{
        arv->direita=addArvore(arv->direita,add);
        arv->direita->origem=arv;
    }
    return arv;
}
void preOrdem(struct no *arv){
    if (((arv->id)=!NULL)){
        printf(" %d",arv->id);
        preOrdem(arv->esquerda);
        preOrdem(arv->direita);
    }
}
void inOrdem(No *arv){
    if ((arv->id=!NULL)){
        inOrdem(arv->esquerda);
        printf(" %d",arv->id);
        inOrdem(arv->direita);
    }
}
void posOrdem(No *arv){
    if (arv!=NULL){
        posOrdem(arv->esquerda);
        posOrdem(arv->direita);
        printf(" %d",arv->id);
    }
}

int main() {
    int c,i=0,j=0,add = 0;
    scanf("%d",&c);
    int n[c];
    No *arvore[c];
    while (i<c){
        arvore[i]=malloc(sizeof(No));
        scanf("%d",&n[i]);
        while(j<n[i]){
            scanf("%d",&add);
            arvore[i]=addArvore(arvore[i],add);
            j++;
        }
        i++;
        j=0;
    }
    i=0;
    while (i<c){
        printf("Pre.:");
        preOrdem(arvore[i]);
        printf("\nIn..:");
        inOrdem(arvore[i]);
        printf("\nPost:");
        posOrdem(arvore[i]);
        printf("\n\n");
        i++;
    }
    
    
    return 0;
}
