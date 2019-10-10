#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

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

void FileInit (FILE * file)
{
    srand(time(NULL));
    int i = rand() % 10 + 1, j;
    int n, m;
    int next;

    for (n = 0; n < i; n++)
    { 
        j = rand() % 10 + 1;   
        for (m = 0; m < j; m++)
        {
            next = rand() % (int)(pow(2,16) - 1);
            fprintf(file, "%d ", next);
        }
        fputc('\n', file);
    }   
}

int main()
{
    FILE * inp;
    int c;
    int input;
    node *nd = NULL;

    inp = fopen("inp.txt", "w+r");
    out = fopen("out.txt", "w");

    FileInit(inp);

    if (!(inp || out))
    {
        printf("can`t open file");
        return ERROR_CREATE_OR_OPEN_FILE;
    }

    char checker;

    // do
    // {
    //     if (input = fscanf(inp, "%d", &c))
    //     {
    //         nd = Add(nd, c);
    //         printf("%d ", c);
    //     }

    //     else if (!input)
    //     {
    //         printf("the variable should have a digital type\n");
    //         return ERROR_TYPE;
    //     }
    // } while (checker = fgetc(inp) != EOF);

    while (checker = fgetc(inp) != EOF)
    {
        printf("%c", checker);
    }

    printInorder(nd, 0);

    LeftRootRight(nd);
    RightRootLeft(nd);

    fclose(inp);
    fclose(out);
    return 0;
}