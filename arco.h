#ifndef ARCO_H_
#define ARCO_H

#include "node.h"
#include <stdio.h>


typedef struct arco{
    double peso;
    Node* leftNode;
    Node* rightNode;
}Arco;

Arco* criaArco(Node* n1, Node* n2, double peso);

int compararPeso(const void* x, const void* y);

double getPeso(Arco* a);

void liberaArco(Arco* a);

void sortArcos(Arco** array,int lo,int hi);

void swap(Arco** array,int i, int j);

void insertion_sort_med(Arco** a, int lo, int hi);

int partition_med(Arco**a, int lo, int hi);

void preOrder(Node* nd,Node** N_array,Arco** A_array,int size);

int searchNext(int idNode,Arco** array,int size);

double calculaPesoTotal(Arco** array,int size);

void liberaArrayArco(Arco** array,int size);

void quick_sort(Arco** a, int lo, int hi);

int median_of_3(Arco** a, int left, int right);

#endif