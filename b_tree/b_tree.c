#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"

Status initialBTree(BTree *R)
{
    /*
    根节点初始化，分配地址空间
    */
    Status s = fail;
    BTree p;
    if(*R == NULL)
    {
        p = (BTree)malloc(sizeof(BTreeNode));
        if(p == NULL) return s;
        *R = p;
        (*R)->data = 1;
        (*R)->lchild = NULL;
        (*R)->rchild = NULL;
        s = sucess;
    }
    return s;
}

Status createCBTree(DataType *A, int n, BTree *R)
{
    /*
    利用队列思想构建一棵完全二叉树， 注意输入为（BTree *）为二叉树根节点指针的指针，为了参数传递
    */
    Status s = fail;
    BTree Queue[n+1];
    int front, rear;
    front = 0;
    rear = 1;
    Queue[rear] = *R;
    while(front != rear)
    {
        front++;
        Queue[front]->data = A[front];
        if(Queue[front]->lchild == NULL && rear < 10)
        {
            Queue[front]->lchild = (BTree)malloc(sizeof(BTreeNode));
            if(Queue[front]->lchild == NULL) break;
            rear++;
            Queue[rear] = Queue[front]->lchild;
        }
        if(Queue[front]->rchild == NULL && rear < 10)
        {
            Queue[front]->rchild = (BTree)malloc(sizeof(BTreeNode));
            if(Queue[front]->rchild == NULL) break;
            rear++;
            Queue[rear] = Queue[front]->rchild;
        }
    }
    if(front == rear) s = sucess;
    (*R) = Queue[1];//将根节点指针指向队首数据
    return s;
}

void destroyBTree(BTree R)
{
    if(R != NULL)
    {
        destroyBTree(R->lchild);
        destroyBTree(R->rchild);
        free(R);
    }
}

void preOrder(BTree R)
{
    if(R != NULL)
    {
        visit(R->data);
        preOrder(R->lchild);
        preOrder(R->rchild);
    }
}

void midOrder(BTree R)
{
    if(R != NULL)
    {
        midOrder(R->lchild);
        visit(R->data);
        midOrder(R->rchild);
    }
}

void laOrder(BTree R)
{
    if(R != NULL)
    {
        laOrder(R->lchild);
        laOrder(R->rchild);
        visit(R->data);
    }
}

void visit(DataType data)
{
    printf("%d\t", data);
}

void bfOrder(BTree R, int n)
{
    BTree queue[n+1];
    int front = 0;
    int rear = 1;
    queue[rear] = R;
    while(front != rear)
    {
        front++;
        visit(queue[front]->data);
        if(queue[front]->lchild != NULL)
        {
            rear++;
            queue[rear] = queue[front]->lchild;
        }
        if(queue[front]->rchild != NULL)
        {
            rear++;
            queue[rear] = queue[front]->rchild;
        }
    }
}
