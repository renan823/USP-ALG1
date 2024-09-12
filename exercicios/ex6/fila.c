#include "item.h"
#include "fila.h"
#include "apagar.c"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct fila_ {
    NO* inicio;
    NO* fim;
    int tamanho;
};

struct no_ {
    ITEM* item;
    NO* proximo;
};

FILA* fila_criar() {
    FILA* fila = (FILA*) malloc(sizeof(FILA));

    if (fila != NULL) {
        fila->tamanho = 0;
        fila->inicio = NULL;
        fila->fim = NULL;
    } 

    return(fila);
}


bool fila_inserir(FILA* fila, ITEM* item) {
    if (fila_cheia(fila)) {
        return(false);
    }

    /*
    criar novo no (e atribuir valores)
    se tamanho = 0; inicio = no
    senão se fim = NULL -> fim = no
        senão: mudar o ponteiro fim e trocar o no
    */

    NO* no = (NO*) malloc(sizeof(NO));
    if (no == NULL) {
        return(false);
    }

    no->item = item;
    no->proximo = NULL;

    if (fila_vazia(fila)) {
        fila->inicio = no;
        fila->fim = no;
    } else {
        fila->fim->proximo = no;
        fila->fim = no;
    }

    fila->tamanho++;

    return(true);
}

ITEM* fila_remover(FILA* fila) {
    if (fila_vazia(fila)) {
        return(NULL);
    }

    /*
    salvar o fila->inicio em um aux
    salvar aux->item
    fazer fila->inicio receber aux->proximo
    aux->item = NULL e proximo = NULL
    liberar aux
    retornar o item
    */

    NO* inicio = fila->inicio;
    ITEM* item = inicio->item;

    fila->inicio = inicio->proximo;

    inicio->item = NULL;
    inicio->proximo = NULL;

    free(inicio);

    return(item);
}

ITEM* fila_inicio(FILA* fila) {
    if (fila_vazia(fila)) {
        return(NULL);
    }

    return(fila->inicio->item);
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

    NO* atual = fila->inicio;
    while (atual != NULL) {
        printf("%d ", item_get_chave(atual->item));
        atual = atual->proximo;
    }

    printf("]\n");
    printf("}\n");
}

