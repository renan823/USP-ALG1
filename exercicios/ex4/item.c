#include "item.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct item_ {
    int chave;
    void *comp;
};

ITEM *item_criar(int chave, void *comp) {
    ITEM *item = (ITEM *) malloc(sizeof(ITEM));

    if (item == NULL) {
        fprintf(stderr, "ERRO: Sem memória!\n");
    }

    item->chave = chave;
    item->comp = comp;

    return(item);
}

bool item_apagar(ITEM **item) {
    if (*item != NULL) {
        free(*item);
        *item = NULL;

        return(true);
    }

    return(false);
}

int item_get_chave(ITEM *item) {
    return(item->chave);
}

bool item_set_chave(ITEM *item, int chave) {
    item->chave = chave;

    return(true);
}

void *item_get_dados(ITEM *item) {
    return(item->comp);
}