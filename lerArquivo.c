#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int origem;
    int destino;
} Aresta;

Aresta* lerListaArestas(const char* nomeArquivo, int nArestas) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        nArestas = 0;
        return NULL;
    }
    Aresta* lista = (Aresta*)malloc(nArestas * sizeof(Aresta));

    for (int i = 0; i < nArestas; i++) {
        if (fscanf(arquivo, "%d %d", &lista[i].origem, &lista[i].destino) != 2) {
            free(lista);
            fclose(arquivo);
            nArestas = 0;
            return NULL;
        }
    }

    fclose(arquivo);
    return lista;
}