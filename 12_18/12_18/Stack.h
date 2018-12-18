#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;
#define MAX_LEN 10;
typedef struct Stack
{
	STDataType arr[MAX_LEN];
	STDataType top;
}Stack;
void StackInit(Stack *stack)
{
	stack->top = 0;
}
void StackDestroy(Stack *stack)
{
	stack->top = 0;
}
void StackPush(Stack *stack, STDataType val)
{
	assert(stack);
	assert(stack->top < MAX_LEN);
	stack->arr[stack->top] = val;
	stack->top++;
}
void StackPop(Stack *stack, STDataType val)
{
	assert(stack);
	assert(stack->top > 0);
	stack->top--;
}
//·µ»ØÕ»¶¥ÔªËØ
STDataType StackTop(Stack *stack)
{
	assert(stack);
	assert(stack->top > 0);
	return stack->arr[stack->top - 1];
}
int StackEmpty(const Stack *stack)
{
	return stack->top == 0 ? 1 : 0;
}
int StackSize(const Stack *stack)
{
	return stack->top;
}