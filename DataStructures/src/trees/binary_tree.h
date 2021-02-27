#pragma once

#include <stdbool.h>
#include <stdlib.h>

// Binary Search Tree Node (No Duplicates)
typedef struct btnode {
    void *data;
    struct btnode *left;
    struct btnode *right;
} btnode;

void bt_init(btnode **root);

bool bt_insert(btnode **root, void *data, int (*cmp)(void *, void *));

bool bt_leaf(btnode *node);

void *bt_remove(btnode **root, void *data, int (*cmp)(void *, void *));

void bt_print_preorder(btnode *root, void (*prn)(void *));
void bt_print_inorder(btnode *root, void (*prn)(void *));
void bt_print_postorder(btnode *root, void (*prn)(void *));

void bt_clear(btnode **root, void (*fr)(void *));
