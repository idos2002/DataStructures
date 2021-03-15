#include "avl_tree.h"

static avlnode *create_avlnode(void *data)
{
    avlnode *node = malloc(sizeof(avlnode));
    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void avl_init(avlnode **root)
{
    *root = NULL;
}

int avl_height(avlnode *root)
{
    if (!root)
        return 0;

    return root->height;
}

static void fix_height(avlnode *root)
{
    if (!root) return;
    
    int leftHeight = avl_height(root->left);
    int rightHeight = avl_height(root->right);

    root->height = 1 + max(leftHeight, rightHeight);
}

static void rotate_left(avlnode **root)
{
    avlnode *newRoot = (*root)->right;
    (*root)->right = newRoot->left;
    newRoot->left = *root;
    *root = newRoot;

    fix_height((*root)->left);
    fix_height(*root);
}

static void rotate_right(avlnode **root)
{
    avlnode *newRoot = (*root)->left;
    (*root)->left = newRoot->right;
    newRoot->right = *root;
    *root = newRoot;

    fix_height((*root)->right);
    fix_height(*root);
}

static int balance_factor(avlnode *root)
{
    return avl_height(root->left) - avl_height(root->right);
}

static void avl_balance(avlnode **root)
{
    int balanceFactor = balance_factor(*root);

    if (balanceFactor == 2) { // If left subtree heavy
        // In LR case
        if (balance_factor((*root)->left) == -1)
            rotate_left(&(*root)->left);

        // Both LL and LR
        rotate_right(root);
    } else if (balanceFactor == -2) { // If right subtree heavy
        // In RL case
        if (balance_factor((*root)->right) == 1)
            rotate_right(&(*root)->right);

        // Both RR and RL
        rotate_left(root);
    } else { // If balanced, only fix height
        fix_height(*root);
    }
}

void avl_insert(avlnode **root, void *data, int(*cmp)(void *, void *))
{
    if (!*root) {
        *root = create_avlnode(data);
    } else {
        if (cmp(data, (*root)->data) >= 0)
            avl_insert(&(*root)->right, data, cmp);
        else
            avl_insert(&(*root)->left, data, cmp);

        avl_balance(root);
    }
}

void avl_print_preorder(avlnode *root, void(*prn)(void *))
{
    if (root) {
        prn(root->data);
        avl_print_preorder(root->left, prn);
        avl_print_preorder(root->right, prn);
    }
}

void avl_print_inorder(avlnode *root, void(*prn)(void *))
{
    if (root) {
        avl_print_inorder(root->left, prn);
        prn(root->data);
        avl_print_inorder(root->right, prn);
    }
}

void avl_print_postorder(avlnode *root, void(*prn)(void *))
{
    if (root) {
        avl_print_postorder(root->left, prn);
        avl_print_postorder(root->right, prn);
        prn(root->data);
    }
}

void avl_clear(avlnode **root, void(*fr)(void *))
{
    if (*root) {
        avl_clear(&(*root)->left, fr);
        avl_clear(&(*root)->right, fr);

        if (fr)
            fr((*root)->data);
        free(*root);
        *root = NULL;
    }
}
