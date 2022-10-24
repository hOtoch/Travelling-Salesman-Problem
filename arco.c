#include "arco.h"

Arco* criaArco(Node* n1, Node* n2, double peso){
    Arco* arch = (Arco*)malloc(sizeof(Arco));
    arch->leftNode = n1;
    arch->rightNode = n2;
    arch->peso = peso;

    return arch;
}



// void sortArcos(Arco** array,int lo, int hi){ // Quick sort

//     if(hi <= lo) return;
    
//     int j = partition_med(array, lo, hi);
    
//     sortArcos(array, lo, j-1);
//     sortArcos(array, j+1, hi);
    
// }

void quick_sort(Arco** a, int lo, int hi) {

    if(hi <= lo) return;
    
    int median = median_of_3(a, lo, hi);
    swap(a,lo,median);
    
    int j = partition_med(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

int median_of_3(Arco** a, int left, int right) {
    int center = (left + right) / 2;

    if (a[center]->peso < a[left]->peso)
        swap(a, left, center);
    if (a[right]->peso < a[left]->peso)
        swap(a, left, right);
    if (a[right]->peso < a[center]->peso)
        swap(a, center, right);

    swap(a, center, right - 1);
    return right - 1;
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

void liberaArrayArco(Arco** array,int size){
    for(int i = 0; i < size; i++){
        liberaArco(array[i]);
    }
}

double getPeso(Arco* a){
    return a->peso;
}

