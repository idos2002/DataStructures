#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SSTACK_MAX_SIZE 50

// Statically Allocated Stack
typedef struct sstack {
    void *arr[SSTACK_MAX_SIZE];
    int size;
} sstack;

void sstack_init(sstack *stack);

bool sstack_empty(sstack *stack);

bool sstack_full(sstack *stack);

void sstack_push(sstack *stack, void *data);

void *sstack_pop(sstack *stack);

void *sstack_peek(sstack *stack);

void sstack_clear(sstack *stack, void (*fr)(void *));

void sstack_print(sstack *stack, void (*prn)(void *));
