#pragma once
typedef int ElemType;

void insertSort(ElemType *, int n);
void shellSort(ElemType *, int n);
void chooseSort(ElemType *, int n);
void mergeSort(ElemType *, int n);
void _msort(ElemType *, ElemType *, int left, int right);
void _merge(ElemType *, ElemType *, int left, int center, int right);
void changeSort(ElemType *);
void quickSort(ElemType *);
void baseSort(ElemType *);
