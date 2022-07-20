#pragma once

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

typedef int HDatatype;
typedef struct Heap
{
	HDatatype* hp;
	int size;
	int capacity;
}Heap;

void swap(HDatatype* data1, HDatatype* data2);
void AdjustDown(Heap* php,int n,int root);
void HeapInit(Heap* php, HDatatype* a,int n);//n用于记录a中数组个数
void HeapDestroy(Heap* php);
void AdjustUp(Heap* php, int n);
void HeapPush(Heap* php, HDatatype x);
void HeapPop(Heap* php);
int HeapTop(Heap* php);