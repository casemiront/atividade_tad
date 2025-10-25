#include "lista_equipes.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LISTA_CAP_PADRAO
#define LISTA_CAP_PADRAO 100
#endif

struct lista_equipes {
    EquipeParoquial** dados; // vetor de ponteiros
    int n;                   // quantidade usada
    int cap;                 // capacidade total
};

static int indice_do_id(const ListaEquipes* lista, int id) {
    if (!lista) return -1;
    for (int i = 0; i < lista->n; ++i) {
        if (get_id(lista->dados[i]) == id) return i;
    }
    return -1;
}

ListaEquipes* criar_lista(int capacidade) {
    if (capacidade <= 0) capacidade = LISTA_CAP_PADRAO;
    ListaEquipes* lista = (ListaEquipes*) malloc(sizeof(ListaEquipes));
    if (!lista) return NULL;
    lista->dados = (EquipeParoquial**) calloc(capacidade, sizeof(EquipeParoquial*));
    if (!lista->dados) { free(lista); return NULL; }
    lista->n = 0;
    lista->cap = capacidade;
    return lista;
}

void destruir_lista(ListaEquipes* lista) {
    if (!lista) return;
    // libera todas as equipes armazenadas
    for (int i = 0; i < lista->n; ++i) {
        liberar_equipe(lista->dados[i]);
    }
    free(lista->dados);
    free(lista);
}

int cheia(const ListaEquipes* lista) { return lista ? (lista->n == lista->cap) : 0; }
int vazia(const ListaEquipes* lista) { return lista ? (lista->n == 0) : 1; }
int capacidade(const ListaEquipes* lista) { return lista ? lista->cap : 0; }
int tamanho(const ListaEquipes* lista) { return lista ? lista->n : 0; }

int inserir(ListaEquipes* lista, EquipeParoquial* e) {
    if (!lista || !e || cheia(lista)) return 0;
    if (indice_do_id(lista, get_id(e)) != -1) {
        // id duplicado -> não insere; libera o objeto recebido para evitar vazamento
        liberar_equipe(e);
        return 0;
    }
    lista->dados[lista->n++] = e;
    return 1;
}

EquipeParoquial* buscar(const ListaEquipes* lista, int id) {
    int idx = indice_do_id(lista, id);
    return (idx == -1) ? NULL : lista->dados[idx];
}

int remover(ListaEquipes* lista, int id) {
    if (!lista || vazia(lista)) return 0;
    int idx = indice_do_id(lista, id);
    if (idx == -1) return 0;
    // libera elemento e compacta
    liberar_equipe(lista->dados[idx]);
    for (int i = idx; i < lista->n - 1; ++i) {
        lista->dados[i] = lista->dados[i + 1];
    }
    lista->n--;
    lista->dados[lista->n] = NULL;
    return 1;
}

void listar(const ListaEquipes* lista) {
    if (!lista) { printf("(lista NULL)\n"); return; }
    if (vazia(lista)) { printf("[Lista vazia]\n"); return; }
    printf("=== LISTA DE EQUIPES (%d/%d) ===\n", lista->n, lista->cap);
    for (int i = 0; i < lista->n; ++i) {
        imprimir_equipe(lista->dados[i]);
    }
}