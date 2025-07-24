// encurtador_funcoes.h
#ifndef ENCURTADOR_FUNCOES_H
#define ENCURTADOR_FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100003

typedef struct URLNo {
    char chave[20];
    char url[2048];
    struct URLNo *prox;
} URLNo;

extern URLNo *tabela[TAM];

unsigned int hash(char *str);
void gerarChave(unsigned int num, char *saida);
void inicializarTabela();
void inserirURL(char *url, char *saida_html);
void buscarURL(char *codigo, char *saida_html);
void mostrarTemplateComResultado(const char *resultado);

#endif
