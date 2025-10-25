#include "equipe_paroquial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_TAM 50
#define RESPONSAVEL_TAM 50
#define STATUS_TAM 20

struct equipe_paroquial {
    int id;
    char nome[NOME_TAM];
    char responsavel[RESPONSAVEL_TAM];
    int n_membros;
    char status[STATUS_TAM];
};

static void copia_segura(char* dst, const char* src, size_t maxlen) {
    if (!dst || !src || maxlen == 0) return;
    strncpy(dst, src, maxlen - 1);
    dst[maxlen - 1] = '\0';
}

EquipeParoquial* criar_equipe(int id, const char* nome, const char* responsavel, int n_membros, const char* status) {
    if (!nome || !responsavel || !status || n_membros < 0) return NULL;
    EquipeParoquial* e = (EquipeParoquial*) malloc(sizeof(EquipeParoquial));
    if (!e) return NULL;
    e->id = id;
    e->n_membros = n_membros;
    copia_segura(e->nome, nome, NOME_TAM);
    copia_segura(e->responsavel, responsavel, RESPONSAVEL_TAM);
    copia_segura(e->status, status, STATUS_TAM);
    return e;
}

void liberar_equipe(EquipeParoquial* e) {
    if (e) free(e);
}

void imprimir_equipe(const EquipeParoquial* e) {
    if (!e) { printf("(equipe NULL)\n"); return; }
    printf("ID:%d | Equipe:%s | Responsavel:%s | Membros:%d | Status:%s\n",
           e->id, e->nome, e->responsavel, e->n_membros, e->status);
}

int get_id(const EquipeParoquial* e) { return e ? e->id : -1; }
const char* get_nome(const EquipeParoquial* e) { return e ? e->nome : NULL; }
const char* get_responsavel(const EquipeParoquial* e) { return e ? e->responsavel : NULL; }
int get_n_membros(const EquipeParoquial* e) { return e ? e->n_membros : -1; }
const char* get_status(const EquipeParoquial* e) { return e ? e->status : NULL; }

void atualizar_status(EquipeParoquial* e, const char* novo_status) {
    if (!e || !novo_status) return;
    copia_segura(e->status, novo_status, STATUS_TAM);
}

void atualizar_n_membros(EquipeParoquial* e, int novo_n_membros) {
    if (!e || novo_n_membros < 0) return;
    e->n_membros = novo_n_membros;
}