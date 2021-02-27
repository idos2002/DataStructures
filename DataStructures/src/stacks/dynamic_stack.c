#include "dynamic_stack.h"

void dstack_init(dstack *stack)
{
    stack->arr = NULL;
    stack->size = 0;
}

bool dstack_empty(dstack *stack)
{
    return stack->size == 0;
}

void dstack_push(dstack *stack, void *data)
{
    stack->size++;
    stack->arr = realloc(stack->arr, stack->size * sizeof(void *));
    stack->arr[stack->size - 1] = data;
}

void *dstack_pop(dstack *stack)
{
    if (!dstack_empty(stack)) {
        stack->size--;

        void *data = stack->arr[stack->size];
        stack->arr = realloc(stack->arr, stack->size * sizeof(void *));

        return data;
    }

    return NULL;
}

void *dstack_peek(dstack *stack)
{
    if (!dstack_empty(stack))
        return stack->arr[stack->size - 1];

    return NULL;
}

void dstack_clear(dstack *stack, void(*fr)(void *))
{
    int i;

    if (fr)
        for (i = 0; i < stack->size; i++)
            fr(stack->arr[i]);

    free(stack->arr);
    stack->size = 0;
}

void dstack_print(dstack *stack, void(*prn)(void *))
{
    int i;
    for (i = stack->size - 1; i >= 0; i--)
        prn(stack->arr[i]);
    puts("");
}
