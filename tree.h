#ifndef TREE_TREE_H
#define TREE_TREE_H

//Estrutura da arvore
typedef struct tree {
    int valor;
    struct tree *esq;
    struct tree *dir;
} Tree;

//Funcao para criar uma arvore
Tree *criar_arvore(int valor);

//Funcao para inserir um no na arvore
Tree *inserir(Tree *arvore, int valor);

//Remover no
//Tree *remover(Tree *arvore, int valor);

//Tree *pre_ordem_iterativo(Tree *arvore);

//Funcao para imprimir a arvore
void imprimir_arvore(Tree *arvore);

//Funcao para imprimir a arvore em pre-ordem
void imprimir_pre_ordem(Tree *arvore);

#endif //TREE_TREE_H