#include <stdio.h>
#include <stdlib.h>
#include "method.h"
#include <time.h>

int main()
{
    int i = 1;
    ElemType A[11] = {0,3,5,6,4,8,5,4,3,1,2};
    int flag = 0;
    int c_start = 0;
    int time = 0;
    /*
    printf("0:插入排序；1：希尔排序；2：选择排序；3：归并排序；4：交换排序；5：快速排序；6：基数排序\n");
    scanf("请输入演示算法类型：%d", &flag);
    switch(flag)
    {
        case 0:
            printf("插入排序结果为：\n");
            insertSort(A, 10);
            break;
        case 1:
            printf("希尔排序结果为：\n");
            shellSort(A, 10);
            break;
        case 2:
            printf("选择排序结果为：\n");
            chooseSort(A, 10);
            break;
        case 3:
            printf("归并排序结果为：\n");
            mergeSort(A, 10);
            break;
        case 4:
            printf("交换排序结果为：\n");
            bubbleSort(A, 10);
            break;
        case 5:
            printf("快速排序结果为：\n");
            break;
        case 6:
            printf("基数排序结果为：\n");
            break;
        default:
            printf("输入有误：\n");
            break;
    }
    */
    bubbleSort(A, 10);
    for(i = 1; i <= 10; i++)
    {
        printf("%d\t", A[i]);
    }
    return 0;
}
