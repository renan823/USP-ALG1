#include "item.h"
#include "lista.h"

#include <stdbool.h>

int main(void) {
    LISTA* lista = lista_criar(true); //ordenada

    char c1 = 'c';
    char c2 = 'r';
    char c3 = 'a';
    char c4 = 'o';
    char c5 = 'r';

    lista_inserir(lista, item_criar(1, &c1));
    lista_inserir(lista, item_criar(2, &c3));
    lista_inserir(lista, item_criar(3, &c2));
    lista_inserir(lista, item_criar(4, &c5));
    lista_inserir(lista, item_criar(5, &c4));

    lista_imprimir(lista);

    ITEM* item = lista_remover(lista, 4);
    item_apagar(&item);

    lista_imprimir(lista);

    lista_apagar(&lista);

    return(0);
}