#include<stdio.h>
#include<stdlib.h>
#include "test_linkedlist.h"


Status testCreateList(LinkedListPtr l, ElemType data[], int n){
    int i;
    Status s = fail;
    s = listInit(l);
    if(s == sucess){
        for(i = 1; i <= n; i++){
            s = listInsert(l, i, data[i]);
            if(s != sucess) break;
        }
    }
    listPrint(l);
    return s;
}

Status testClearList(LinkedListPtr l){
    Status s = fail;
    if(!listEmpty(l)){
        listClear(l);
        if(listEmpty(l)){
            s = sucess;
        }
    }
    return s;
}

Status testRetrivalPriorNext(LinkedListPtr l, int pos){
    Status s = range_over;
    ElemType e, p, n;
    s = listRetrival(l, pos, &e);
    if(s == sucess){
        printf("该位置的元素为：%d\n", e);
        s = listPrior(l, pos, &p);
        if(s == sucess) printf("该元素的前驱为:%d\n", p);
        else printf("该元素为第一个元素\n");
        s = listNext(l, pos, &n);
        if(s == sucess) printf("该元素的后继为:%d\n", n);
        else printf("该元素为最后一个元素\n");
    }
    else printf("位置不合法\n");
    return s;
}

Status testLocate(LinkedListPtr l, ElemType elem){
    Status s = range_over;
    int pos;
    s = listLocate(l, elem, &pos);
    if(s == sucess){
        printf("该元素在表中位置为：%d\n", pos);
    }
    else printf("查找失败\n");
    return s;
}

Status testLength(LinkedListPtr l){
    Status s = fail;
    int length;
    length = listSize(l);
    s = sucess;
    printf("表长为：%d\n", length);
    return s;
}

