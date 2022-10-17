#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Tree *criar_arvore(int valor) {
    Tree *arvore = (Tree *) malloc(sizeof(Tree));
    arvore->valor = valor;
    arvore->esq = NULL;
    arvore->dir = NULL;
    return arvore;
}

Tree *inserir(Tree *arvore, int valor) {
    if (arvore == NULL) {
        return criar_arvore(valor);
    }
    
    if(valor == 0){
        return;
    }
    
    arvore->esq = inserir(arvore->esq, valor);//se valor < arvore->valor
   
    arvore->dir = inserir(arvore->dir, valor);
    

    
    
    
    return arvore;
}

// Tree *remover(Tree *arvore, int valor) {
//     if (arvore == NULL) {
//         return arvore;
//     }
//     if (valor < arvore->valor) {
//         arvore->esq = remover(arvore->esq, valor);
//     } else if (valor > arvore->valor) {
//         arvore->dir = remover(arvore->dir, valor);
//     } else {
//         if (arvore->esq == NULL) {
//             Tree *temp = arvore->dir;
//             free(arvore);
//             return temp;
//         } else if (arvore->dir == NULL) {
//             Tree *temp = arvore->esq;
//             free(arvore);
//             return temp;
//         }
//         Tree *temp = arvore->dir;
//         while (temp->esq != NULL) {
//             temp = temp->esq;
//         }
//         arvore->valor = temp->valor;
//         arvore->dir = remover(arvore->dir, temp->valor);
//     }
//     return arvore;
// }

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