#pragma once

#include <stdio.h>

#include <lists/circular_linked_list.h>
#include <lists/linear_linked_list.h>

void list_print_int(void *ptr)
{
    printf("%d -> ", *(int *)ptr);
}

void ll_test()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    llnode *list;
    ll_init(&list);

    ll_push(&list, arr);
    ll_push(&list, arr + 1);
    ll_push(&list, arr + 2);
    ll_print(list, list_print_int);

    ll_insert_after(list, arr + 3);
    ll_print(list, list_print_int);

    printf("Popped: %d\n", *(int *)ll_pop(&list));
    ll_print(list, list_print_int);

    ll_clear(&list, NULL);
    ll_print(list, list_print_int);
}

void cl_test()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    clnode *last;
    cl_init(&last);

    cl_insert_last(&last, arr);
    cl_insert_last(&last, arr + 1);
    cl_insert_last(&last, arr + 2);
    cl_print(last, list_print_int);

    cl_insert_after(last, arr + 3);
    cl_print(last, list_print_int);

    printf("Removed: %d\n", *(int *)cl_remove_after(&last->next));
    cl_print(last, list_print_int);

    printf("Removed: %d\n", *(int *)cl_remove_last(&last));
    cl_print(last, list_print_int);

    cl_clear(&last, NULL);
    cl_print(last, list_print_int);
}
