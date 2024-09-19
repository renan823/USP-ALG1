#include "item.h"
#include "lista.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct lista_ {
    int tamanho;
    bool ordenada;
    ITEM* items[MAX];
};

//Utilidades

/*
Busca binária com modificação para a inserção.
Se o modo inserir é false, então a busca binária funciona normalmente
Se o modo inserir é true, então ao achar um valor maior que a chave, retorne-o
*/
int _busca_binaria(LISTA* lista, int chave, bool inserir) {
    if (lista->tamanho == 0) {
        return(0);
    }

    int inicio = 0;
    int fim = lista->tamanho-1;
    int meio = (inicio + fim) / 2;

    while (inicio != fim) {
        if (item_get_chave(lista->items[meio]) == chave) {
            return(meio);
        }

        if (item_get_chave(lista->items[meio]) > chave) {
            if (inserir) {
                return(meio);
            }

            fim = meio - 1;
            meio = (inicio + fim) / 2;
        } else {
            inicio = meio + 1;
            meio = (inicio + fim) / 2;
        }
    }

    return(-1);
}

int _busca_sequencial(LISTA* lista, int chave) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (item_get_chave(lista->items[i]) == chave) {
            return(i);
        }
    }

    return(-1);
}

bool _inserir_posicao(LISTA* lista, int pos, ITEM* item) {
    for (int i = lista->tamanho; i > pos; i--) {
        lista->items[i+1] = lista->items[i];
    }

    lista->items[pos] = item;
    lista->tamanho++;

    return(true);
}

ITEM* _remover_posicao(LISTA* lista, int pos) {
    ITEM* item = lista->items[pos];
    lista->tamanho--;

    for (int i = pos; i < lista->tamanho; i++) {
        lista->items[i] = lista->items[i+1];
    }

    return(item);
}


LISTA* lista_criar(bool ordenada) {
    LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
    
    if (lista != NULL) {
        lista->tamanho = 0;
        lista->ordenada = ordenada;
    }

    return(lista);
}

void lista_apagar(LISTA** lista) {
    if (*lista == NULL) {
        return;
    }

    free(*lista);
    *lista = NULL;
}

bool lista_inserir(LISTA* lista, ITEM* item) {
    if (lista_cheia(lista)) {
        return(false);
    }

    int pos = -1;

    if (lista->ordenada) {
        pos = _busca_binaria(lista, item_get_chave(item), true); //modo de inserir
    }

    if (pos != -1) {
        return(_inserir_posicao(lista, pos, item));
    }

    lista->items[lista->tamanho] = item;
    lista->tamanho++;

    return(true);
}

ITEM* lista_remover(LISTA* lista, int chave) {
    int pos = -1;

    if (!lista->ordenada) {
        pos = _busca_sequencial(lista, chave);
    } else {
        pos = _busca_binaria(lista, chave, false);
    }

    if (pos == -1) {
        return(NULL);
    }

    return(_remover_posicao(lista, pos));
}

bool lista_cheia(LISTA* lista) {
    if (lista == NULL) {
        return(true);
    }

    return(lista->tamanho == MAX);
}

bool lista_vazia(LISTA* lista) {
    if (lista == NULL) {
        return(false);
    }

    return(lista->tamanho == 0);
}

int lista_tamanho(LISTA* lista) {
    if (lista == NULL) {
        return(-1);
    }

    return(lista->tamanho);
}

void lista_print(LISTA* lista) {
    if (lista_vazia(lista)) {
        return;
    }

    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d\n", item_get_chave(lista->items[i]));
    }
}

