#include<stdio.h>
#include<stdlib.h>
#include "test_sqlist.h"
#include "sqlist.h"


int main(){
    Status s;
    SqList list;
    ElemType data[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s = testCreateList(&list, data, 10);
    s = testRetrivalPriorNext(&list, 5);
    s = testLocate(&list, 5);
    s = testLength(&list);
    s = testClearList(&list);
    if(s == sucess){
        listPrint(&list);
        printf("list已清空");
    }

    return 0;
}
