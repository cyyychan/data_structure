#pragma once
#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10
#define bool int

typedef enum Status{
    sucess, fail, fatal, range_error
}Status;

typedef int ElemType;

typedef struct SqList{
    ElemType *elem;
    int length;
    int list_size;
}SqList, *Ptr, *SqListPtr;

Status listInit(SqListPtr l);
void listDestory(SqListPtr l);
bool listEmpty(SqListPtr l);
void listClear(SqListPtr l);
int listSize(SqListPtr l);
Status listRetrival(SqListPtr l, int pos, ElemType *elem);
Status listLocate(SqListPtr l, ElemType elem, int *pos);
Status listInsert(SqListPtr l, int pos, ElemType elem);
Status listDelete(SqListPtr l, int pos);
Status listPrior(SqListPtr l, int pos, ElemType *elem);
Status listNext(SqListPtr l, int pos, ElemType *elem);
void listPrint(SqListPtr l);