#include "ponto.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

/*
É mais intuitivo pensar que a responsibilidade de calcular a distância seja do TAD ponto.
Afinal, estamos calculado a distância entre dois pontos.
O TAD circulo apenas faz uso do ponto, sem acesso direto aos dados.
Implementando a função no TAD ponto, podemos acessar diretamente os dados que precisamos,
sem utilizar as funções implementadas na interface.
*/
float distancia(PONTO *p1, PONTO *p2) {
    return(sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2)));
}