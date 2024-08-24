#include "item.h"
#include "stack.h"

#include <stdio.h>

int main(void) {
    STACK *s = stack_create();

    printf("empty? %s\n", stack_is_empty(s) ? "Yes" : "No");
    printf("full? %s\n", stack_is_full(s) ? "Yes" : "No");

    char *value = "Message!";
    ITEM *i = item_create(1, value);

    stack_push(s, i);

    printf("size: %d\n", stack_size(s));

    ITEM *it = stack_peek(s);
    if (it != NULL) {
        value = item_get_value(it);
        printf("%s\n", value);
    }

    stack_print(s);
    stack_pop(s);

    stack_destroy(&s);

    return(0);
}