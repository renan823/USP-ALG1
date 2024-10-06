#include "item.h"
#include "lista.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct lista_{ 
    ITEM *lista[TAM_MAX];
    int inicio; 
    int fim;
    int tamanho;
};

LISTA* lista_criar() {
    LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
    
    if (lista != NULL) {
        lista->tamanho = 0;
        lista->inicio = 0;
        lista->fim = 0;
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

void _inserir_posicao(LISTA* lista, ITEM* item, int pos) {
    for (int i = lista->tamanho; i > pos; i--) {
        lista->lista[i] = lista->lista[i-1]; //pega o anterior e "puxa"
    }

    lista->lista[pos] = item;
    lista->fim = lista->tamanho;
    lista->tamanho++;
}

bool lista_inserir(LISTA* lista, ITEM* item) {
    /*
    Deve achar a posição certa pra inserir.
    Se lista->tamanho = 0, inserir no fim.
    Senão, busque na lista até achar o primeiro elemento
    maior que a chave do item.
    Insira na posição.
    */

    if (lista->tamanho == 0) {
        lista->lista[0] = item;
        lista->fim = lista->tamanho;
        lista->tamanho++;

        return(true);
    }

    for (int i = lista->inicio; i < lista->tamanho; i++) {
        if (item_get_chave(lista->lista[i]) > item_get_chave(item)) {
            _inserir_posicao(lista, item, i); //i = pos
            return(true);
        }
    }
}

bool lista_cheia(LISTA* lista) {
    if (lista == NULL) {
        return(true);
    }

    return(lista->tamanho == TAM_MAX);
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

void lista_imprimir(LISTA* lista) {
    if (lista_vazia(lista)) {
        return;
    }

    for (int i = 0; i < lista->tamanho; i++) {
        printf("[%d]; ", item_get_chave(lista->lista[i]));
    }
    printf("\n");
}

