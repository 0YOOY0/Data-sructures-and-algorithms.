#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int SLData;

typedef struct Stack
{
	SLData* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps)
{
	ps->a=NULL;
	ps->top=ps->capacity=0;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a=NULL;
	ps->capacity=ps->top=0;
}

void CheckCapacity(Stack** pps)
{
	assert(*pps);
	int newcapacity=(*pps)->capacity==0?4:((*pps)->capacity)*2;
	SLData* tmp=realloc((*pps)->a,sizeof(SLData)*newcapacity);
	if(tmp==NULL)
	{
		printf("Realloc Failed!\n");
		exit(-1);
	}
	(*pps)->capacity=newcapacity;
	(*pps)->a=tmp;
}

void StackPush(Stack* ps,SLData x)
{
	assert(ps);
	if(ps->capacity==ps->top)
	CheckCapacity(&ps);
	ps->a[ps->top]=x;
	ps->top++;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top==0;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

SLData StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top-1];
}

void StackTest1()
{
	Stack stack;
	StackInit(&stack);
	StackPush(&stack,1);
	StackPush(&stack,2);
	StackPush(&stack,3);
	StackPush(&stack,4);
	StackPush(&stack,5);
	StackPop(&stack);
	StackPop(&stack);
	StackPop(&stack);
	int top=StackTop(&stack);
	printf("%d\n",top);
	StackPop(&stack);
	StackEmpty(&stack);
	StackPop(&stack);
	StackEmpty(&stack);
	StackDestroy(&stack);
	
} 

int main()
{
	StackTest1();
}
