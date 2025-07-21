#include <stdio.h>
#include <stdlib.h>
#include "lerArquivo.c"

void inicializarMatriz(int **matriz, int numVertices) {
    int i, j;
    for (i = 0; i < numVertices; ++i) {
        for (j = 0; j < numVertices; ++j) {
            matriz[i][j] = 0;
        }
    }
}

void adicionarAresta(int** matriz, int origem, int destino, int numVertices) {
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
        matriz[origem][destino] = 1;
        matriz[destino][origem] = 1; 
    }
}

void mostrarMatriz(int** matriz, int numVertices) {
    int i, j;
    for (i = 0; i < numVertices; ++i) {
        for (j = 0; j < numVertices; ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i;
    const char* nomeArquivo = "clube_da_luta.dat";
    int nArestas = 78;
    int nVertices = 34;
    Aresta* lista = lerListaArestas(nomeArquivo, nArestas);
    int **matriz = (int**) malloc(nVertices*sizeof(int*));
    for (i = 0; i < nVertices; i++){
        matriz[i] = (int*) malloc(nVertices*sizeof(int));
    }
    inicializarMatriz(matriz, nVertices);
    for (i = 0; i < nArestas; i++) {
        adicionarAresta(matriz, lista[i].origem, lista[i].destino, nVertices);
    }
    mostrarMatriz(matriz, nVertices);
    
    return 0;
}