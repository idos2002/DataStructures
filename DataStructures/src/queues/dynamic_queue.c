#include "dynamic_queue.h"

void dqueue_init(dqueue *queue)
{
    queue->arr = NULL;
    queue->size = 0;
}

bool dqueue_empty(dqueue *queue)
{
    return queue->size == 0;
}

void dqueue_enqueue(dqueue *queue, void *data)
{
    queue->size++;
    queue->arr = realloc(queue->arr, queue->size * sizeof(void *));
    queue->arr[queue->size - 1] = data;
}

void *dqueue_dequeue(dqueue *queue)
{
    if (!dqueue_empty(queue)) {
        void *data = queue->arr[0];
        queue->size--;
        memcpy(queue->arr, queue->arr + 1, queue->size * sizeof(void *));
        queue->arr = realloc(queue->arr, queue->size * sizeof(void *));

        // realloc(ptr, 0) doesn't return NULL on all implementations,
        // therefore we need to assure arr is NULL if the size of the
        // queue is 0
        if (queue->size == 0)
            queue->arr = NULL;

        return data;
    }

    return NULL;
}

void *dqueue_peek(dqueue *queue)
{
    return queue->arr[0];
}

void dqueue_clear(dqueue *queue, void(*fr)(void *))
{
    int i;

    if (fr)
        for (i = 0; i < queue->size; i++)
            fr(queue->arr[i]);

    free(queue->arr);
    queue->size = 0;
}

void dqueue_print(dqueue *queue, void(*prn)(void *))
{
    int i;
    for (i = 0; i < queue->size; i++)
        prn(queue->arr[i]);
    puts("");
}
