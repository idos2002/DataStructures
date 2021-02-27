#pragma once

#include <stdio.h>

#include "queues/dynamic_queue.h"
#include "queues/static_queue.h"

void queue_print_int(void *ptr)
{
    printf("%d ", *(int *)ptr);
}

void dqueue_test()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    dqueue queue;
    dqueue_init(&queue);

    dqueue_enqueue(&queue, arr);
    dqueue_enqueue(&queue, arr + 1);
    dqueue_enqueue(&queue, arr + 2);

    dqueue_print(&queue, queue_print_int);

    printf("Dequeued: %d\n", *(int *)dqueue_dequeue(&queue));
    printf("Peeked: %d\n", *(int *)dqueue_peek(&queue));

    dqueue_print(&queue, queue_print_int);

    dqueue_clear(&queue, NULL);

    dqueue_print(&queue, queue_print_int);
}

void squeue_test()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    squeue queue;
    squeue_init(&queue);

    squeue_enqueue(&queue, arr);
    squeue_enqueue(&queue, arr + 1);
    squeue_enqueue(&queue, arr + 2);

    squeue_print(&queue, queue_print_int);

    printf("Dequeued: %d\n", *(int *)squeue_dequeue(&queue));
    printf("Peeked: %d\n", *(int *)squeue_peek(&queue));

    squeue_print(&queue, queue_print_int);

    squeue_clear(&queue, NULL);

    squeue_print(&queue, queue_print_int);
}

