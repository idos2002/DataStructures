#pragma once

#include <stdbool.h>
#include <stdlib.h>

// Dynamically Allocated Generic Heap
// (min/max determined by comparing function)
typedef struct maxheap {
    void **arr;
    int size;
} maxheap;

void maxheap_init(maxheap *heap);

bool maxheap_empty(maxheap *heap);

void *maxheap_peek(maxheap *heap);

void maxheap_push(maxheap *heap, void *data, int (*cmp)(void *, void *));

void *maxheap_pop(maxheap *heap, int (*cmp)(void *, void *));

void maxheap_clear(maxheap *heap, void (*fr)(void *));
