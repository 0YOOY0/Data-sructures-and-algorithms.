#include "Heap.h"

int main()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap heap;
	HeapInit(&heap, a, sizeof(a) / sizeof(a[0]));
	HeapPush(&heap, 13);
	HeapPush(&heap, 13);
	HeapPop(&heap);
	printf("%d\n", HeapTop(&heap));
	HeapSort(&heap);
	return 0;
}