#include "lista_equipes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Formato esperado do arquivo equipes.txt (UTF-8, uma por linha):
// id;nome;responsavel;n_membros;status
// Exemplo:
// 1;Liturgia;Maria;8;Ativa
// 2;Alimentação;José;12;Preparação
// 3;Música;João;10;Ativa

static void carregar_de_arquivo(const char* caminho, ListaEquipes* lista) {
    FILE* f = fopen(caminho, "r");
    if (!f) {
        printf("Aviso: não foi possível abrir '%s'. Pulando leitura do arquivo.\n", caminho);
        return;
    }
    char linha[256];
    while (fgets(linha, sizeof(linha), f)) {
        if (linha[0] == '\n' || linha[0] == '#') continue;
        // Remove \n
        linha[strcspn(linha, "\r\n")] = '\0';

        int id, n_membros;
        char nome[64], responsavel[64], status[32];
        // Tenta ler os 5 campos
        if (sscanf(linha, "%d;%63[^;];%63[^;];%d;%31[^\n]",
                   &id, nome, responsavel, &n_membros, status) == 5) {
            EquipeParoquial* e = criar_equipe(id, nome, responsavel, n_membros, status);
            if (!inserir(lista, e)) {
                printf("Falha ao inserir equipe ID %d (lista cheia ou ID duplicado)\n", id);
            }
        } else {
            printf("Linha inválida (ignorada): %s\n", linha);
        }
    }
    fclose(f);
}

int main(void) {
    printf("==== Teste da Lista de Equipes ====\n");
    ListaEquipes* lista = criar_lista(10);

    // 1) Cria e insere manualmente algumas equipes
    inserir(lista, criar_equipe(1, "Liturgia", "Maria", 8, "Ativa"));
    inserir(lista, criar_equipe(2, "Alimentação", "José", 12, "Preparação"));
    inserir(lista, criar_equipe(3, "Música", "João", 10, "Ativa"));

    listar(lista);

    // 2) Busca
    printf("\n-- Buscando ID 2 --\n");
    EquipeParoquial* achada = buscar(lista, 2);
    if (achada) {
        printf("Encontrada: ");
        imprimir_equipe(achada);
    } else {
        printf("Equipe ID 2 não encontrada.\n");
    }

    // 3) Remove
    printf("\n-- Removendo ID 1 --\n");
    if (remover(lista, 1)) {
        printf("ID 1 removido.\n");
    } else {
        printf("Falha ao remover ID 1.\n");
    }
    listar(lista);

    // 4) Bônus: carregar de arquivo (se existir)
    printf("\n-- Carregando de 'equipes.txt' (bônus) --\n");
    carregar_de_arquivo("equipes.txt", lista);
    listar(lista);

    destruir_lista(lista);
    return 0;
}