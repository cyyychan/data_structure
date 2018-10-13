#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main()
{
    Status s;
    HashTable hash;
    int n = 2;
    int p = 0;
    int c = 0;
    DataType data[3];
    data[1].key = 20;
    data[1].num = 110;
    data[2].key = 30;
    data[2].num = 120;
    s = createHash(&hash, data, n);
    printf("%d\n", hash.data[20].key);
    printf("%d\n", hash.data[30].key);
    s = searchHash(&hash, 30, &p, &c);
    printf("%d, %d", p, c);
    return 0;
}
