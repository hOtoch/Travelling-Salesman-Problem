#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "arco.h"


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

            //printf("(%d - %d) : %.2f\n",n1->id,n2->id,matrizDist[i][j]);

            grafo[sizeAtual] = criaArco(n1,n2,matrizDist[i][j]);
            sizeAtual++;
            
            
        }
    }

    //printf("%d arcos e %d vertices\n",sizeAtual,numVertices);



    for(int i = 0; i< nArcos;i++){
        printf("(%d - %d) : %.2f\n",grafo[i]->leftNode->id,grafo[i]->rightNode->id,grafo[i]->peso);
    }







    
    
      

    
    
}

