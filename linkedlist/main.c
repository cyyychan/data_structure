#include<stdio.h>
#include<stdlib.h>
#include "test_linkedlist.h"
#include "linkedlist.h"


int main(){
    Status s;
    Ptr list=NULL;
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
    listDestory(&list);
    return 0;
}
