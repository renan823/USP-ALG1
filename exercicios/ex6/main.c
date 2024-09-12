#include "fila.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILA* fila = fila_criar();

    int n;
    scanf("%d", &n);

    int *numeros = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
        fila_inserir(fila, item_criar(i, &numeros[i]));
    }

    fila_apagar(&fila);

    free(numeros);

    return(0);
}