#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"

int main()
{
    Status s = fail;
    DataType A[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BTree bt;
    s = initialBTree(&bt);
    if(s == sucess)
    {
        s = createCBTree(A, 10, &bt);
        /*
        if(s == sucess)
            printf("%d", bt->data);
        else
            printf("完全二叉树建立失败");
        */
    }
    printf("先序遍历：\n");
    preOrder(bt);
    printf("\n中序遍历：\n");
    midOrder(bt);
    printf("\n后序遍历：\n");
    laOrder(bt);
    //传递指针进函数可以释放内存
    destroyBTree(bt);
    return 1;
}
