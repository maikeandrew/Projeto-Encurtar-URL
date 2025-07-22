// encurtador.h
#ifndef ENCURTADOR_H
#define ENCURTADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100003 // Tamanho da tabela hash

// Estrutura de dados para armazenar uma URL e sua chave encurtada
typedef struct URLNo
{
    char chave[20];     // Chave curta gerada (base62)
    char url[2048];     // URL original
    struct URLNo *prox; // Ponteiro para o próximo nó (encadeamento)
} URLNo;

// Tabela hash global
extern URLNo *tabela[TAM];

// Protótipos de funções
unsigned int hash(char *str);                            // Função de hash para gerar índice
void gerarChave(unsigned int num, char *saida);          // Converte número para chave base62
void inicializarTabela();                                // Inicializa a tabela hash
void inserirURL(char *url, char *saida_html);            // Insere nova URL e gera chave
void buscarURL(char *codigo, char *saida_html);          // Busca URL pela chave
void mostrarTemplateComResultado(const char *resultado); // Exibe template HTML com resultado

#endif
