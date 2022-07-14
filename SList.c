#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

typedef int STDatatype;

typedef struct SListNode
{
	STDatatype data;
	struct SListNode* next;
}SListNode;

SListNode* SListBuyNode(STDatatype x)//����������SListNode*
{
	SListNode* newnode=(SListNode*)malloc(sizeof(SListNode));
	newnode->data=x;
	newnode->next=NULL;
	return newnode;
}

void SListPrint(SListNode* plist)
{
	while(plist)
	{
		printf("%d->",plist->data);
		plist=plist->next;
	}
	printf("NULL\n");
}

void SListDestroy(SListNode** pplist)
{
	free(*pplist);
	(*pplist)=NULL;
}

void SListPushBack(SListNode** pplist,STDatatype x)//β��Ҫ����û�н������ 
{
	SListNode* newnode=SListBuyNode(x);
	SListNode* tail=NULL;
	if(!(*pplist))
	(*pplist)=newnode;
	else
	{
		tail=(*pplist);
		while(tail->next)
		{
			tail=tail->next;
		}
		tail->next=newnode;
	}
}

void SListPopBack(SListNode** pplist)//βɾҪ����ֻ��һ���ڵ����� 
{
	assert((*pplist)!=NULL);
	SListNode* tail=(*pplist)->next;//
	SListNode* prev=(*pplist);
	if(!tail)
	{
		free(*pplist);
		(*pplist)=NULL;
	}
	else
	{
		while(tail->next)//
		{
			prev=tail;
			tail=tail->next;
		}
		prev->next=NULL;
	}
	free(tail);
	tail=NULL;
}

void SListPushFront(SListNode** pplist,STDatatype x)//ֻ��ͷ�岻�÷���� 
{
	SListNode* newnode=SListBuyNode(x);
	newnode->next=(*pplist);
	(*pplist)=newnode;
}

void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* prev=(*pplist);
	if(!(*pplist)->next)
	(*pplist)=NULL;
	else
	(*pplist)=(*pplist)->next;
	free(prev);
	prev=NULL; 
}

SListNode* SListFind(SListNode* plist,STDatatype x)
{
	while(plist->data!=x&&plist!=NULL)//�����߼�д��һ�� 
	{
		plist=plist->next;
	}
	return plist;
}

void SListInsert(SListNode** pplist,SListNode* pos,STDatatype x)//��posǰ����� 
{
	SListNode* newnode=SListBuyNode(x);
	SListNode* prev=*pplist;
	if(pos==(*pplist))
	{
		newnode->next=(*pplist);
		(*pplist)=newnode;
	}
	else
	{
		while(prev->next!=pos)
		{
			prev=prev->next;
		}
		newnode->next=pos;
		prev->next=newnode;
	}
}

void SListErase(SListNode** pplist,SListNode* pos)//ɾ��pos������ 
{
	assert(*pplist);
	SListNode* prev=*pplist,*after=*pplist;
	if(pos==*pplist)
	{
		if((*pplist)->next==NULL)
		{
			free(*pplist);
			*pplist=NULL;
			return;
		}
		else
		{
			*pplist=(*pplist)->next;
		}
	}
	else
	{
		while(prev->next!=pos)
		prev=prev->next;
		after=pos->next;
		prev->next=after;
	}
	free(pos);
	pos=NULL;
}

void SListInsertAfter(SListNode** pplist,SListNode* pos,STDatatype x)//��pos�������(���򵥣� 
{
	SListNode* newnode=SListBuyNode(x);
	SListNode* after=pos->next;
	pos->next=newnode;
	newnode->next=after;
}

void SListEraseAfter(SListNode** pplist,SListNode* pos)//ɾ��pos��������� �����򵥣� 
{
	assert(pos->next&&*pplist);
	SListNode* tmp=pos->next,*after=tmp->next;
	pos->next=after;
	free(tmp);
	tmp=NULL;
}

void TestSList1()
{
	SListNode* plist=NULL;//����һ��ָ���ʱ����ð���ָ��NULL 
	SListPrint(plist);
	SListPushBack(&plist,1);
	SListPushBack(&plist,2);
	SListPushBack(&plist,3);
	SListPushBack(&plist,4);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
//	SListPopBack(&plist);
}

void TestSList2()
{
	SListNode* plist=NULL;
	SListPushFront(&plist,1);
	SListPushFront(&plist,2);
	SListPushFront(&plist,3);
	SListPushFront(&plist,4);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
//	SListPopFront(&plist);
}

void TestSList3()
{
	SListNode* plist=NULL;
	SListPushFront(&plist,1);
	SListPushFront(&plist,2);
	SListPushFront(&plist,3);
	SListPushFront(&plist,4);
	SListPrint(plist);
	SListInsert(&plist,SListFind(plist,3),30);
	SListInsert(&plist,SListFind(plist,4),40);
	SListPrint(plist);
	SListErase(&plist,SListFind(plist,30));
	SListPrint(plist);
	SListErase(&plist,SListFind(plist,40));
	SListPrint(plist);
//	SListPopFront(&plist);
}

void TestSList4()
{
	SListNode* plist=NULL;
	SListPushFront(&plist,1);
	SListPushFront(&plist,2);
	SListPushFront(&plist,3);
	SListPushFront(&plist,4);
	SListPrint(plist);
	SListInsertAfter(&plist,SListFind(plist,3),30);
	SListInsertAfter(&plist,SListFind(plist,4),40);
	SListPrint(plist);
	SListEraseAfter(&plist,SListFind(plist,30));
	SListPrint(plist);
	SListEraseAfter(&plist,SListFind(plist,40));
	SListPrint(plist);
//	SListPopFront(&plist);
}

int main()
{
//	TestSList1();
//	TestSList2();
	TestSList3();
	TestSList4();
}
