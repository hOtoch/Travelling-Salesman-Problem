#ifndef TREE_TREE_H
#define TREE_TREE_H
#include "arco.h"

//Estrutura da arvore
typedef struct tree {
    int valor;
    struct tree *esq;
    struct tree *dir;
    double pesoTotal;
} Tree;

//Funcao para criar uma arvore
Tree *criar_arvore(int valor);

//Funcao para inserir um no na arvore
void inserir(Tree *arvore, int valor,Arco** arcos,int size);

//Remover no
//Tree *remover(Tree *arvore, int valor);

//Tree *pre_ordem_iterativo(Tree *arvore);

//Funcao para imprimir a arvore
void imprimir_arvore(Tree *arvore);

//Funcao para imprimir a arvore em pre-ordem
void imprimir_pre_ordem(Tree *arvore);

#endif //TREE_TREE_H