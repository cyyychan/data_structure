#pragma once
#define TABLE_INIT_SIZE 100

typedef enum Status{
    sucess, unsucess
}Status;
typedef int KeyType;
typedef char PhoneNumType;

typedef struct DataType{
    KeyType key;
    PhoneNumType num;
}DataType;

typedef struct HashTable{
    DataType *data;
    int length;
    int table_size;
}HashTable, *HashTablePtr;

int Hash(KeyType key);
int collision(HashTablePtr h, int p, int c);
Status initHash(HashTablePtr h);
Status insertHash(HashTablePtr h, DataType d);
Status createHash(HashTablePtr h, DataType *d, int n);
void destoryHash(HashTablePtr h);
Status searchHash(HashTablePtr h, KeyType key, int *p, int *c);
