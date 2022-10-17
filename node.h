#ifndef NODE_H_
#define NODE_H_
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct node{
    int id;
    double x;
    double y;
}Node;

Node* criaNode();

double calculaDist(int i, int j,Node** vNodes,int numVertices);

Node* findNode(int i,Node** array,int size);

void liberaNode(Node* a);

int getID(Node* n);

double getX(Node* n);

double getY(Node* n);


#endif