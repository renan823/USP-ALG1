#include "item.h"
#include "Pilha.h"

#include <stdio.h>

int main(void) {
    char sequencia[101];

    while(1) {
        scanf("%s", &sequencia);

        if (sequencia[0] == EOF) {
            break;
        }

        printf("%.2f\n", rpn(sequencia));
    }

    return(0);
}