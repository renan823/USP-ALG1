#include "item.h"
#include "Deque.h"

int main(void) {
    DEQUE* d1 = deque_criar();

    char c1 = 'a';
    char c2 = 'b';
    char c3 = 'c';
    char c4 = 'd';
   
    deque_inserir_inicio(d1, item_criar(1, &c1));
    deque_inserir_fim(d1, item_criar(2, &c2));
    deque_inserir_fim(d1, item_criar(3, &c3));
    deque_inserir_inicio(d1, item_criar(4, &c4));

    deque_print(d1);

    deque_apagar(&d1);

    return(0);
}