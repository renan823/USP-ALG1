#include "racional.h"

#include <stdlib.h>
#include <stdio.h>

struct racional {
    int num, den;
};

void *_allocate(int items, unsigned long int size) {
    void *memory;

    if ((memory = malloc(items * size)) == NULL) {
        printf("ERRO: sem memoria para alocar!\n");
        exit(1);
    }

    return(memory);
}

Racional *criar(int num, int den) {
    if (den == 0) {
        printf("ERRO: denominador deve ser diferente de zero!\n");
        exit(1);
    }

    Racional *rac = (Racional *) _allocate(1, sizeof(Racional));
    rac->num = num;
    rac->den = den;

    return(rac);
}

void apagar(Racional *rac) {
    free(rac);
}

Racional *somar(Racional *r1, Racional *r2) {
    Racional *rac = criar(1, 1);

    //dividir mmc pelo denominador, multiplicar o resultado pelo numerador
    int mmc;
    if (r1->den == r2->den) {
        mmc = r1->den;
    } else {
        mmc = (r1->den * r2->den);
    }
    int soma = ((mmc / r1->den) * r1->num) + ((mmc / r2->den) * r2->num);

    rac->num = soma;
    rac->den = mmc;

    return(rac);
}

Racional *multiplicar(Racional *r1, Racional *r2) {
    Racional *rac = criar(1, 1);
    rac->num = (r1->num * r2->num);
    rac->den = (r1->den * r2->den);

    return(rac);
}

void exibir(Racional *rac) {
    printf("%d/%d\n", rac->num, rac->den);
}