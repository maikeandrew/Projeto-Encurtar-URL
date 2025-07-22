// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encurtador_funcoes.h"

int main() {
    inicializarTabela();  // Inicializa a tabela hash (não obrigatória se não for usar em RAM)

    char *query = getenv("QUERY_STRING");
    char saida[4096] = "";

    if (query != NULL && strlen(query) > 0) {
        char par[4096];

        // Encurtar URL
        if (sscanf(query, "url=%[^\n]", par) == 1) {
            char *url = query + 4; // pula "url="
            inserirURL(url, saida);
        }
        // Buscar URL
        else if (sscanf(query, "busca=%[^\n]", par) == 1) {
            char *codigo = query + 6; // pula "busca="
            buscarURL(codigo, saida);
        }
        // Query inválida
        else {
            strcpy(saida, "<p>Parâmetro inválido na URL.</p>");
        }
    } else {
        strcpy(saida, "<p>Nenhum parâmetro recebido.</p>");
    }

    mostrarTemplateComResultado(saida);
    return 0;
}