#include "pilha.h"
#include "item.h"

#include <stdbool.h>
#include <stdio.h>

char itemParaChar(ITEM *item) {
    char *c = item_get_dados(item);
    return (*c);
}

bool balanceada(char *sequencia) {
    PILHA *p = pilha_criar();

    /*
    se for abertura, só colcocar na pilha
    se for fechamento -> {
        se pilha vazia: não ordenado
        senão: desempilhar e comparar (dependendo da comparação -> não ordenado)
    }
    */

    int i = 0;
    ITEM *topo = NULL;

    while(sequencia[i] != '\0') {
        if (sequencia[i] == '(' || sequencia[i] == '[' || sequencia[i] == '{') {
            pilha_empilhar(p, item_criar(i, &sequencia[i]));
        } else {
            if (pilha_vazia(p)) {
                pilha_apagar(&p);
                return(false);
            }

            topo = pilha_desempilhar(p);
            char c = itemParaChar(topo);
            //printf("%c\n", c);

            if (c == '(' && sequencia[i] != ')') {
                pilha_apagar(&p);
                return(false);
            }

            if (c == '[' && sequencia[i] != ']') {
                pilha_apagar(&p);
                return(false);
            }

            if (c == '{' && sequencia[i] != '}') {
                pilha_apagar(&p);
                return(false);
            }
        }

        i++;
    }

    if (!pilha_vazia(p)) {
        pilha_apagar(&p);
        return(false);
    }

    pilha_apagar(&p);
    return(true);
}
