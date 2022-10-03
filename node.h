#ifndef NODE_H_
#define NODE_H_
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int id;
    double x;
    double y;
}Node;

Node* criaNode();


#endif