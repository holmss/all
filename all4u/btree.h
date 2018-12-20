#include <stdio.h>
#include <stdlib.h>

#ifndef BTREE_C
#define BTREE_C

typedef struct TBtreeNode
{
    int value;
    struct TBtreeNode *left;
    struct TBtreeNode *right;
} node;

node *Add(node *nd, int value)
{
    if (nd == NULL)
    {
        node *new_nd = (node *)malloc(sizeof(node));
        new_nd->left = NULL;
        new_nd->right = NULL;
        new_nd->value = value;
        return new_nd;
    }
    else if (nd->value == value)
        return nd;

    if (nd->value < value)
        nd->right = Add(nd->right, value);
    else
        nd->left = Add(nd->left, value);

    return nd;
}

void printInorder(const node *tree, int tab)
{
    if (tree == NULL)
    {
        return;
    }
    printInorder(tree->left, tab + 2);
    for (int i = 0; i < tab; ++i)
    {
        putchar(' ');
    }
    printf("%d\n", tree->value);
    printInorder(tree->right, tab + 2);
}

#endif
