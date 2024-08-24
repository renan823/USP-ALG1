#include "item.h"
#include "stack.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct stack {
    ITEM *items[MAX_SIZE];
    int size;
};

void *_allocate(int items, unsigned long size) {
    void *mem;

    if ((mem = malloc(item * size)) == NULL) {
        fprintf(stderr, "ERROR: Not enough memory to allocate!\n");
    }

    return(mem);
}

STACK *stack_create() {
    STACK *s = (STACK *) _allocate(1, sizeof(STACK));
    s->size = 0;

    return(s);
}

void stack_destroy(STACK **stack) {
    if (stack == NULL || *stack == NULL) {
        return;
    }
    
    for (int i = 0; i < (*stack)->tamanho; i++) {
        item_destroy(&((*stack)->items[i]));
    }

    free(*pilha);
    *pilha = NULL;
}

bool stack_is_empty(STACK *stack) {
    return(stack->size == 0);
}

bool stack_is_full(STACK *stack) {
    return(stack->size == MAX_SIZE);
}

int stack_size(STACK *stack) {
    return(stack->size);
}

void stack_push(STACK *stack, ITEM *item) {
    if (stack_is_full(stack)) {
        fprintf(stderr, "ERROR: The stack is full!\n");
        return;
    }

    stack->items[stack->size] = item;
    stack->size++;
}

ITEM *stack_pop(STACK *stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "ERROR: The stack is empty!\n");
        return(NULL);
    }

    //precisa "apagar" o ponteiro pra item (usando auxiliar)...
    stack->size--;

    ITEM *item = stack_peek(stack);
    stack->items[stack->size] = NULL;

    return(item);
}

ITEM *stack_peek(STACK *stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "ERROR: The stack is empty!\n");
        return(NULL);
    }

    return(stack->items[stack->size-1]);
}

void stack_print(STACK *stack) {
    printf("Stack {\n");
    printf("  - size: %d\n", stack->size);

    printf("  - items: [ ")
    for(int i = 0; i < stack->size; i++) {
        printf("%d ", item_get_key(stack->items[i]));
    }
    printf("]\n");

    printf("}\n");
}

void _swap(ITEM *a, ITEM *b) {
    ITEM *temp = a;
    a = b;
    b = temp;
}

void stack_reverse(STACK *stack) {
    /*
    percorrer o vetor até a metade (verificar tamanho par/impar)
    se par -> max = size/2
    se impar -> max = (size-1)/2
    swap nos ponteiros (i e p->size-i)
    */
    int max = (stack->size % 2 == 0) ? stack->size / 2 : (stack->size -1) / 2;

    for(int i = 0; i < max; i++) {
        _swap(stack->items[i], stack->items[stack->size-i]);
    }
}

