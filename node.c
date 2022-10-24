#include "node.h"


Node* criaNode(){
    Node* node = (Node*)malloc(sizeof(Node));

    return node;
}

double calculaDist(int i, int j,Node** vNodes,int numVertices){
    double deltaX,deltaY,dist;
    Node* n1;
    Node* n2;

    n1 = vNodes[i];
    n2 = vNodes[j];
    

    deltaX = n2->x - n1->x;
    deltaY = n2->y - n1->y;

    dist = sqrt(pow(deltaX,2) + pow(deltaY,2));

    return dist;
}

Node* findNode(int i,Node** array,int size){
    for(int j = 0; j < size; j++){
        if(array[j]->id == i) return array[j];
    }

    return 0;
}

void liberaNode(Node* a){
    free(a);
}

int getID(Node* n){
    return n->id;
}

double getX(Node* n){
    return n->x;
}

double getY(Node* n){
    return n->y;
}

void liberaArrayNode(Node** array,int size){
    for(int i = 0; i < size; i++){
        liberaNode(array[i]);
    }
    free(array);
}
