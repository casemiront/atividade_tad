#ifndef LISTA_EQUIPES_H
#define LISTA_EQUIPES_H

#include "equipe_paroquial.h"

// Lista sequencial de ponteiros para EquipeParoquial (tipo opaco)
typedef struct lista_equipes ListaEquipes;

// Cria uma lista com capacidade fixa (capacidade > 0).
// Se capacidade <= 0, usa um valor padrão.
ListaEquipes* criar_lista(int capacidade);

// Destrói a lista e libera TODAS as equipes contidas nela.
void destruir_lista(ListaEquipes* lista);

// Informativas
int cheia(const ListaEquipes* lista);
int vazia(const ListaEquipes* lista);
int capacidade(const ListaEquipes* lista);
int tamanho(const ListaEquipes* lista);

// Manipulação
// Retorna 1 se inseriu, 0 se falhou (cheia ou id duplicado).
int inserir(ListaEquipes* lista, EquipeParoquial* e);
// Retorna ponteiro para a equipe com o id dado, ou NULL se não encontrar.
EquipeParoquial* buscar(const ListaEquipes* lista, int id);
// Remove pelo id. Retorna 1 se removeu, 0 se não encontrou.
int remover(ListaEquipes* lista, int id);

// Impressão
void listar(const ListaEquipes* lista);

#endif // LISTA_EQUIPES_H