#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MST.h"
#include "node.h"
#include "tree.h"
#include "time.h"



int main(int argc, char* argv[]){
    clock_t start,stop;
    if(argc < 2){
        printf("ERRO: Informe o arquivo de entrada.\n");
        return 0;
    }

    /* Leitura do arquivo */
    FILE* entry;
    
    start = clock();
    
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
        for(int j = 0; j < i; j++){       
            matrizDist[i][j] = calculaDist(i,j,arrayNode,numVertices);
        }
    }

    
    
    /* Criação do array de arcos (grafo) */

    int nArcos = (numVertices*(numVertices-1))/2;  /* Calculando o número de arcos considerando G um grafo completo */
    //printf("%d\n",nArcos);

    Arco** grafo = (Arco**)malloc(nArcos*sizeof(Arco*));

    

    int sizeAtual = 0;
    Node* n1,*n2;


    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < i; j++){

            n1 = arrayNode[i];
            n2 = arrayNode[j];

            grafo[sizeAtual] = criaArco(n1,n2,matrizDist[i][j]);
            sizeAtual++;
            
        }
    }

    
   
    

    /* Libera matriz */
    for(int i = 0; i < numVertices; i++){
        free(matrizDist[i]);
    }
    free(matrizDist);

    


    quick_sort(grafo,0,nArcos-1);
    //sortArcos(grafo,0,nArcos-1); // fazer quick sort
    
    

    // for(int i = 0; i < nArcos;i++){
    //     printf("\n%d - (%d - %d) : %.2f\n",i,grafo[i]->rightNode->id,grafo[i]->leftNode->id,grafo[i]->peso);
    // }

    


    

    /* Criação da MST */

    int* mst = MST_init(numVertices);
    Node* nA1;
    Node* nA2;
    Arco** arcosMST = (Arco**)malloc((numVertices-1)*sizeof(Arco*)); // Array de arcos utilizados na MST
    int posAtual = 0;

    for(int i = 0 ; i< nArcos;i++){
        nA1 = grafo[i]->leftNode;
        nA2 = grafo[i]->rightNode;
       

        if(MST_find(nA1->id-1,mst) != MST_find(nA2->id-1,mst)){
            MST_union(nA1->id-1,nA2->id-1,mst);
            arcosMST[posAtual] = grafo[i];
            posAtual++;
        }
    }


    // /* Criando a arvore*/

   
    Tree* root = NULL;

    inserir(root,1,arcosMST,numVertices-1);

    //criaArquivoSaida(arcosMST, numVertices - 1, arrayNode, numVertices, entry);

    


    //imprimir_pre_ordem(root);

    liberar_arvore(root);
    liberaArrayNode(arrayNode,numVertices);
    liberaArrayArco(arcosMST,numVertices-1);
    liberaArrayArco(grafo,nArcos);
    MST_libera(mst);

    stop = clock(); 
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.6f\n",time_taken);


    
}

