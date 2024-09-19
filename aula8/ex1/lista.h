#ifndef LISTA_H
    #define LISTA_H
    #define MAX 200

    #include "item.h"
    #include <stdbool.h>

    typedef struct lista_ LISTA;

    LISTA* lista_criar(bool ordenada);
    void lista_apagar(LISTA** lista);

    bool lista_inserir(LISTA* lista, ITEM* item);
    bool lista_inserir_posicao(LISTA* lista, int posicao, ITEM* item);

    ITEM* lista_remover(LISTA* lista, int chave);
    ITEM* lista_remover_posicao(LISTA* lista, int posicao);

    ITEM* lista_buscar(LISTA* lista, int chave);

    int lista_tamanho(LISTA* lista);
    bool lista_cheia(LISTA* lista);
    bool lista_vazia(LISTA* lista);

    void lista_print(LISTA* lista);
#endif



    