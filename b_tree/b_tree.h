#pragma once

typedef enum Status
{
    fail, sucess
}Status;

typedef int DataType;

typedef struct BTreeNode{
    DataType data;
    struct BTreeNode *lchild, *rchild;
}BTreeNode, *BTree;

Status initialBTree(BTree *);
Status createCBTree(DataType *, int, BTree *);
void destroyBTree(BTree);
void preOrder(BTree);
void midOrder(BTree);
void laOrder(BTree);
void visit(DataType);
