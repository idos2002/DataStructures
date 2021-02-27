#include "binary_tree.h"

void bt_init(btnode **root)
{
    *root = NULL;
}

bool bt_insert(btnode **root, void *data, int(*cmp)(void *, void *))
{
    if (*root) {
        int result = cmp(data, (*root)->data);

        if (result > 0)
            return bt_insert(&(*root)->right, data, cmp);
        else if (result < 0)
            return bt_insert(&(*root)->left, data, cmp);
        else
            return false;
    }

    *root = malloc(sizeof(btnode));
    (*root)->data = data;
    (*root)->left = NULL;
    (*root)->right = NULL;

    return true;
}

bool bt_leaf(btnode *node)
{
    return !node->left && !node->right;
}

static void *remove_min_child(btnode **root)
{
    if ((*root)->left)
        return remove_min_child(&(*root)->left);

    void *data = (*root)->data;
    btnode *temp = NULL;

    if ((*root)->right)
        temp = (*root)->right;

    free(*root);
    *root = temp;
    return data;
}

static void *delete_node(btnode **node)
{
    void *data = (*node)->data;
    btnode *temp;

    if (bt_leaf(*node)) {							// is leaf
        free(*node);
        *node = NULL;
    } else if ((*node)->left && !(*node)->right) {	// has left child
        temp = (*node)->left;
        free(*node);
        *node = temp;
    } else if (!(*node)->left && (*node)->right) {	// has right child
        temp = (*node)->right;
        free(*node);
        *node = temp;
    } else {										// has both children
        (*node)->data = remove_min_child(&(*node)->right);
    }

    return data;
}

void *bt_remove(btnode **root, void *key, int(*cmp)(void *, void *))
{
    if (*root) {
        int result = cmp(key, (*root)->data);

        if (result > 0)
            return bt_remove(&(*root)->right, key, cmp);
        else if (result < 0)
            return bt_remove(&(*root)->left, key, cmp);
        else
            return delete_node(root);
    }

    return NULL; // key not found
}

void bt_print_preorder(btnode *root, void(*prn)(void *))
{
    if (root) {
        prn(root->data);
        bt_print_preorder(root->left, prn);
        bt_print_preorder(root->right, prn);
    }
}

void bt_print_inorder(btnode *root, void(*prn)(void *))
{
    if (root) {
        bt_print_inorder(root->left, prn);
        prn(root->data);
        bt_print_inorder(root->right, prn);
    }
}

void bt_print_postorder(btnode *root, void(*prn)(void *))
{
    if (root) {
        bt_print_postorder(root->left, prn);
        bt_print_postorder(root->right, prn);
        prn(root->data);
    }
}

void bt_clear(btnode **root, void(*fr)(void *))
{
    if (*root) {
        bt_clear(&(*root)->left, fr);
        bt_clear(&(*root)->right, fr);

        if (fr)
            fr((*root)->data);
        free(*root);
        *root = NULL;
    }
}
