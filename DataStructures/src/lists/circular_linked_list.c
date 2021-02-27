#include "circular_linked_list.h"

void cl_init(clnode **node)
{
    *node = NULL;
}

void cl_insert_last(clnode **last, void *data)
{
    clnode *temp = malloc(sizeof(clnode));
    temp->data = data;

    if (*last) {
        temp->next = (*last)->next;
        (*last)->next = temp;
    } else {
        temp->next = temp;
    }

    *last = temp;
}

void *cl_remove_last(clnode **last)
{
    void *data = (*last)->data;
    clnode *ptr = *last;

    while (ptr->next != *last)
        ptr = ptr->next;

    ptr->next = (*last)->next;
    free(*last);

    if (*last == ptr)
        *last = NULL;
    else
        *last = ptr;

    return data;
}

void cl_insert_after(clnode *node, void *data)
{
    clnode *temp = malloc(sizeof(clnode));
    temp->data = data;
    temp->next = node->next;
    node->next = temp;
}

void *cl_remove_after(clnode **node)
{
    void *data = (*node)->next->data;
    clnode *temp = (*node)->next;

    if (*node == temp)
        return cl_remove_last(node);

    (*node)->next = temp->next;
    free(temp);

    return data;
}

void cl_clear(clnode **last, void(*fr)(void *))
{
    clnode *temp = (*last)->next;

    while (temp != *last) {
        (*last)->next = temp->next;

        if (fr)
            fr(temp->data);
        free(temp);

        temp = (*last)->next;
    }

    if (fr)
        fr(temp->data);
    free(temp);

    *last = NULL;
}

void cl_print(clnode *last, void(*prn)(void *))
{
    if (last) {
        clnode *ptr = last->next;

        while (ptr != last) {
            if (prn)
                prn(ptr->data);

            ptr = ptr->next;
        }

        if (prn)
            prn(ptr->data);
    }

    puts("");
}
