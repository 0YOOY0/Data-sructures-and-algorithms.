#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLData;

typedef struct DSListNode
{
	SLData data;
	struct DSListNode* prev;
	struct DSListNode* next;
}DSListNode;

DSListNode* BuyDListNode(SLData x)
{
	DSListNode* newnode=NULL;
	newnode=(DSListNode*)malloc(sizeof(DSListNode));
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}

void DSListInit(DSListNode** psl)
{
	DSListNode* head=(DSListNode*)malloc(sizeof(DSListNode));
	head->next=head;
	head->prev=head;
	(*psl)=head;
}

void DSListPrint(DSListNode* psl)
{
	if(!psl||psl->next==psl)
	{
		printf("无有效数据\n");
		return ;
	}
	DSListNode* cur=psl->next;
	while(cur!=psl)
	{
		printf("%d ",cur->data);
		cur=cur->next;
	}
	printf("\n");
}

void DSListDestroy(DSListNode** psl)
{
	if(!*psl)
	{
		printf("NULL");
		return ;
	}
	DSListNode* cur=(*psl)->next,*next=cur->next;
	if(cur!=next)//错误：忘记考虑只有一个头结点的情况 
	{
		(*psl)->next=NULL;
		while(cur!=(*psl))
		{
			free(cur);
			cur=next;
			next->prev=NULL;
			next=next->next;
		}
	}
	free(cur);
	cur=NULL;
}

void DSListPushBack(DSListNode** psl,SLData x)
{
	assert(*psl);
	DSListNode* newnode=BuyDListNode(x);
	DSListNode* head=(*psl),*tail=((*psl)->prev);
	tail->next=newnode;
	head->prev=newnode;
	newnode->next=head;
	newnode->prev=tail;
}

void DSListPopBack(DSListNode** psl)
{
	assert((*psl)->next!=(*psl));
	DSListNode* tail=(*psl)->prev,*prev=tail->prev;
	prev->next=(*psl);
	(*psl)->prev=prev;
	free(tail);
	tail=NULL;
}

void DSListPushFront(DSListNode** psl,SLData x)
{
	assert(*psl); 
	DSListNode* next=(*psl)->next,*newnode;
	newnode=BuyDListNode(x);
	newnode->next=next;
	newnode->prev=(*psl);
	next->prev=newnode;
	(*psl)->next=newnode;
}

void DSListPopFront(DSListNode** psl)
{
	assert(*psl&&(*psl)->next!=*psl);
	DSListNode* cur=(*psl)->next,*next=cur->next;
	(*psl)->next=next;
	next->prev=(*psl);
	free(cur);
	cur=NULL;
}

DSListNode* DSListFind(DSListNode* sl,SLData x)
{
	assert(sl);
	DSListNode* cur=sl->next;
	while(sl!=cur)
	{
		if(cur->data==x)
		return cur;
		cur=cur->next;
	}
	printf("NULL");
	return NULL;
}

void DSListInsert(DSListNode** psl,SLData x,DSListNode* pos)
{
	DSListNode* newnode=BuyDListNode(x);
	newnode->next=pos->next;
	newnode->prev=pos;
	pos->next=newnode;
	newnode->next->prev=newnode;
}

void DSListErase(DSListNode** psl,DSListNode* pos)
{
	assert(*psl);
	pos->prev->next=pos->next;//之前错误：少了->next; 
	pos->next->prev=pos->prev;//之前错误：少了->prev; 
	free(pos);
	pos=NULL;
}

void TestSList1()
{
	DSListNode* sl=NULL;
	DSListPrint(sl);
	DSListInit(&sl);
	DSListPrint(sl);
	DSListPushBack(&sl,1);
	DSListPushBack(&sl,2);
	DSListPushBack(&sl,3);
	DSListPushBack(&sl,4);
	DSListPrint(sl);
	DSListPopBack(&sl);
	DSListPopBack(&sl);
	DSListPrint(sl);
//	DSListPopBack(&sl);
//	DSListPopBack(&sl);
//	DSListPrint(sl);
//	DSListPopBack(&sl);
//	DSListPopBack(&sl);
//	DSListPrint(sl);
	DSListDestroy(&sl);
}

void TestSList2()
{
	DSListNode* sl=NULL;
	DSListPrint(sl);
	DSListInit(&sl);
	DSListPushFront(&sl,1);
	DSListPushFront(&sl,2);
	DSListPushFront(&sl,3);
	DSListPushFront(&sl,4);
	DSListPrint(sl);
	DSListPopFront(&sl);
	DSListPopFront(&sl);
	DSListPrint(sl);
	printf("%d ",DSListFind(sl,2)->data);
	DSListPopFront(&sl);
	DSListPopFront(&sl);
//	printf("%d ",DSListFind(sl,2)->data);
//	DSListPrint(sl);
//	DSListPopBack(&sl);
//	DSListPopBack(&sl);
//	DSListPrint(sl);
	DSListDestroy(&sl);
}

void TestSList3()
{
	DSListNode* sl=NULL;
	DSListPrint(sl);
	DSListInit(&sl);
	DSListInsert(&sl,1,sl);
	DSListInsert(&sl,2,sl);
	DSListInsert(&sl,3,sl);
	DSListInsert(&sl,4,sl);
	DSListInsert(&sl,5,sl);
	DSListPrint(sl);
	DSListErase(&sl,DSListFind(sl,5));
	DSListErase(&sl,DSListFind(sl,4));
	DSListErase(&sl,DSListFind(sl,2));
	DSListPrint(sl);
	DSListErase(&sl,DSListFind(sl,3));
	DSListErase(&sl,DSListFind(sl,1));
	DSListPrint(sl);
	DSListErase(&sl,sl);
	DSListPrint(sl);
	DSListDestroy(&sl);
}

int main()
{
//	TestSList1();
//	TestSList2();
	TestSList3();
	return 0;
}
