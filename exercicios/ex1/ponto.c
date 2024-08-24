#include "ponto.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct ponto_ {
    float x;
    float y;
};

PONTO *ponto_criar (float x, float y) {
    PONTO *p = (PONTO *) malloc(1 * sizeof(PONTO));

    if (p == NULL) {
        printf("ERRO!\n");
        exit(1);
    }

    p->x = x;
    p->y = y;

    return(p);
}

void ponto_apagar (PONTO **p) {
    free(*p);
}

bool ponto_set (PONTO *p, float x, float y) {
    p->x = x;
    p->y = y;

    return(true);
}

float ponto_get_x (PONTO *p) {
    return(p->x);
}
float ponto_get_y (PONTO *p) {
    return(p->y);
}

void ponto_print (PONTO *p) {
    printf("Ponto: (%.1f, %.1f)\n", p->x, p->y);
}