#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dynamically Allocated Queue
typedef struct dqueue {
    void **arr;
    int size;
} dqueue;

void dqueue_init(dqueue *queue);

bool dqueue_empty(dqueue *queue);

void dqueue_enqueue(dqueue *queue, void *data);

void *dqueue_dequeue(dqueue *queue);

void *dqueue_peek(dqueue *queue);

void dqueue_clear(dqueue *queue, void (*fr)(void *));

void dqueue_print(dqueue *queue, void (*prn)(void *));
