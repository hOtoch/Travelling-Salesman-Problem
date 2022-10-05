#ifndef ARCO_H_
#define ARCO_H

#include "node.h"
#include <stdio.h>


typedef struct arco{
    double peso;
    Node* leftNode;
    Node* rightNode;
}Arco;

Arco* criaArco(Node* n1, Node* n2, double peso);

// int verificaArco(int i,int j, Arco** array,int size);


#endif