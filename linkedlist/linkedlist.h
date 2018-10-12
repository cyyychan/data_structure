#pragma once
#define bool int

typedef enum Status{
    sucess, fail, fatal, range_over
}Status;

typedef int ElemType;

typedef struct Node{
    ElemType elem;
    struct Node *next;
}Node, *Ptr;

typedef Ptr *LinkedListPtr;

Status listInit(LinkedListPtr l);
void listDestory(LinkedListPtr l);
bool listEmpty(LinkedListPtr l);
void listClear(LinkedListPtr l);
int listSize(LinkedListPtr l);
Status listRetrival(LinkedListPtr l, int pos, ElemType *elem);
Status listLocate(LinkedListPtr l, ElemType elem, int *pos);
Status listFind(LinkedListPtr l, int pos, Ptr *pAddr);
Status listInsert(LinkedListPtr l, int pos, ElemType elem);
Status listDelete(LinkedListPtr l, int pos);
Status listPrior(LinkedListPtr l, int pos, ElemType *elem);
Status listNext(LinkedListPtr l, int pos, ElemType *elem);
void listPrint(LinkedListPtr l);
