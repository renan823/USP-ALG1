#include "item.h"
#include "fila.h"

#include <stdio.h>

int main(void) {
    FILA* fila = fila_criar();
    char a = 'a';
    char b = 'b';
    char c = 'c';

    fila_inserir(fila, item_create(1, &a));
    fila_inserir(fila, item_create(2, &b));

    fila_print(fila);
    
    fila_remover(fila);

    fila_print(fila);

    fila_destruir(&fila);
    return(0);
}