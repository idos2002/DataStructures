#pragma once

#include <stdio.h>
#include <stdlib.h>

// Linear Singly Linked List Node
typedef struct llnode {
    void *data;
    struct llnode *next;
} llnode;

void ll_init(llnode **head);

void ll_push(llnode **head, void *data);

void *ll_pop(llnode **head);

void ll_insert_after(llnode *node, void *data);

void *ll_remove_after(llnode *node);

/// <summary>
/// Clears the linked list and sets head to NULL.
/// </summary>
/// <param name="head">Head of the linked list.</param>
/// <param name="fr">Pointer to a function to free data of the list's nodes. May pass NULL if not needed.</param>
void ll_clear(llnode **head, void (*fr)(void *));

void ll_print(llnode *head, void (*prn)(void *));
