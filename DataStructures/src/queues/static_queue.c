#include "static_queue.h"

void squeue_init(squeue *queue)
{
    queue->size = 0;
    queue->front = 0;
    queue->back = 0;
}

bool squeue_empty(squeue *queue)
{
    return queue->size == 0;
}

bool squeue_full(squeue *queue)
{
    return queue->size == SQUEUE_MAX_SIZE;
}

void squeue_enqueue(squeue *queue, void *data)
{
    if (!squeue_full(queue)) {
        queue->arr[queue->back] = data;
        queue->back = (queue->back + 1) % SQUEUE_MAX_SIZE;
        queue->size++;
    }
}

void *squeue_dequeue(squeue *queue)
{
    if (!squeue_empty(queue)) {
        void *data = queue->arr[queue->front];
        queue->front = (queue->front + 1) % SQUEUE_MAX_SIZE;
        queue->size--;
        return data;
    }

    return NULL;
}

void *squeue_peek(squeue *queue)
{
    if (!squeue_empty(queue))
        return queue->arr[queue->front];

    return NULL;
}

void squeue_clear(squeue *queue, void(*fr)(void *))
{
    void *data;

    while (!squeue_empty(queue)) {
        data = squeue_dequeue(queue);

        if (fr)
            fr(data);
    }
}

void squeue_print(squeue *queue, void(*prn)(void *))
{
    int i;

    if (!squeue_empty(queue)) {
        prn(queue->arr[queue->front]);

        for (i = queue->front + 1; i != queue->back; i = (i + 1) % SQUEUE_MAX_SIZE)
            prn(queue->arr[i]);
    }

    puts("");
}
