#include <stdio.h>
#include <stdlib.h>
#include "method.h"


void insertSort(ElemType *A, int n)
/*
    简单插入排序，每次将有序数列后一个数插入有序列中
*/
{
    int i, j;
    for(i = 2; i <= n; i++)
    {
        A[0] = A[i];
        j = i - 1;
        while(j > 0 && A[0] < A[j])
        {
            A[j + 1] = A[j];
            j = j -1;
        }
        A[j + 1] = A[0];
    }
}

void shellSort(ElemType *A, int n)
/*
    希尔排序，间隔为d[i]的插入排序，d[i] = {5, 3, 1}
*/
{
    int d[3] = {5, 3, 1};
    int k = 0;
    int i = 0, j = 0;
    while(k < 3)
    {
        for(i = d[k] + 1; i <= n; i++)
        {
            A[0] = A[i];
            j = i - d[k];
            while(j > 0 && A[0] < A[j])
            {
                A[j + d[k]] = A[j];
                j = j - d[k];
            }
            A[j + d[k]] = A[0];
        }
        k++;
    }
}

void chooseSort(ElemType *A, int n)
/*
    选择排序，选择n - i个数字中最小的那个数
*/
{
    ElemType temp;
    int i = 1;
    int k = 1, j = 1;
    for(i = 1; i <=10; i++)
    {
        k = i;
        for(j = i + 1; j <= 10; j++)
        {
            if(A[j] < A[k])
            {
                k = j;
            }
        }
        if(A[i] != A[k])
        {
            temp = A[i];
            A[i] = A[k];
            A[k] = temp;
        }
    }
}

void mergeSort(ElemType *A, int n)
/*
    归并排序，采用递归思想
*/
{
    ElemType *Temp;
    Temp = (ElemType *)malloc((n + 1) * sizeof(ElemType));
    if(Temp != NULL)
    {
        _msort(A, Temp, 1, n);
        free(Temp);
    }
    else
        printf("no space");
}

void _msort(ElemType *A, ElemType *Temp, int left, int right)
{
    int center;
    if(left < right)
    {
        center = (left + right) / 2;
        _msort(A, Temp, left, center);
        _msort(A, Temp, center + 1, right);
        _merge(A, Temp, left, center + 1, right);
    }
}

void _merge(ElemType *A, ElemType *Temp, int lpos, int rpos, int right_end)
{
    int i, left_end, tempos, num;
    left_end = rpos - 1;
    tempos = lpos;
    num =  right_end - lpos + 1;
    while(lpos <= left_end && rpos <= right_end)
    {
        if(A[lpos] < A[rpos])
        {
            Temp[tempos++] = A[lpos++];
        }
        else
        {
            Temp[tempos++] = A[rpos++];
        }
    }
    while(lpos <= left_end)
    {
        Temp[tempos++] = A[lpos++];
    }
    while(rpos <= right_end)
    {
        Temp[tempos++] = A[rpos++];
    }
    for(i = 1; i <= num; i++,right_end--)
    {
        A[right_end] = Temp[right_end];//!!!注意
    }
    printf("%d\n", num);
}

void changeSort(ElemType *A)
{

}
void quickSort(ElemType *A)
{

}
void baseSort(ElemType *A)
{

}
