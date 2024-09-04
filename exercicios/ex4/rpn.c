#include "item.h"
#include "pilha.h"

#include <stdlib.h>

float itemParaFloat(ITEM* item) {
    float* f = item_get_dados(item);
    item_apagar(&item);

    return(*f); 
}

float rpn(char *sequencia) {
    /*
    verifica se é uma operação (switch)
    se for numero:
        colocar na pilha (usar atof)
    se for operação:
        remove o topo (salva)
        remove o topo novamente (salva)
        opera com as duas variaveis (operador recebido)
        empilha resultado
    ler os casos até acabar a strin (\0)
    a pilha deve ter um unico elemento no final

    o vetor valores é usado para armazenar os inseridos/já operados
    na sub e multi, o v2 antece o v1 (v2 foi inserido antes na pilha, por isso precede)
    */

    PILHA* p = pilha_criar();

    int i = 0;
    char c = sequencia[i];

    float valores[100];

    while(c != '\0') {
        switch(c) {
            case '+':
                valores[i] = itemParaFloat(pilha_desempilhar(p));
                valores[i] += itemParaFloat(pilha_desempilhar(p));

                pilha_empilhar(p, item_criar(i, &valores[i]));
                break;
            case '-':
                //para manter a ordem v2 - v1, inverter ambos
                valores[i] = itemParaFloat(pilha_desempilhar(p)) * -1;
                valores[i] -= (itemParaFloat(pilha_desempilhar(p)) * -1);

                pilha_empilhar(p, item_criar(i, &valores[i]));
                break;
            case '*':
                valores[i] = itemParaFloat(pilha_desempilhar(p));
                valores[i] *= itemParaFloat(pilha_desempilhar(p));

                pilha_empilhar(p, item_criar(i, &valores[i]));
                break;
            case '/':
                //para manter a ordem v2 / v1, salva o topo no i+1 depois divide
                valores[i+1] = itemParaFloat(pilha_desempilhar(p));
                valores[i] = itemParaFloat(pilha_desempilhar(p)) / valores[i+1];

                pilha_empilhar(p, item_criar(i, &valores[i]));
                break;
            default:
                //converter char para float e empilhar
                valores[i] = atof(&c);
                pilha_empilhar(p, item_criar(i, &valores[i]));
        }

        i++;
        c = sequencia[i];
    }

    float final = itemParaFloat(pilha_desempilhar(p));
    pilha_apagar(&p);

    return(final);
}
