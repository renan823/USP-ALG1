#include "fila.h"
#include "item.h"

#include <stdio.h>
#include <stdlib.h>

void apagar_no(NO* no) {
    if (no == NULL) {
        return;
    }
 
    apagar_no(no->proximo);
    item_apagar(&no->item);

    free(no);
}

void fila_apagar(FILA** fila) {
    if (*fila == NULL) {
        return;
    }

    /*
    condição de parada: proximo nó é null
    até que o no seja null:
        se o no tem proximo, vai pro proximo
        na volta da recursão, apague o no->item e o no
    */
    apagar_no((*fila)->inicio);

    free(*fila);
    *fila = NULL;
}