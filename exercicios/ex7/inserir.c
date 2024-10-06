#include "item.h"
#include "lista.h"

#include <stdbool.h>
#include <stdio.h>

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