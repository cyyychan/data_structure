#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

Status listInit(LinkedListPtr l){
    Status s = fail;
    Ptr p;
    //注意这里使用*l，并非l
    if((*l) == NULL)
    {
        p = (Ptr)malloc(sizeof(Node));
        if(p == NULL) return s;
        *l = p;
        (*l)->next = NULL;
        s = sucess;
    }
    return s;
}

void listDestory(LinkedListPtr l){
    listClear(l);
    if(*l)
    {
        free(*l);
        (*l) = NULL;
    }
}

bool listEmpty(LinkedListPtr l){
    return (*l)->next == NULL;
}

void listClear(LinkedListPtr l){
    Ptr p = (*l)->next;
    if(*l)
    {
        while(p)
        {
            (*l)->next = p->next;
            free(p);
            p = (*l)->next;
        }
    }
}
int listSize(LinkedListPtr l){
    int i = 1;
    Ptr p = (*l)->next;
    if(*l)
    {
        while(p->next)
        {
            i++;
            p = p->next;
        }
    }
    return i;
}

Status listRetrival(LinkedListPtr l, int pos, ElemType *elem){
    Status s = fail;
    int i = 1;
    Ptr p = (*l)->next;
    if(*l)
    {
        while(p && i != pos)
        {
            i++;
            p = p->next;
        }
        if(i == pos && p)
        {
            (*elem) = p->elem;
            s = sucess;
        }
    }
    return s;
}

Status listLocate(LinkedListPtr l, ElemType elem, int *pos){
    Status s = fail;
    int i = 1;
    Ptr p = (*l)->next;
    if(*l)
    {
        while(p && p->elem != elem)
        {
            i++;
            p = p->next;
        }
        if(p->elem == elem && p)
        {
            *pos = i;
            s = sucess;
        }
    }
    return s;
}

Status listFind(LinkedListPtr l, int pos, Ptr *pAddr)
{
    Status s = fail;
    int i=1;
    Ptr p=(*l)->next;
    if(*l)
    {
        //当pos为0时无意义，p指向空指针
        while(p && i!=pos)
        {
            i++;
            p = p->next;
        }
        if(i == pos && p)
        {
            *pAddr = p;
            s = sucess;
        }
    }
    return s;
}

Status listInsert(LinkedListPtr l, int pos, ElemType elem){
    Status s = fail;
    Ptr p = (*l)->next, q = (*l);
    if(*l)
    {
        if(pos > 1)
        {
            s = listFind(l, pos-1, &q);
            if(s == sucess)
            {
                p = (Ptr)malloc(sizeof(Node));
                if(p)
                {
                    p->elem = elem;
                    p->next = q->next;
                    q->next = p;
                    s = sucess;
                }
            }
        }
        else
        {
            p = (Ptr)malloc(sizeof(Node));
            if(p)
            {
                p->elem = elem;
                p->next = q->next;
                q->next = p;
                s = sucess;
            }
        }

    }
    return s;
}

Status listDelete(LinkedListPtr l, int pos){
    Status s = fail;
    Ptr p = (*l)->next, q = (*l);
    if(*l)
    {
        s = listFind(l, pos-1, &q);
        if(s == sucess)
        {
            p = q->next;
            q->next = p->next;
            free(p);
            s = sucess;
        }
    }
    return s;
}

Status listPrior(LinkedListPtr l, int pos, ElemType *elem){
    Status s = fail;
    Ptr q = (*l);
    if(*l)
    {
        s = listFind(l, pos-1, &q);
        *elem = q->elem;
    }
    return s;
}

Status listNext(LinkedListPtr l, int pos, ElemType *elem){
    Status s = fail;
    Ptr q = (*l);
    if(*l)
    {
        s = listFind(l, pos+1, &q);
        *elem = q->elem;
    }
    return s;
}

void listPrint(LinkedListPtr l){
    Ptr p = (*l)->next;
    while(p)
    {
        printf("%d ", p->elem);
        p = p->next;
    }
}
