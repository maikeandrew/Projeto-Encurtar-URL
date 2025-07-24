#include "encurtador_funcoes.h"

URLNo *tabela[TAM];

unsigned int hash(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % TAM;
}

void gerarChave(unsigned int num, char *saida) {
    const char *base62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char temp[6];
    int i = 0;

    do {
        temp[i++] = base62[num % 62];
        num /= 62;
    } while (num > 0 && i < 5);

    while (i < 5)
        temp[i++] = 'a';

    for (int j = 0; j < 5; j++)
        saida[j] = temp[4 - j];

    saida[5] = '\0';
}

void inicializarTabela() {
    for (int i = 0; i < TAM; i++)
        tabela[i] = NULL;
}

void inserirURL(char *url, char *saida_html) {
    unsigned int h = hash(url);
    char chave[20];
    gerarChave(h, chave);

    FILE *fp = fopen("LinkdeUrl.txt", "a");
    if (fp) {
        fprintf(fp, "%s %s\n", chave, url);
        fclose(fp);
    }

    sprintf(saida_html,
            "<h2>URL encurtada com sucesso!</h2>"
            "<p>Chave gerada: www.Encurtadinho.com/%s</p>", chave);
}

void buscarURL(char *codigo, char *saida_html) {
    FILE *fp = fopen("LinkdeUrl.txt", "r");
    if (!fp) {
        sprintf(saida_html, "<p>Link inválido</p>");
        return;
    }

    char chave[21], url[2048], linha[4096];
    while (fgets(linha, sizeof(linha), fp)) {
        if (sscanf(linha, "%s %[^\n]", chave, url) == 2 && strcmp(chave, codigo) == 0) {
            sprintf(saida_html,
                    "<h2>Resultado da busca:</h2>"
                    "<p><strong>URL encurtada:</strong> https://www.encurtadinho.com/%s</p>"
                    "<p><strong>URL original:</strong> %s</p>", chave, url);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    sprintf(saida_html, "<h2>URL inválida</h2>");
}

void mostrarTemplateComResultado(const char *resultado) {
    FILE *fp = fopen("template.html", "r");
    if (!fp) {
        printf("Content-Type: text/html\r\n\r\n");
        printf("<html><body><p>Erro ao abrir template.html</p></body></html>");
        return;
    }

    printf("Content-Type: text/html\r\n\r\n");

    char linha[4096];
    while (fgets(linha, sizeof(linha), fp)) {
        char *pos = strstr(linha, "{{RESULTADO}}");
        if (pos) {
            *pos = '\0';
            printf("%s%s%s", linha, resultado, pos + strlen("{{RESULTADO}}"));
        } else {
            printf("%s", linha);
        }
    }

    fclose(fp);
}
