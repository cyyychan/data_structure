#include <stdio.h>
#include <stdlib.h>
#include "bs_tree.h"

Status initialBST(BST *root)
{
    Status s = fail;
    if((*root) == NULL)
    {
        (*root) = (BST *)malloc(sizeof(BSTNode));
        if((*root) == NULL) return s;
        s = sucess;
    }
    return s;
}

Status createBST(BST *root, DataType *data_array, int n)
{
    Status s = fail;
    int i = 1;
    BST p = *root;
    (*root)->data = data_array[i++];
    if((*root) != NULL)
    {
        while(i < n)
        {
            s = insertBST(root, data_array[i++]);
            if(s == fail) break;
        }
    }
    return s;
}

Status insertBST(BST *node, DataType data)
{
    Status s = fail;
    while((*node) != NULL)
    {
        if((*node)->data < data)
        {
            *node = (*node)->lchild;
        }
        if((*node)->data > data)
        {
            *node = (*node)->rchild;
        }
    }
    *node = (BST *)malloc(sizeof(BSTNode));
    if((*node) != NULL)
    {
        (*node)->data = data;
        s = sucess;
    }
    return s;
}

Status deleteBST(BST *, DataType)
{

}

Status findBST(BST *, DataType)
{

}
