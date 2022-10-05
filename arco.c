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

double getPeso(Arco* a){
    return a->peso;
}