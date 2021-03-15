#pragma once

#include <stdbool.h>
#include <stdlib.h>

// AVL Tree Node
typedef struct avlnode {
    void *data;
    int height;
    struct avlnode *left;
    struct avlnode *right;
} avlnode;

void avl_init(avlnode **root);

int avl_height(avlnode *root);

void avl_insert(avlnode **root, void *data, int (*cmp)(void *, void *));

// bool avl_remove(avlnode **root, void *data, int (*cmp)(void *, void *));

void avl_print_preorder(avlnode *root, void (*prn)(void *));
void avl_print_inorder(avlnode *root, void (*prn)(void *));
void avl_print_postorder(avlnode *root, void (*prn)(void *));

void avl_clear(avlnode **root, void (*fr)(void *));
