#include <stdlib.h>
#include <stdio.h>

#include "item.h"

struct item {
    int key;
    void *value;
};

void *_allocate(int items, unsigned long int size) {
    void *mem;

    if ((mem = malloc(items * size)) == NULL) {
        fprintf(stderr, "ERROR: Not enough memory to allocate!\n");
        exit(EXIT_FAILURE);
    }

    return(mem);
}

ITEM *item_create(int key, void *value) {
    ITEM *item = (ITEM *) _allocate(1, sizeof(ITEM));

    item->key = key;
    item->value = value;

    return(item);
}

void item_destroy(ITEM **item) {
    if (*item != NULL) {
        free(*item);
        *item = NULL;
    }
}

int item_get_key(ITEM *item) {
    return(item->key);
}

void item_set_key(ITEM *item, int key) {
    item->key = key;
}

void *item_get_value(ITEM *item) {
    return(item->value);
}

void item_set_value(ITEM *item, *void value) {
    item->value = value;
}