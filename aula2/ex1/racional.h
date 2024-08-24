#ifndef RACIONAL_H
    #define RACIONAL_H

    typedef struct racional Racional;

    Racional *criar(int num, int den);
    void apagar(Racional *racional);

    Racional *somar(Racional *r1, Racional *r2);
    Racional *multiplicar(Racional *r1, Racional *r2);

    void exibir(Racional *racional);
#endif