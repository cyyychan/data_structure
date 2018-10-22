#include <stdio.h>
#include <stdlib.h>
#include "method.h"
#include <math.h>


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
    归并排序，采用递归思想， 了解算法步骤
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
}

void bubbleSort(ElemType *A, int n)
/*
    冒泡排序， 交换排序的一种， 改进算法， 记录了每次交换的位置
*/
{
    ElemType temp;
    int i, j, last_pos;
    for(j = n; j > 1; j = last_pos)
    {
        last_pos = 1;//初始化
        for(i = 1; i < j; i++)
        {
            if(A[i] > A[i + 1])
            {
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                last_pos = i;
            }
        }
    }
}

void quickSort(ElemType *A, int l, int h)
/*
    快排， 应用最广泛， 速度最快, 递归实现
*/
{
    int i, j, m;
    ElemType temp;
    i = l;
    j = h;
    m = (l + h) / 2;
    if(l >= h) return;
    while(i < j)
    {
        while((i < j) && (A[j] >= A[m])) j--;
        while((i < j) && (A[i] <= A[m])) i++;
        if(i == j)
        {
            temp = A[m];
            A[m] = A[i];
            A[i] = temp;
            m = i;
        }
        else
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;//交换值之后还需要移动位置
            j--;
        }
    }
    quickSort(A, l, m - 1);
    quickSort(A, m + 1, h);
}

void baseSort(ElemType *A, int n)
{
    /*
        基数排序
    */
    ElemType bucket[n + 1] = {0}, maxVal = 0;
    int i, digitPosition = 1;//数字的位
    int digitCount[10] = {0};//记录每个数字的个数， 及累计个数
    for(i = 1; i <= n; i++)
    {
        if(A[i] > maxVal) maxVal = A[i];
    }
    while(maxVal/digitPosition > 0)
    {
        for(i = 0; i <= 9; i++)
        {
            digitCount[i] = 0;
        }
        for(i = 1; i <= n; i++)
        {
            digitCount[(A[i] / digitPosition) % 10]++;
        }
        for(i = 1; i <= 9; i++)
        {
            digitCount[i] = digitCount[i] + digitCount[i - 1];
        }
        for(i = n; i >= 1; i--)
        {
            bucket[--digitCount[(A[i] / digitPosition) % 10]] = A[i];//此处--digitCount很关键
        }
        for(i = 0; i <= n; i++)
            A[i+1] = bucket[i];
        digitPosition = digitPosition * 10;
    }
}
