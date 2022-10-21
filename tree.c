#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Tree *criar_arvore(int valor) {
    Tree *arvore = (Tree *) malloc(sizeof(Tree));
    arvore->valor = valor;
    arvore->pesoTotal = 0;
    arvore->esq = NULL;
    arvore->dir = NULL;
    return arvore;
}

void inserir(Tree *arvore, int valor,Arco** arcos,int size) {
    int id1,id2;
    if (arvore == NULL) {
        arvore = criar_arvore(valor);
    }
    //printf("%d\n",valor);


    id1= searchNext(valor,arcos,size); 
    if(id1 != 0){
        inserir(arvore->esq, id1,arcos,size);
    }else return;


    id2 = searchNext(valor,arcos,size);
    if(id2 != 0){
        inserir(arvore->dir, id2,arcos,size);
    }else return;
    

}
// Tree *pre_ordem_iterativo(Tree *arvore) {
//     if (arvore == NULL) {
//         return NULL;
//     }
//     Tree *tree = criar_arvore(arvore->valor);
//     inserir(tree, arvore->valor);
//     while (!arvore->esq == NULL) {
//         Tree *node = remover(arvore, arvore->esq->valor);
//         printf("%d ", node->valor);
//         if (node->dir != NULL) {
//             inserir(tree, node->dir->valor);
//         }
//         if (node->esq != NULL) {
//             inserir(tree, node->esq->valor);
//         }
//     }
//     return arvore;
// }

void imprimir_arvore(Tree *arvore) {
    if (arvore == NULL) {
        return;
    }
    imprimir_arvore(arvore->esq);
    printf("%d ", arvore->valor);
    imprimir_arvore(arvore->dir);
}

void imprimir_pre_ordem(Tree *arvore) {
    if (arvore == NULL) {
        return;
    }
    printf("%d ", arvore->valor);
    imprimir_pre_ordem(arvore->esq);
    imprimir_pre_ordem(arvore->dir);
}
