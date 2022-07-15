#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QData;

typedef struct QueueNode
{
	struct QueueNode* next;
	QData data;
}QueueNode;

typedef struct Queue
{
	QueueNode* tail;
	QueueNode* head;
}Queue;

void QueueInit(Queue* pq)
{
	pq->tail=NULL;
	pq->head=NULL;
}

bool QueueEmpty(Queue* pq)
{
	if((!pq->head)&&(!pq->tail))
	return true;
	else 
	return false;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	while(!pq->head)
	{
		QueueNode* next=pq->head->next;
		free(pq->head);
		pq->head=next;
	}
	free(pq->head);
	pq->head=pq->tail=NULL;
}

void QueuePush(Queue* pq,QData x)
{
	assert(pq);
	QueueNode* newnode=(QueueNode*)malloc(sizeof(QueueNode));
	newnode->data=x;
	newnode->next=NULL;
	if(!pq->head&&!pq->tail)
	{
		pq->head=pq->tail=newnode;
	}
	else
	{
		pq->tail->next=newnode;//居然少了这一句！ 
		pq->tail=newnode;
	}
//	printf("%d ",pq->tail->data);
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* tmp=pq->head->next;
	free(pq->head);
	pq->head=tmp;
	if(!pq->head)
	pq->tail=NULL;
}

QData QueueFront(Queue* pq)
{
	assert(pq);
	return pq->head->data;
}

QData QueueBack(Queue* pq)
{
	assert(pq);
	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int size=0;
	QueueNode* cur=pq->head;
	while(cur)
	{
		QueueNode* tmp=cur->next;//好家伙，少了个next真棒！！！ 
		size++;
		cur=tmp;
	}
	return size;
}

void QueueTest1()
{
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue,1);
	QueuePush(&queue,2);
	QueuePush(&queue,3);
	QueuePush(&queue,4);
	QueuePop(&queue);
	QueuePop(&queue);
	printf("%d\n",QueueFront(&queue));
	printf("%d\n",QueueBack(&queue));
	int size=QueueSize(&queue);
	printf("%d\n",size);
	QueueDestroy(&queue);
}

int main()
{
	QueueTest1();
	return 0;
}
