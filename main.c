#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"


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

    fgets(nameFile,50,entry); 
    fgets(commentFile,100,entry);
    fgets(typeFile,50,entry);
    fgets(dimensionFile,50,entry);
    fgets(weightTypeFile,50,entry);


    char* pDimension = strtok(dimensionFile,":");
    pDimension = strtok(NULL,":");

    int numVertices = atoi(pDimension);
    
    // Criando vetor de Nós

    Node** arrayNode = (Node**)malloc(numVertices * sizeof(Node*));

    char line[100];
    char* auxLine;


    fgets(line,100,entry); // Ignora o "NODE_COORD_SECTION"

    while(!feof(entry)){
        fgets(line,100,entry);
        if(line == "EOF"){
            break;
        }

        if(line==NULL){
            continue;
        }

        printf("%s\n",line);

        Node* node = criaNode();

        auxLine = strtok(line," ");
        node->id = atoi(auxLine);

        auxLine = strtok(NULL," ");
        node->x = atof(auxLine);

        auxLine = strtok(NULL, " ");
        node->y = atof(auxLine);

        //printf("%d - x : %f - y: %f\n",node->id,node->x,node->y);  
       

        
        free(node);
    }

    
      

    
    
}

