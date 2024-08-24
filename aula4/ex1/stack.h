#ifndef STACK_H
    #define STACK_H
    #define MAX_SIZE 100

    #include "item.h"
    #include <stdbool.h>

    typedef struct stack STACK;

    STACK *stack_create();
    void stack_destroy(STACK **stack);

    bool stack_is_empty(STACK *stack);
    bool stack_is_full(STACK *stack);
    int stack_size(STACK *stack);

    void stack_push(STACK *stack, ITEM *item);
    ITEM *stack_pop(STACK *stack);
    ITEM *stack_peek(STACK *stack);

    void stack_print(STACK *stack);
    void*stack_reverse(STACK *stack);
#endif

