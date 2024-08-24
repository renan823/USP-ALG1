#include "ponto.h"
#include "circulo.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct circulo_ {
    PONTO *centro;
    float raio;
};

CIRCULO *circulo_criar(PONTO *p, float raio) {
    CIRCULO *c = (CIRCULO *) malloc(1 * sizeof(CIRCULO));

    if (c == NULL) {
        printf("ERRO!\n");
        exit(1);
    }

    c->centro = p;
    c->raio = raio;

    return(c);
}
void circulo_apagar (CIRCULO **circulo) {
    ponto_apagar(&((*circulo)->centro));

    free(*circulo);
}

bool circulo_set_ponto (CIRCULO *c, PONTO *p) {
    c->centro = p;

    return(true);
}

bool circulo_set_raio (CIRCULO *c, float raio) {
    c->raio = raio;

    return(true);
}

PONTO *circulo_get_ponto (CIRCULO *c) {
    return(c->centro);
}

float circulo_get_raio (CIRCULO *c) {
    return(c->raio);
}