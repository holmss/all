#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR_CREATE_OR_OPEN_FILE -1
#define ERROR_TYPE -2

FILE * out;

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

void LeftRootRight(node *node)
{
    if (node == NULL)
    {
        return;
    }
    
    LeftRootRight(node->left);
    
    if((node->value)%2 == 0)
        fprintf(out, "%d ", node->value);
    
    LeftRootRight(node->right);
}

void RightRootLeft(node * node)
{
    if (node == NULL)
        return;
    
    RightRootLeft(node->right);

    if((node->value)%2 != 0)
        fprintf(out, "%d ", node->value);

    RightRootLeft(node->left);
}

int main()
{
    int c;
    int inp;
    node *nd = NULL;

    out = fopen("out.txt", "w");

    if (!out)
    {
        printf("can`t open file");
        return ERROR_CREATE_OR_OPEN_FILE;
    }

    do
    {
        if ((inp = scanf("%d", &c)) == 1)
            nd = Add(nd, c);

        else if (!inp)
        {
            printf("the variable should have a digital type\n");
            return ERROR_TYPE;
        }

        else
            break;
    } while (inp);

    printInorder(nd, 0);

    LeftRootRight(nd);
    RightRootLeft(nd);

    fclose(out);
    return 0;
}