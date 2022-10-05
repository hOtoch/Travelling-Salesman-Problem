#include "node.h"


Node* criaNode(){
    Node* node = (Node*)malloc(sizeof(Node));

    return node;
}

double calculaDist(int i, int j,Node** vNodes,int numVertices){
    double deltaX,deltaY,dist;
    Node* n1;
    Node* n2;
    
    for(int x = 0; x < numVertices;x++){
       
        if(i == getID(vNodes[x])){           
            n1 = vNodes[x];
        }
        if(j == getID(vNodes[x])){
            n2 = vNodes[x];
        }
    }

    deltaX = n2->x - n1->x;
    deltaY = n2->y - n1->y;

    dist = sqrt(pow(deltaX,2) + pow(deltaY,2));

    return dist;
}

Node* findNode(int i,Node** array,int size){
    for(int j = 0; j < size; j++){
        if(array[j]->id == i) return array[j];
    }

    return NULL;
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
