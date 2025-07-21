#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 13

void InicializarTabela(int t[]);
void InserirTabela(int t[], int valor);  
int BuscarTabela(int t[], int chave);
void ImprimirTabela(int t[]);
int FuncaoHash(int chave);

int main() {
    int tabela[TAM], opcao, valor, retorno;

    InicializarTabela(tabela);

    do {
        printf("\nInforme o que deseja fazer:\n");
        printf("1- Inserir\n");
        printf("2- Buscar\n");
        printf("3- Imprimir\n");
        printf("4- Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Insira o valor que deseja inserir: \n");
                scanf("%d", &valor);
                InserirTabela(tabela, valor);  
                break;

            case 2:
                printf("Insira o valor que deseja buscar: \n");
                scanf("%d", &valor);
                retorno = BuscarTabela(tabela, valor);
                if (retorno != 0) {
                    printf("Valor encontrado: %d!!\n", retorno);
                } else {
                    printf("Valor nao encontrado!\n");
                }
                break;

            case 3:
                ImprimirTabela(tabela);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 4); 

    return 0;
}

void InicializarTabela(int t[]) {
    int i;
    for (i = 0; i < TAM; i++) {
        t[i] = 0;
    }
}

int FuncaoHash(int chave) {
    return chave % TAM;
}

void InserirTabela(int t[], int valor) {  
    int id = FuncaoHash(valor);
    while (t[id] != 0) {
        id = FuncaoHash(id + 1);
    }
    t[id] = valor;
}

int BuscarTabela(int t[], int chave) {
    int id = FuncaoHash(chave);
    int tentativas = 0;
    while (t[id] != 0 && tentativas < TAM) {  // Evita loop infinito
        if (t[id] == chave) {
            return t[id];
        } else {
            id = FuncaoHash(id + 1);
            tentativas++;
        }
    }
    return 0;
}

void ImprimirTabela(int t[]) {
    int i;
    for (i = 0; i < TAM; i++) {
        printf("%d = %d\n", i, t[i]);  // Corrigido: printf em vez de pritnf
    }
}