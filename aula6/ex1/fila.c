#include "item.h"
#include "fila.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct fila {
    ITEM* items[TAM];
    int tamanho;
};

FILA* fila_criar() {
    FILA* fila = (FILA*) malloc(sizeof(fila));

    if (fila != NULL) {
        fila->tamanho = 0;
    } 

    return(fila);
}

void fila_destruir(FILA** fila) {
    if (*fila == NULL) {
        return;
    }

    for(int i = 0; i < (*fila)->tamanho; i++) {
        item_destroy(&(*fila)->items[i]);
    }

    free(*fila);
    fila = NULL;
}

bool fila_inserir(FILA* fila, ITEM* item) {
    if (fila_cheia(fila)) {
        return(false);
    }

    //só inserir no final

    fila->items[fila->tamanho] = item;
    fila->tamanho++;

    return(true);
}

ITEM* fila_remover(FILA* fila) {
    if (fila_vazia(fila)) {
        return(NULL);
    }

    /*
    salvar o primeiro item em uma variavel auxiliar
    fazer um laço e "puxar" cada item para a posição anterior da lista
    começar em 0 e ir até o penultimo elemento (i < tamanho-1)
    */

    ITEM* frente = fila_frente(fila);

    for(int i = 0; i < fila->tamanho-1; i++) {
        fila->items[i] = fila->items[i+1]; //item anterior é igual ao proximo
    }

    fila->items[fila->tamanho] = NULL;
    fila->tamanho--;
    
    return(frente);
}

ITEM* fila_frente(FILA* fila) {
    if (fila_vazia(fila)) {
        return(NULL);
    }

    return(fila->items[0]);
}

int fila_tamanho(FILA* fila) {
    if (fila == NULL) {
        return(-1);
    }

    return(fila->tamanho);
}

bool fila_cheia(FILA* fila) {
    if (fila == NULL) {
        return(true);
    }

    return(fila->tamanho == TAM);
}

bool fila_vazia(FILA* fila) {
    if (fila == NULL) {
        return(false);
    }

    return(fila->tamanho == 0);
}

void fila_print(FILA* fila) {
    if (fila == NULL) {
        return;
    }

    printf("FILA: {\n");
    printf("  tamanho: %d\n", fila->tamanho);
    printf("  items: [ ");

    for(int i = 0; i < fila->tamanho; i++) {
        printf("%d ", item_get_key(fila->items[i]));
    }

    printf("]\n");
    printf("}\n");
}