#ifndef DEQUE_H
    #define DEQUE_H

    #include "item.h"
    #include <stdbool.h>

    typedef struct deque_ DEQUE;
    typedef struct no_ NO;

    DEQUE* deque_criar();
    void deque_apagar(DEQUE** deque);

    bool deque_inserir_inicio(DEQUE* deque, ITEM* item);
    bool deque_inserir_fim(DEQUE* deque, ITEM* item);
    ITEM* deque_remover_inicio(DEQUE* deque);
    ITEM* deque_remover_fim(DEQUE* deque);

    ITEM* deque_primeiro(DEQUE* deque);
    ITEM* deque_ultimo(DEQUE* deque);

    int deque_contar(DEQUE* deque);
    bool deque_vazia(DEQUE* deque);
    bool deque_cheia(DEQUE* deque);

    void deque_print(DEQUE* deque);
#endif