#pragma once

typedef enum Status
{
    fail, sucess
}Status;

typedef int DataType;

typedef struct BSTNode{
    DataType data;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BST;

Status initialBST(BST *);
Status createBST(BST *, DataType *, int);
Status insertBST(BST *, DataType);
Status deleteBST(BST *, DataType);
Status findBST(BST *, DataType);

