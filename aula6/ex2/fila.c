#include "item.h"
#include "fila.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct fila {
    NO* frente;
    NO* tras;
    int tamanho;
};

struct no {
    ITEM* item;
    NO* proximo;
};

FILA* fila_criar() {
    FILA* fila = (FILA*) malloc(sizeof(FILA));

    if (fila != NULL) {
        fila->tamanho = 0;
        fila->frente = NULL;
        fila->tras = NULL;
    } 

    return(fila);
}

void fila_destruir(FILA** fila) {
    if (*fila == NULL) {
        return;
    }

    NO *prox = (*fila)->frente;
    NO *aux;

    while (prox != NULL) {
        aux = prox;
        prox = prox->proximo;
        item_destroy(&(aux->item)); //apaga o item junto
        free(aux);
    }

    free(*fila);
    *fila = NULL;
}

bool fila_inserir(FILA* fila, ITEM* item) {
    if (fila_cheia(fila)) {
        return(false);
    }

    /*
    criar novo no (e atribuir valores)
    se tamanho = 0; frente = no
    senão se tras = NULL -> tras = no
        senão: mudar o ponteiro tras e trocar o no
    */

    NO* no = (NO*) malloc(sizeof(NO));
    if (no == NULL) {
        return(false);
    }

    no->item = item;
    no->proximo = NULL;

    if (fila_vazia(fila)) {
        fila->frente = no;
        fila->tras = no;
    } else {
        fila->tras->proximo = no;
        fila->tras = no;
    }

    fila->tamanho++;

    return(true);
}

ITEM* fila_remover(FILA* fila) {
    if (fila_vazia(fila)) {
        return(NULL);
    }

    /*
    salvar o fila->frente em um aux
    salvar aux->item
    fazer fila->frente receber aux->proximo
    aux->item = NULL e proximo = NULL
    liberar aux
    retornar o item
    */

    NO* frente = fila->frente;
    ITEM* item = frente->item;

    fila->frente = frente->proximo;

    frente->item = NULL;
    frente->proximo = NULL;

    free(frente);

    return(item);
}

ITEM* fila_frente(FILA* fila) {
    if (fila_vazia(fila)) {
        return(NULL);
    }

    return(fila->frente->item);
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

    NO* no = (NO*) malloc(sizeof(NO));  
    if (no == NULL) {
        return(true);
    }

    free(no);
    return(false);
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

    NO* atual = fila->frente;
    while (atual != NULL) {
        printf("%d ", item_get_key(atual->item));
        atual = atual->proximo;
    }

    printf("]\n");
    printf("}\n");
}