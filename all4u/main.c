#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "btree.h"

#define ERROR_CREATE_OR_OPEN_FILE -1
#define ERROR_TYPE -2

FILE * out;

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