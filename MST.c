#include "MST.h"

int* MST_init(int n){ // Inicia o vetor com os vértices
    int* mst = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        mst[i] = i;
    }
    return mst;
}

int MST_find(int x,int* mst){ // Procura e retorna o pai de x
    while (x != mst[x]) x = mst[x];
    return x;
}

void MST_union(int p, int q, int* mst){
    int i = MST_find(p,mst);
    int j = MST_find(q,mst);
    mst[i] = j;
}




