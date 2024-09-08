#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funções definidas em estrutura.c e livro.c
void adicionar_livro(char *codigo, char *titulo, char *autor, int ano);
void buscar_livro_por_titulo(char *titulo);

// Processa um arquivo de entrada
void processar_arquivo(char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo: %s\n", nome_arquivo);
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Remove o newline do final da linha
        linha[strcspn(linha, "\n")] = 0;

        if (strncmp(linha, "ADD", 3) == 0) {
            // Parse da linha ADD para extrair os dados do livro
            char codigo[20], titulo[100], autor[50];
            int ano;
            sscanf(linha, "ADD %19[^;]; %99[^;]; %49[^;]; %d", codigo, titulo, autor, &ano);
            adicionar_livro(codigo, titulo, autor, ano);
        } else if (strncmp(linha, "SEARCH", 6) == 0) {
            // Parse da linha SEARCH para extrair o título
            char titulo[100];
            sscanf(linha, "SEARCH %99[^\n]", titulo);
            buscar_livro_por_titulo(titulo);
        }
    }

    fclose(arquivo);
}

int main() {
    // Nomes dos arquivos de entrada
    char *arquivos[] = {"ent01.in", "ent02.in", "ent03.in"};
    int num_arquivos = sizeof(arquivos) / sizeof(arquivos[0]);

    // Processa cada arquivo
    for (int i = 0; i < num_arquivos; i++) {
        processar_arquivo(arquivos[i]);
    }

    return 0;
}