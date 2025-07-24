// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encurtador.h"

int main() {
    // Inicia a tabela em RAM (pode ser usada em futuras expansões)
    inicializarTabela();

    // Saída para HTML
    char *query = getenv("QUERY_STRING");
    char saida[4096] = "";

    printf("Content-Type: text/html\r\n\r\n");

    if (query && strlen(query) > 0) {
        if (strncmp(query, "url=", 4) == 0) {
            inserirURL(query + 4, saida);
        } else if (strncmp(query, "busca=", 6) == 0) {
            buscarURL(query + 6, saida);
        } else {
            strcpy(saida, "<p>Parâmetro inválido.</p>");
        }
    } else {
        strcpy(saida, "<p>Nenhum parâmetro recebido.</p>");
    }

    mostrarTemplateComResultado(saida);
    return 0;
}
