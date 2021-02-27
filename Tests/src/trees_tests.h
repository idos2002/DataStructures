#pragma once

#include <stdio.h>

#include <trees/binary_tree.h>
#include <trees/max_heap.h>

int tree_compare_int(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

void tree_print_int(void *data)
{
    printf("%d ", *(int *)data);
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
