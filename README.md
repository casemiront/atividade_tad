# Relatório — Atividade TADs (Monitoramento de Equipes da Paróquia)

**Curso:** Sistemas de Informação  
**Disciplina:** Algoritmos e Estruturas de Dados I  
**Atividade:** Atividade Prática 1 — Tipos Abstratos de Dados  
**Aluno:** Preencha seu nome  
**Matrícula:** Preencha sua matrícula

## 1. Escolhas de modelagem
Foi escolhido representar o domínio de **equipes da paróquia** envolvidas em festejos (Liturgia, Alimentação, Música etc.).  
O TAD simples `EquipeParoquial` contém: `id` (chave), `nome`, `responsavel`, `n_membros`, `status`.
Motivação: facilitar o **monitoramento** do andamento e da organização dos grupos durante os eventos.

### Exemplos de instâncias
- `id=1, nome="Liturgia", responsavel="Maria", n_membros=8, status="Ativa"`  
- `id=2, nome="Alimentação", responsavel="José", n_membros=12, status="Preparação"`

## 2. Detalhes de implementação (Partes 1, 2 e 3)
- **Parte 1 — TAD simples:** Tipo opaco, funções `criar/liberar/imprimir`, getters e operações de atualização (`atualizar_status`, `atualizar_n_membros`).
- **Parte 2 — TAD Lista (sequencial):** Vetor de ponteiros com capacidade fixa, operações `criar/destruir`, informativas (`cheia`, `vazia`, `capacidade`, `tamanho`), manipulação (`inserir`, `buscar`, `remover`) e `listar`. Previne **IDs duplicados**.
- **Parte 3 — Testes:**
  - `teste_equipe.c` demonstra todas as operações do TAD simples.
  - `teste_lista.c` demonstra inserção, busca, remoção e listagem. Lê dados de `equipes.txt` (bônus).  
  - **Não** usa `scanf()`. Valores estão embutidos no código, conforme solicitado.

## 3. Reflexão
- **Aprendizado:** Encapsulamento com tipos opacos, API limpa de TADs, manipulação de vetores e ponteiros, responsabilidades de alocação e liberação.
- **Maior desafio:** Evitar vazamentos de memória e gerenciar IDs duplicados. Foi resolvido centralizando `liberar_equipe` na lista e validando duplicatas em `inserir`.
- **Aplicação futura:** O padrão TAD + Lista pode ser reutilizado para cadastro de voluntários, eventos e recursos, ou em outras disciplinas que exijam modularização.
