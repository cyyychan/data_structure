#include<stdio.h>
#include<stdlib.h>
#include"hashtable.h"

Status initHash(HashTablePtr h){
    Status s = unsucess;
    if(h != NULL)
    {
        h->data = (DataType*)malloc((TABLE_INIT_SIZE + 1) * sizeof(DataType));
        h->table_size = TABLE_INIT_SIZE;
        h->length = 0;
        s = sucess;
    }
    return s;
}

Status searchHash(HashTablePtr h, KeyType key, int *p, int *c){
    Status s = unsucess;
    *p = Hash(key);
    while(h->data[*p].key != NULL && h->data[*p].key != key)
    {
        (*c)++;
        (*p) = collision(h, *p, *c);
    }
    if(h->data[*p].key == key)
    {
        s = sucess;
    }
    return s;
}

int Hash(KeyType key)
{
    return key;
}

int collision(HashTablePtr h, int p, int c)
{
    return p = (p + c) % (h->table_size);
}

Status insertHash(HashTablePtr h, DataType d){
    Status s = unsucess;
    int p = 0;
    int c = 0;
    s = searchHash(h, d.key, &p, &c);
    if(s == unsucess && h->data[p].key == NULL)
    {
        p = d.key;
        h->data[p].key = d.key;
        h->data[p].num = d.num;
        s = sucess;
    }
    return s;
}

Status createHash(HashTablePtr h, DataType *d, int n){
    Status s;
    int i = 1;
    s = initHash(h);
    for(i = 1; i <= n; i++)
    {
        s = insertHash(h, d[i]);
        if(s != sucess)
        {
            break;
        }
    }
    return s;
}

void destoryHash(HashTablePtr h){
    if(h != NULL)
    {
        if(h->data)
        {
            free(h->data);
            h->data = NULL;
            h->table_size = 0;
            h->length = 0;
        }
    }
}


