#include "ponto.h"
#include "circulo.h"

#include <stdio.h>

int main(void) {
    float ptx, pty, cx, cy, cr;

    scanf("%f %f %f %f %f", &ptx, &pty, &cx, &cy, &cr);

    PONTO *p = ponto_criar(ptx, pty);
    CIRCULO *c = circulo_criar(ponto_criar(cx, cy), cr);

    ponto_print(p);

    PONTO *cp = circulo_get_ponto(c);
    printf("Circulo: Centro (%.1f, %.1f), Raio = %.1f\n", ponto_get_x(cp), ponto_get_y(cp), circulo_get_raio(c));

    ponto_apagar(&p);
    circulo_apagar(&c);

    return(0);
}