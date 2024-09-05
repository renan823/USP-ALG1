#include "item.h"
#include "Deque.h"

int main(void) {
    DEQUE* d = deque_criar();

    deque_apagar(&d);

    return(0);
}