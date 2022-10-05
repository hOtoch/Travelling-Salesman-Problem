#ifndef MST_H
#define MST_H
#include <stdlib.h>


int* MST_init(int n);

int MST_find(int x,int* mst);

void MST_union(int p, int q, int* mst);


#endif 
