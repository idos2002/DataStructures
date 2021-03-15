#pragma once

#include <stdbool.h>
#include <stdlib.h>

// Dynamically Allocated Min Heap
typedef struct minheap {
    void **arr;
    int size;
} minheap;

void minheap_init(minheap *heap);

bool minheap_empty(minheap *heap);

void *minheap_peek(minheap *heap);

void minheap_push(minheap *heap, void *data, int (*cmp)(void *, void *));

void *minheap_pop(minheap *heap, int (*cmp)(void *, void *));

void minheap_clear(minheap *heap, void (*fr)(void *));
