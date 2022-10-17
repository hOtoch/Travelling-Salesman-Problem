#include "arco.h"

Arco* criaArco(Node* n1, Node* n2, double peso){
    Arco* arch = (Arco*)malloc(sizeof(Arco));
    arch->leftNode = n1;
    arch->rightNode = n2;
    arch->peso = peso;

    return arch;
}

void sortArcos(Arco** array,int hi){ // Insertion sort
    for(int i = 1; i < hi; i++){
        for(int j = i; j > 0; j--){
            //compexch(array[j-1],array[j]);
            
            if(array[j]->peso < array[j-1]->peso){
                Arco* aux = array[j-1];
                array[j-1] = array[j];
                array[j] = aux;
            }
        }
    }
}

int searchNext(int idNode,Arco** array,int size){
    for(int i = 0;i < size; i++){
        if(array[i] != NULL){
            if(array[i]->leftNode->id == idNode){
                idNode = array[i]->rightNode->id;
                array[i] = NULL;
                return idNode;
            }
            if(array[i]->rightNode->id == idNode){
                idNode = array[i]->leftNode->id;
                array[i] = NULL;
                return idNode;
            }
        }
        
    }
    return 0;
}









void liberaArco(Arco* a){
    free(a);
}

double getPeso(Arco* a){
    return a->peso;
}