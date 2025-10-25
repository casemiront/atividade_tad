#ifndef EQUIPE_PAROQUIAL_H
#define EQUIPE_PAROQUIAL_H

// TAD simples: EquipeParoquial (tipo opaco)
typedef struct equipe_paroquial EquipeParoquial;

// Cria uma equipe com os campos informados.
// Retorna ponteiro válido em caso de sucesso ou NULL em caso de erro.
EquipeParoquial* criar_equipe(int id, const char* nome, const char* responsavel, int n_membros, const char* status);

// Libera a memória de uma equipe.
void liberar_equipe(EquipeParoquial* e);

// Imprime os dados de uma equipe em uma única linha.
void imprimir_equipe(const EquipeParoquial* e);

// Getters básicos
int get_id(const EquipeParoquial* e);
const char* get_nome(const EquipeParoquial* e);
const char* get_responsavel(const EquipeParoquial* e);
int get_n_membros(const EquipeParoquial* e);
const char* get_status(const EquipeParoquial* e);

// Operações de atualização
void atualizar_status(EquipeParoquial* e, const char* novo_status);
void atualizar_n_membros(EquipeParoquial* e, int novo_n_membros);

#endif // EQUIPE_PAROQUIAL_H