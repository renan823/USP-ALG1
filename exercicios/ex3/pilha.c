#include "item.h"
#include "pilha.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct pilha {
    ITEM *items[TAM];
    int tamanho;
};

PILHA *pilha_criar() {
    PILHA *pilha = (PILHA *) malloc(sizeof(PILHA));

    if (pilha == NULL) {
        fprintf(stderr, "ERRO: Sem memória!\n");
    }

    pilha->tamanho = 0;
    return(pilha);
}

void pilha_apagar(PILHA **pilha) {
    if (pilha == NULL || *pilha == NULL) {
        return;
    }
    
    for (int i = 0; i < (*pilha)->tamanho; i++) {
        item_apagar(&((*pilha)->items[i]));
    }

    free(*pilha);
    *pilha = NULL;
}

bool pilha_vazia(PILHA *pilha) {
    return(pilha->tamanho == 0);
}

bool pilha_cheia(PILHA *pilha) {
    return(pilha->tamanho == TAM);
}

int pilha_tamanho(PILHA *pilha) {
    return(pilha->tamanho);
}

bool pilha_empilhar(PILHA *pilha, ITEM *item) {
    if (pilha_cheia(pilha)) {
        return(false);
    }

    pilha->items[pilha->tamanho] = item;
    pilha->tamanho++;

    return(true);
}

ITEM *pilha_desempilhar(PILHA *pilha) {
    if (pilha_vazia(pilha)) {
        return(NULL);
    }

    //precisa "apagar" o ponteiro pra item (usando auxiliar)...
    pilha->tamanho--;

    ITEM *item = pilha->items[pilha->tamanho];
    pilha->items[pilha->tamanho] = NULL;

    return(item);
}

ITEM *pilha_topo(PILHA *pilha) {
    if (pilha_vazia(pilha)) {
        return(NULL);
    }

    return(pilha->items[pilha->tamanho-1]);
}
