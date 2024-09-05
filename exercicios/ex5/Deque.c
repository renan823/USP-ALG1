#include "item.h"
#include "Deque.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

struct deque_ {
    int tamanho;
    ITEM* items[MAX];
};

DEQUE* deque_criar() {
    DEQUE* d = (DEQUE*) malloc(sizeof(DEQUE));

    if (d != NULL) {
        d->tamanho = 0;
    }

    return(d);
}

void deque_apagar(DEQUE** deque) {
    if (*deque == NULL) {
        return;
    }

    for (int i = 0; i < (*deque)->tamanho; i++) {
        item_apagar(&(*deque)->items[i]);
    }

    free(*deque);
    *deque = NULL;
}   

bool deque_inserir_inicio(DEQUE* deque, ITEM* item) {
    if (deque_cheia(deque)) {
        return(false);
    }

    /*
    Se vazio -> inserir em items[0]
    Senão -> mover valores uma casa para direita e colocar em items[0]
    tamanho++
    */

    if (deque->tamanho == 0) {
        deque->items[0] = item;
    } else {
        for (int i = deque->tamanho; i > 0; i--) {
            deque->items[i] = deque->items[i-1];
        }
        deque->items[0] = item;
    }

    deque->tamanho++;
    return(true);
}

bool deque_inserir_fim(DEQUE* deque, ITEM* item) {
    if (deque_cheia(deque)) {
        return(false);
    }

    deque->items[deque->tamanho] = item;
    deque->tamanho++;

    return(true);
}

ITEM* deque_remover_inicio(DEQUE* deque) {
    if (deque_vazia(deque)) {
        return(NULL);
    }

    /*
    Salva o primeiro em um aux
    Puxa todos os items uma casa para esquerda
    Torna null o utimo item
    retorna aux
    */

    ITEM* item = deque->items[0];

    for (int i = 0; i < deque->tamanho-1; i++) {
        deque->items[i] = deque->items[i+1];
    }

    deque->tamanho--;
    deque->items[deque->tamanho] = NULL;

    return(item);
}

ITEM* deque_remover_fim(DEQUE* deque) {
    if (deque_vazia(deque)) {
        return(NULL);
    }

    /*
    Salva o ultimo em um aux
    coloca o ultimo lugar como null
    tamanho--
    retorna o aux
    */
    deque->tamanho--;

    ITEM* item = deque->items[deque->tamanho];
    deque->items[deque->tamanho] = NULL;

    return(item);
}

ITEM* deque_primeiro(DEQUE* deque) {
    if (deque == NULL) {
        return(NULL);
    }

    return(deque->items[0]);
}

ITEM* deque_ultimo(DEQUE* deque) {
    if (deque == NULL) {
        return(NULL);
    }

    return(deque->items[deque->tamanho-1]);
}

int deque_contar(DEQUE* deque) {
    if (deque == NULL) {
        return(-1);
    }

    return(deque->tamanho);
}

bool deque_vazia(DEQUE* deque) {
    if (deque == NULL) {
        return(false);
    }

    return(deque->tamanho == 0);
}


bool deque_cheia(DEQUE* deque) {
    if (deque == NULL) {
        return(true);
    }
   
    return(deque->tamanho == MAX);
}

void deque_print(DEQUE* deque) {
    if (deque == NULL) {
        return;
    }


    for (int i = 0; i < deque->tamanho; i++) {
        printf("%d\n", item_get_chave(deque->items[i]));
    }
}