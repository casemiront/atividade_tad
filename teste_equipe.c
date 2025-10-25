#include "equipe_paroquial.h"
#include <stdio.h>

int main(void) {
    printf("==== Teste do TAD EquipeParoquial ====\n");
    EquipeParoquial* liturgia = criar_equipe(1, "Liturgia", "Maria", 8, "Ativa");
    EquipeParoquial* musica = criar_equipe(2, "Música", "João", 12, "Preparação");
    EquipeParoquial* limpeza = criar_equipe(3, "Limpeza", "Ana", 6, "Ativa");

    imprimir_equipe(liturgia);
    imprimir_equipe(musica);
    imprimir_equipe(limpeza);

    printf("\n-- Atualizando status e membros --\n");
    atualizar_status(musica, "Ativa");
    atualizar_n_membros(limpeza, 7);

    imprimir_equipe(musica);
    imprimir_equipe(limpeza);

    liberar_equipe(liturgia);
    liberar_equipe(musica);
    liberar_equipe(limpeza);
    return 0;
}