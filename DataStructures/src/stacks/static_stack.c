#include "static_stack.h"

void sstack_init(sstack *stack)
{
    stack->size = 0;
}

bool sstack_empty(sstack *stack)
{
    return stack->size == 0;
}

bool sstack_full(sstack *stack)
{
    return stack->size == SSTACK_MAX_SIZE;
}

void sstack_push(sstack *stack, void *data)
{
    if (!sstack_full(stack)) {
        stack->arr[stack->size] = data;
        stack->size++;
    }
}

void *sstack_pop(sstack *stack)
{
    if (!sstack_empty(stack)) {
        void *data = stack->arr[stack->size - 1];
        stack->size--;
        return data;
    }

    return NULL;
}

void *sstack_peek(sstack *stack)
{
    if (!sstack_empty(stack))
        return stack->arr[stack->size - 1];

    return NULL;
}

void sstack_clear(sstack *stack, void(*fr)(void *))
{
    while (stack->size) {
        stack->size--;
        if (fr)
            fr(stack->arr[stack->size]);
    }
}

void sstack_print(sstack *stack, void(*prn)(void *))
{
    int i;
    for (i = stack->size - 1; i >= 0; i--)
        prn(stack->arr[i]);
    puts("");
}
