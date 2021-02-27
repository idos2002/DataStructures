#include "linear_linked_list.h"

void ll_init(llnode **head)
{
    *head = NULL;
}

void ll_push(llnode **head, void *data)
{
    llnode *temp = malloc(sizeof(llnode));
    temp->data = data;

    temp->next = *head;
    *head = temp;
}

void *ll_pop(llnode **head)
{
    llnode *temp = *head;
    void *data = temp->data;

    *head = temp->next;
    free(temp);

    return data;
}

void ll_insert_after(llnode *node, void *data)
{
    llnode *temp = malloc(sizeof(llnode));
    temp->data = data;

    temp->next = node->next;
    node->next = temp;
}

void *ll_remove_after(llnode *node)
{
    llnode *temp = node->next;
    void *data = temp->data;

    node->next = temp->next;
    free(temp);

    return data;
}

void ll_clear(llnode **head, void (*fr)(void *))
{
    llnode *temp = *head;

    while (*head) {
        *head = temp->next;

        if (fr)
            fr(temp->data);
        free(temp);

        temp = *head;
    }
}

void ll_print(llnode *head, void(*prn)(void *))
{
    while (head) {
        prn(head->data);
        head = head->next;
    }
    puts("");
}
