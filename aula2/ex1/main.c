#include "racional.h"

int main(void) {
    Racional *r1 = criar(1, 2);
    Racional *r2 = criar(1, 2);
    Racional *r3 = somar(r1, r2);
    Racional *r4 = multiplicar(r1, r2);

    exibir(r1);
    exibir(r2);
    exibir(r3);
    exibir(r4);

    apagar(r1);
    apagar(r2);
    apagar(r3);
    apagar(r4);

    return(0);
}