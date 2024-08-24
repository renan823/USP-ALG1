#include "item.h"
#include "pilha.h"

#include <stdio.h>

int main(void) {
    int n;
    char seq[1000];

    scanf("%d", &n);

    while(n > 0) {
        scanf("%s", &seq);
        if (balanceada(seq)) {
            printf("BALANCEADO\n");
        } else {
            printf("NÃO BALANCEADO\n");
        }
        n--;
    }

    return(0);
}