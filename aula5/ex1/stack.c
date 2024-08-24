#include "item.h"
#include "stack.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct stack {
    NODE *top;
    int size;
};

struct node {
    ITEM *item;
    NODE *next;
};

void *_allocate(int items, unsigned long size) {
    void *mem = malloc(items * size);

    return(mem);
}

STACK *stack_create() {
    STACK *s = (STACK *) _allocate(1, sizeof(STACK));

    if (s == NULL) {
        return(s);
    }

    s->top = NULL;
    s->size = 0;

    return(s);
}

void stack_destroy(STACK **stack) {
    if (stack == NULL || *stack == NULL) {
        return;
    }

    NODE *node;

    while ((*stack)->top != NULL) {
        node = (*stack)->top;
        (*stack)->top = (*stack)->top->next;

        item_destroy(&node->item);
        node->next = NULL;
        free(node);
        node = NULL;
    }

    free(*stack);
    *stack = NULL;

}

bool stack_is_empty(STACK *stack) {
    if (stack == NULL) {
        return(false);
    }

    return(stack->size == 0);
}

bool stack_is_full(STACK *stack) {
    if (stack == NULL) {
        return(true);
    }

    //tenta alocar (a pilha estar cheia depende da capacidade de memoria)
    //o limite é a heap!!
    NODE *node = (NODE *) _allocate(1, sizeof(NODE));
    if (node == NULL) {
        return(true);
    }

    free(node);
    return(false);
}

int stack_size(STACK *stack) {
    if (stack == NULL) {
        return(-1);
    }

    return(stack->size);
}

void stack_push(STACK *stack, ITEM *item) {
    if (stack_is_full(stack)) {
        fprintf(stderr, "ERROR: The stack is full!\n");
        return;
    }

    NODE *new = (NODE *) _allocate(1, sizeof(NODE));
    if (new == NULL) {
        return;
    }

    new->item = item;
    new->next = stack->top;

    stack->top = new;
    stack->size++;
}

ITEM *stack_pop(STACK *stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "ERROR: The stack is empty!\n");
        return(NULL);
    }

    stack->size--;

    //movendo o top
    NODE *old = stack->top;
    stack->top = old->next;
    old->next = NULL;

    //salvar o item e excluir ponteiros
    ITEM *item = old->item;

    free(old);
    old = NULL;

    return(item);
}

ITEM *stack_peek(STACK *stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "ERROR: The stack is empty!\n");
        return(NULL);
    }

    return(stack->top->item);
}

void stack_print(STACK *stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "ERROR: The stack is empty!\n");
        return;
    }

    printf("Stack {\n");
    printf("  - size: %d\n", stack->size);
    printf("  - items (keys): [ ");
    
    NODE *next = stack->top;
    while(next != NULL) {
        if (next != NULL) {
            printf("%d ", item_get_key(next->item));
        }

        next = stack->top->next;
    }

    free(next);

    printf("]\n");
    printf("}\n");
}

void stack_reverse(STACK *stack) {
    if (stack == NULL) {
        return;
    }
}
