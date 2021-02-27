#pragma once

#include <stdio.h>

#include "stacks/dynamic_stack.h"
#include "stacks/static_stack.h"

void stack_print_int(void *ptr)
{
    printf("%d ", *(int *)ptr);
}

void dstack_test()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    dstack stack;
    dstack_init(&stack);

    dstack_push(&stack, arr);
    dstack_push(&stack, arr + 1);
    dstack_push(&stack, arr + 2);

    dstack_print(&stack, stack_print_int);

    printf("Popped: %d\n", *(int *)dstack_pop(&stack));
    printf("Peeked: %d\n", *(int *)dstack_peek(&stack));

    dstack_print(&stack, stack_print_int);

    dstack_clear(&stack, NULL);

    dstack_print(&stack, stack_print_int);
}

void sstack_test()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    sstack stack;
    sstack_init(&stack);

    sstack_push(&stack, arr);
    sstack_push(&stack, arr + 1);
    sstack_push(&stack, arr + 2);

    sstack_print(&stack, stack_print_int);

    printf("Popped: %d\n", *(int *)sstack_pop(&stack));
    printf("Peeked: %d\n", *(int *)sstack_peek(&stack));

    sstack_print(&stack, stack_print_int);

    sstack_clear(&stack, NULL);

    sstack_print(&stack, stack_print_int);
}
