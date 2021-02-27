#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SQUEUE_MAX_SIZE 50

// Statically Allocated Queue
typedef struct squeue {
    void *arr[SQUEUE_MAX_SIZE];
    int size;
    int front; // Index of the front of the queue
    int back; // Index of the empty cell after the back of the queue
} squeue;

void squeue_init(squeue *queue);

bool squeue_empty(squeue *queue);

bool squeue_full(squeue *queue);

void squeue_enqueue(squeue *queue, void *data);

void *squeue_dequeue(squeue *queue);

void *squeue_peek(squeue *queue);

void squeue_clear(squeue *queue, void (*fr)(void *));

void squeue_print(squeue *queue, void (*prn)(void *));
