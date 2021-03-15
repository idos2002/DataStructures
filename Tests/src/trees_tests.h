#pragma once

#include <stdio.h>

#include <trees/avl_tree.h>
#include <trees/binary_tree.h>
#include <trees/max_heap.h>
#include <trees/min_heap.h>

int tree_compare_int(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

void tree_print_int(void *data)
{
    printf("%d ", *(int *)data);
}

void avl_test()
{
    int i;
    int arr[] = { 3, 8, 9, 4, 7, 1, 0, 5, 6, 2 };
    avlnode *root;
    avl_init(&root);

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        avl_insert(&root, arr + i, tree_compare_int);

    avl_print_inorder(root, tree_print_int);
    puts("");

    // printf("\nRemoved: %d\n", *(int *)avl_remove(&root, arr + 1, tree_compare_int));

    // avl_print_inorder(root, tree_print_int);

    printf("\nTree height: %d\n", avl_height(root));

    avl_clear(&root, NULL);

    puts("\nCleared tree");
    avl_print_inorder(root, tree_print_int);
}

void bt_test()
{
    int i;
    int arr[] = { 3, 8, 9, 4, 7, 1 };
    btnode *root;
    bt_init(&root);

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        bt_insert(&root, arr + i, tree_compare_int);

    bt_print_inorder(root, tree_print_int);

    printf("\nRemoved: %d\n", *(int *)bt_remove(&root, arr + 1, tree_compare_int));

    bt_print_inorder(root, tree_print_int);

    bt_clear(&root, NULL);

    puts("\nCleared tree");
    bt_print_inorder(root, tree_print_int);
}

void maxheap_test()
{
    int i;
    int arr[] = { 3, 8, 9, 4, 7, 1 };
    void *data;
    maxheap heap;
    maxheap_init(&heap);

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        maxheap_push(&heap, arr + i, tree_compare_int);

    printf("Peeked: %d\n", *(int *)maxheap_peek(&heap));

    while (!maxheap_empty(&heap)) {
        data = maxheap_pop(&heap, tree_compare_int);
        tree_print_int(data);
    }
    puts("");

    maxheap_clear(&heap, NULL);
    while (!maxheap_empty(&heap)) {
        data = maxheap_pop(&heap, tree_compare_int);
        tree_print_int(data);
    }
    puts("");
}

void minheap_test()
{
    int i;
    int arr[] = { 3, 8, 9, 4, 7, 1 };
    void *data;
    minheap heap;
    minheap_init(&heap);

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        minheap_push(&heap, arr + i, tree_compare_int);

    printf("Peeked: %d\n", *(int *)minheap_peek(&heap));

    while (!minheap_empty(&heap)) {
        data = minheap_pop(&heap, tree_compare_int);
        tree_print_int(data);
    }
    puts("");

    minheap_clear(&heap, NULL);
    while (!minheap_empty(&heap)) {
        data = minheap_pop(&heap, tree_compare_int);
        tree_print_int(data);
    }
    puts("");
}
