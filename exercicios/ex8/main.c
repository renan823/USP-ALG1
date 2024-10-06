#include "item.h"
#include "lista.h"

#include <stdbool.h>

int main(void) {
    LISTA* lista = lista_criar(true); 

    int i1 = 2;
    int i2 = 3;
    int i3 = 5;

    int j1 = 1;
    int j2 = 4;

    lista_inserir(lista, item_criar(2, &i1));
    lista_inserir(lista, item_criar(3, &i2));
    lista_inserir(lista, item_criar(4, &j2));
    lista_inserir(lista, item_criar(5, &i3));
    lista_inserir(lista, item_criar(1, &j1));

    lista_imprimir(lista);

    lista_inverter(lista);

    lista_imprimir(lista);

    lista_apagar(&lista);

    return(0);
}