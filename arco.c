#include "arco.h"

Arco* criaArco(Node* n1, Node* n2, double peso){
    Arco* arch = (Arco*)malloc(sizeof(Arco));
    arch->leftNode = n1;
    arch->rightNode = n2;
    arch->peso = peso;

    return arch;
}

// int verificaArco(int i,int j, Arco** array,int size){
//     if(i == j) return 0;

//     for(int i = 0; i < size; i++){
//         if(array[i] == NULL) return 1;
//         if((array[i]->leftNode->id == i && array[i]->rightNode->id == j) || (array[i]->rightNode->id == i && array[i]->leftNode->id == j)) return 0;
//     }
// }