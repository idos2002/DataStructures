#include "max_heap.h"

#define parent_index(index) (((index) - 1) / 2)
#define left_child_index(index) (2 * (index) + 1)
#define right_child_index(index) (2 * (index) + 2)

static bool has_parent(maxheap *heap, int index) { return parent_index(index) >= 0; }
static bool has_left_child(maxheap *heap, int index) { return left_child_index(index) < heap->size; }
static bool has_right_child(maxheap *heap, int index) { return right_child_index(index) < heap->size; }

static void *parent(maxheap *heap, int index) { return heap->arr[parent_index(index)]; }
static void *left_child(maxheap *heap, int index) { return heap->arr[left_child_index(index)]; }
static void *right_child(maxheap *heap, int index) { return heap->arr[right_child_index(index)]; }

static void swap(maxheap *heap, int i, int j)
{
    void *temp = heap->arr[i];
    heap->arr[i] = heap->arr[j];
    heap->arr[j] = temp;
}

void maxheap_init(maxheap *heap)
{
    heap->arr = NULL;
    heap->size = 0;
}

bool maxheap_empty(maxheap *heap)
{
    return heap->size == 0;
}

void *maxheap_peek(maxheap *heap)
{
    if (maxheap_empty(heap))
        return NULL;

    return heap->arr[0];
}

static void heapify_up(maxheap *heap, int (*cmp)(void *, void *))
{
    int index = heap->size - 1;

    while (has_parent(heap, index) &&
        cmp(heap->arr[index], parent(heap, index)) > 0) {

        swap(heap, index, parent_index(index));
        index = parent_index(index);
    }
}

void maxheap_push(maxheap *heap, void *data, int (*cmp)(void *, void *))
{
    heap->arr = realloc(heap->arr, (heap->size + 1) * sizeof(void *));
    heap->arr[heap->size] = data;
    heap->size++;
    heapify_up(heap, cmp);
}

static void heapify_down(maxheap *heap, int (*cmp)(void *, void *))
{
    int index = 0, maxChildIndex;

    while (has_left_child(heap, index)) {
        maxChildIndex = left_child_index(index);

        if (has_right_child(heap, index) &&
            cmp(right_child(heap, index), left_child(heap, index)) > 0) {

            maxChildIndex = right_child_index(index);
        }

        if (cmp(heap->arr[index], heap->arr[maxChildIndex]) > 0)
            break;
        else
            swap(heap, index, maxChildIndex);

        index = maxChildIndex;
    }
}

void *maxheap_pop(maxheap *heap, int (*cmp)(void *, void *))
{
    void *data;
    if (maxheap_empty(heap))
        return NULL;

    data = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->arr = realloc(heap->arr, (heap->size - 1) * sizeof(void *));
    heap->size--;

    heapify_down(heap, cmp);

    return data;
}

void maxheap_clear(maxheap *heap, void (*fr)(void *))
{
    int i;
    if (fr)
        for (i = 0; i < heap->size; i++)
            fr(heap->arr[i]);

    free(heap->arr);
    maxheap_init(heap);
}

#undef parent_index
#undef left_child_index
#undef right_child_index