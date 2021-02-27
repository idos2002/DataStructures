#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Dynamically Allocated Stack
typedef struct dstack {
    void **arr; // Dynamically allocated data array
    int size;
} dstack;

void dstack_init(dstack *stack);

bool dstack_empty(dstack *stack);

void dstack_push(dstack *stack, void *data);

void *dstack_pop(dstack *stack);

void *dstack_peek(dstack *stack);

void dstack_clear(dstack *stack, void (*fr)(void *));

void dstack_print(dstack *stack, void (*prn)(void *));
