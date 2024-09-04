#ifndef FILA_H
    #define FILA_H
    #define TAM 100

    #include "item.h"
    #include <stdbool.h>
    
    typedef struct fila FILA;

    FILA* fila_criar();
    void fila_destruir(FILA** fila);

    bool fila_inserir(FILA* fila, ITEM* item);
    ITEM* fila_remover(FILA* fila);

    ITEM* fila_frente(FILA* fila);
    int fila_tamanho(FILA* fila);
    bool fila_cheia(FILA* fila);
    bool fila_vazia(FILA* fila);

    void fila_print(FILA* fila);
#endif