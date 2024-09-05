#include "item.h"
#include "Deque.h"

#include <stdbool.h>
#include <stdlib.h>

struct no_ {
    ITEM* valor;
    NO* proximo;
};

struct deque_ {
    int tamanho;
    NO* inicio;
    NO* fim;
};

DEQUE* deque_criar() {
    DEQUE* d = (DEQUE*) malloc(sizeof(DEQUE));

    if (d != NULL) {
        d->tamanho = 0;
        d->inicio = NULL;
        d->fim = NULL;
    }

    return(d);
}

void deque_apagar(DEQUE** deque) {
    free(*deque);
    *deque = NULL;
}   

bool deque_inserir_inicio(DEQUE* deque, ITEM* item) {
    if (deque == NULL) {
        return(false);
    }

    /*
    Se vazio, então o novo no é criado e inicio = fim
    Senão:
        Cria um novo no e coloca o valor nele.
        Faz o no apontar para o no do inicio
        Faz inicio apontar para o novo no.
    Aumentar tamanho
    */

    NO* novo = (NO*) malloc(sizeof(NO));
    if (novo == NULL) {
        return(false); //Nao insere nada se o no for NULL
    }

    novo->valor = item;
    novo->prox = NULL;

    if (deque->tamanho == 0) {
        deque->inicio = novo;
        deque->fim = novo;
    } else {
        novo->prox = deque->inicio;
        deque->inicio = novo;
    }

    deque->tamanho++;
}

bool deque_inserir_fim(DEQUE* deque, ITEM* item) {
    if (deque == NULL) {
        return(false);
    }

     /*
    Se vazio, então o novo no é criado e inicio = fim
    Senão:
        Cria um novo no e coloca o valor nele.
        Faz o fim->proximo apontar para o novo no.
        Faz deque->fim = no
    Aumentar tamanho
    */

    novo->valor = item;
    novo->prox = NULL;

    NO* novo = (NO*) malloc(sizeof(NO));
    if (novo == NULL) {
        return(false); //Nao insere nada se o no for NULL
    }

    if (deque->tamanho == 0) {
        deque->inicio = novo;
        deque->fim = novo;
    } else {
        deque->fim->prox = novo;
        deque->fim = novo;
    }

    deque->tamanho++;
}

ITEM* deque_remover_inicio(DEQUE* deque) {
    if (deque == NULL) {
        return(NULL);
    }
}

ITEM* deque_remover_fim(DEQUE* deque) {
    if (deque == NULL) {
        return(NULL);
    }
}

ITEM* deque_primeiro(DEQUE* deque) {
     if (deque == NULL) {
        return(NULL);
    }

    return(deque->inicio->valor);
}

ITEM* deque_ultimo(DEQUE* deque) {
    if (deque == NULL) {
        return(NULL);
    }

    return(deque->fim->valor);
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

/*
Na implementação dinâmica, o limite é a memória.
Para saber se está cheia, um ponteiro NO é alocado.
Se o ponteiro for alocado corretamente, então não está cheia.
Senão, está cheia.
*/
bool deque_cheia(DEQUE* deque) {
    if (deque == NULL) {
        return(true);
    }

    NO* aux = (NO*) malloc(sizeof(NO));

    if (aux == NULL) {
        return(true);
    }

    free(aux);
    return(false);
}