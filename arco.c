#include "arco.h"

Arco* criaArco(Node* n1, Node* n2, double peso){
    Arco* arch = (Arco*)malloc(sizeof(Arco));
    arch->leftNode = n1;
    arch->rightNode = n2;
    arch->peso = peso;

    return arch;
}

// int median_of_3(Arco** a, int lo, int hi){
//     int mid = (lo + hi)/2;
//     if(a[mid]->peso < a[lo]->peso){
//         swap(a,lo,mid);
//     }
//     if(a[hi] < a[lo]){
//         swap(a,lo,hi);
//     }
//     if(a[hi] < a[mid]){
//         swap(a,hi,mid);
//     }

//     swap(a,mid,hi-1)


// }

void sortArcos(Arco** array,int lo, int hi){ // Quick sort
    //int CUTOFF = 10;

    // if(hi <= lo + CUTOFF - 1){
    //     insertion_sort_med(array, lo, hi);
    //     return;
    // }

    if(hi <= lo) return;
    
    int j = partition_med(array, lo, hi);
    
    sortArcos(array, lo, j-1);
    sortArcos(array, j+1, hi);
    
}


void insertion_sort_med(Arco** a, int lo, int hi){
    int i, j;
    for(i = lo; i <= hi; i++){
        for(j = i; j > lo && a[j]->peso < a[j-1]->peso; j--){
            swap(a,j,j-1);         
        }
    }
}


void swap(Arco** array, int i, int j){
    Arco* aux;
    aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

int partition_med(Arco** a , int lo, int hi){
    int i = lo, j = hi+1;
    double v = a[lo]->peso;

    while(1){
        while(a[++i]->peso < v) if(i == hi) break;
        while(v < a[--j]->peso) if(j == lo) break;
        if(i >= j) break;
        swap(a,i,j);
    }
    swap(a,lo,j);
    return j;
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

double calculaPesoTotal(Arco** array,int size){
    double pesoTotal = 0;
    for(int i = 0; i < size; i++){
        pesoTotal += getPeso(array[i]);
    }
    return pesoTotal;
}



void liberaArco(Arco* a){
    free(a);
}

double getPeso(Arco* a){
    return a->peso;
}

