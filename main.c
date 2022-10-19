#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MST.h"
#include "node.h"
#include "tree.h"


int main(int argc, char* argv[]){
    if(argc < 2){
        printf("ERRO: Informe o arquivo de entrada.\n");
        return 0;
    }

    /* Leitura do arquivo */
    FILE* entry;
    
    char* fName = argv[1];

    entry = fopen(fName,"r");
    char nameFile[50],commentFile[100],typeFile[10],dimensionFile[50],weightTypeFile[50];

    if(entry==NULL){
        printf("ERRO: Problema ao abrir o arquivo.\n");
        return 0;
    }

    fgets(nameFile,50,entry); /* Salva nome do arquivo */
    fgets(commentFile,100,entry); /* Salva o comentario do arquivo */
    fgets(typeFile,50,entry); /* Salva o tipo do arquivo */
    fgets(dimensionFile,50,entry); /* Salva a dimensão do arquivo */
    fgets(weightTypeFile,50,entry); /* Salva o tipo de peso do arquivo */


    char* pDimension = strtok(dimensionFile,":");
    pDimension = strtok(NULL,":");

    int numVertices = atoi(pDimension);
    
    /* Criando vetor de vértices */

    Node** arrayNode = (Node**)malloc(numVertices * sizeof(Node*));

    char line[100];
    char* auxLine;


    fgets(line,100,entry); // Ignora o "NODE_COORD_SECTION"

    /* Leitura e atribuição das coordenadas aos vértices (Nodes) */

    while(!feof(entry)){
        fgets(line,100,entry);
        
        if(strcmp(line,"EOF") == 0){     
            break;
        }

        Node* node = criaNode();

        auxLine = strtok(line," ");
        node->id = atoi(auxLine);

        auxLine = strtok(NULL," ");
        node->x = atof(auxLine);

        auxLine = strtok(NULL, " ");
        node->y = atof(auxLine);

        arrayNode[getID(node) - 1] = node;

        //printf("%d - x : %f - y: %f\n",node->id,node->x,node->y);  
      
        //free(node);
    }

    fclose(entry);

    /* Criação da matriz de distâncias */

    double** matrizDist = (double**)malloc(numVertices * sizeof(double*));

    for(int i = 0; i < numVertices; i++){
        matrizDist[i] = (double*)malloc(numVertices*sizeof(double));
        for(int j = 0; j < numVertices; j++){       
            matrizDist[i][j] = calculaDist(i+1,j+1,arrayNode,numVertices);
        }
    }

    /* Criação do array de arcos (grafo) */

    int nArcos = (numVertices*(numVertices-1))/2;  /* Calculando o número de arcos considerando G um grafo completo */

    Arco** grafo = (Arco**)malloc(nArcos*sizeof(Arco*));

    int sizeAtual = 0;
    Node* n1,*n2;

    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < i; j++){

           
            n1 = findNode(i+1,arrayNode,numVertices);
            n2 = findNode(j+1,arrayNode,numVertices);

            grafo[sizeAtual] = criaArco(n1,n2,matrizDist[i][j]);
            sizeAtual++;
            
            
        }
    }

    /* Libera matriz */
    for(int i = 0; i < numVertices; i++){
        free(matrizDist[i]);
    }
    free(matrizDist);

    

    /* Ordenando os arcos do grafo com o Insertion sort (qsort nao funcionou) */
    sortArcos(grafo,nArcos);


    /* Criação da MST */

    int* mst = MST_init(numVertices);
    Node* nA1;
    Node* nA2;
    double pesoArco;
    Arco** arcosMST = (Arco**)malloc((numVertices-1)*sizeof(Arco*)); // Array de arcos utilizados na MST
    int posAtual = 0;

    for(int i = 0 ; i< nArcos;i++){
        nA1 = grafo[i]->leftNode;
        nA2 = grafo[i]->rightNode;
        pesoArco = grafo[i]->peso;

        if(MST_find(nA1->id-1,mst) != MST_find(nA2->id-1,mst)){
            MST_union(nA1->id-1,nA2->id-1,mst);
            arcosMST[posAtual] = grafo[i];
            posAtual++;
        }
    }


    // for(int i = 0; i < numVertices-1;i++){
    //     printf("\n%d - (%d - %d) : %.2f\n",i,arcosMST[i]->rightNode->id,arcosMST[i]->leftNode->id,arcosMST[i]->peso);
    // }

    /* Criando a arvore*/


    Tree* root = NULL;

    inserir(root,1,arcosMST,numVertices-1,0);

    //imprimir_pre_ordem(root);

    

    

   
   

    





    
    
}

