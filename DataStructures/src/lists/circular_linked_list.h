#pragma once

#include <stdio.h>
#include <stdlib.h>

// Circular Singly Linked List Node
typedef struct clnode {
    void *data;
    struct clnode *next;
} clnode;

void cl_init(clnode **first);

void cl_insert_last(clnode **last, void *data);

void *cl_remove_last(clnode **last);

void cl_insert_after(clnode *node, void *data);

void *cl_remove_after(clnode **node);

void cl_clear(clnode **last, void (*fr)(void *));

void cl_print(clnode *last, void (*prn)(void *));
