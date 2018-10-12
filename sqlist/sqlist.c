#include<stdio.h>
#include<stdlib.h>
#include "sqlist.h"

Status listInit(SqListPtr l){
    Status s = fail;
    if(l != NULL){
        l->elem = (ElemType *)malloc((LIST_INIT_SIZE + 1)*sizeof(ElemType));
        if(l->elem){
            l->list_size = LIST_INIT_SIZE;
            l->length = 0;
            s = sucess;
        }
    }
    return s;
}

void listDestory(SqListPtr l){
    if(l){
        if(l->elem){
            free(l->elem);
            l->length = 0;
            l->list_size = 0;
            l->elem = NULL;
        }
    }
}

bool listEmpty(SqListPtr l){
    if(l){
        return l->length == 0;
    }
}

void listClear(SqListPtr l){
    if(l){
        l->length = 0;
    }
}

int listSize(SqListPtr l){
    if(l){
        return l->length;
    }
}

Status listRetrival(SqListPtr l, int pos, ElemType *elem){
    Status s = range_over;
    if(l){
        if(pos >= 1 && pos <= l->length){
            *elem = l->elem[pos];
            s = sucess;
        }
    }
    return s;
}

Status listLocate(SqListPtr l, ElemType elem, int *pos){
    Status s = range_over;
    int i = 1;
    if(l){
        while(i <= l->length){
            if(elem == l->elem[i]){
                *pos = i;
                s = sucess;
                break;
            }
            else i++;
        }
    }
    return s;
}

Status listInsert(SqListPtr l, int pos, ElemType elem){
    Status s = range_over;
    int i;
    if(l->length + 1 <= l->list_size){
        if(pos >= 1 && pos <= l->length + 1){
            for(i = l->length; i >= pos; i--){
                l->elem[i+1] = l->elem[i];
            }
            l->length++;
            l->elem[i+1] = elem;
            s = sucess;
        }
    }
    return s;
}

Status listDelete(SqListPtr l, int pos){
    Status s = range_over;
    int i;
    if(l->length - 1 >= 0){
        if(pos >= 1 && pos <= l->length){
            for(i = pos; i <= l->length - 1; i++){
                l->elem[i] = l->elem[i+1];
            }
            l->length--;
                s = sucess;
        }
    }
    return s;
}

Status listPrior(SqListPtr l, int pos, ElemType *elem){
    Status s = range_over;
    if(l){
        if(pos > 1 && pos <= l->length){
            *elem = l->elem[pos-1];
            s = sucess;
        }
    }
    return s;
}

Status listNext(SqListPtr l, int pos, ElemType *elem){
    Status s = range_over;
    if(l){
        if(pos >= 1 && pos < l->length){
            *elem = l->elem[pos+1];
            s = sucess;
        }
    }
    return s;
}

void listPrint(SqListPtr l){
    int i;
    if(l){
        for(i = 1; i <= l->length; i++){
            printf("%d ", l->elem[i]);
            if(i % 10 == 0){
                printf("\n");
            }
        }
    }
}
