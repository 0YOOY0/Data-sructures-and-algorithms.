#include "Heap.h"

void swap(HDatatype* pdata1, HDatatype* pdata2)
{
	int t = *pdata1;
	*pdata1 = *pdata2;
	*pdata2 = t;
}

void AdjustDown(Heap* php,int n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1<n&&php->hp[child] > php->hp[child + 1])
			child = child + 1;
		if (php->hp[child] < php->hp[parent])
			swap(&php->hp[child], &php->hp[parent]);
		else//
			break;
		parent = child;
		child = parent * 2 + 1;
	}
}

void HeapInit(Heap* php, HDatatype* a, int n)
{
	php->hp= (HDatatype*)malloc(sizeof(HDatatype) * n);//注意这里用malloc
	memcpy(php->hp, a, sizeof(HDatatype) * n);//注意这里的第三个参数是size*n
	php->capacity = php->size = n;
	int i;
	for (i = (n - 1 - 1) / 2;i >= 0;i--)
	{
		AdjustDown(php, n, i);
	}
}

void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->hp);
	php->hp = NULL;
	php->capacity = php->size = 0;
}

void AdjustUp(Heap* php, int n)
{
	int child = n - 1;
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (php->hp[child] < php->hp[parent])
		{
			swap(&php->hp[child], &php->hp[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapSort(Heap* php)
{
	assert(php);
	assert(php->size > 0);
	//降序
	swap(&php->hp[0], &php->hp[php->size - 1]);
	int i = php->size;
	i--;
	for ( ;i > 0;i--)
	{
		AdjustDown(php, i, 0);
		swap(&php->hp[0], &php->hp[i - 1]);
	}
	for (i = 0;i < php->size;i++)
	{
		printf("%d ", php->hp[i]);
	}
	printf("\n");
}

void HeapPush(Heap* php, HDatatype x)
{
	assert(php);
	int i;
	for (i = 0;i < php->size;i++)
	{
		printf("%d ", php->hp[i]);
	}
	printf("\n");
	if (php->capacity == php->size)
	{
		HDatatype* tmp = (HDatatype*)realloc(php->hp, php->capacity * 2);
		php->hp = tmp;//这一步又忘了
	}
	php->hp[php->size] = x;
	php->size++;
	for (i = 0;i < php->size;i++)
	{
		printf("%d ", php->hp[i]);
	}
	printf("\n");
	AdjustUp(php, php->size);
	for (i = 0;i < php->size;i++)
	{
		printf("%d ", php->hp[i]);
	}
	printf("\n");
}

void HeapPop(Heap* php)
{
	assert(php);
	assert(php->size>0);
	swap(&php->hp[0], &php->hp[php->size - 1]);
	php->size--;
	int n = php->size;
	AdjustDown(php, n, 0);
	int i;
	for (i = 0;i < php->size;i++)
	{
		printf("%d ", php->hp[i]);
	}
	printf("\n");
}

int HeapTop(Heap* php)
{
	assert(php);
	if (!php->hp)
		printf("NULL\n");
	return php->hp[0];
}
