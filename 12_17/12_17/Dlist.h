#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DLDataType;
typedef struct DListNode
{
	DLDataType val;
	struct DListNode *next;
	struct DListNode *prev;
}DListNode;
typedef struct
{
	DListNode *head;
}DList;
void DListInit(DList *dlist);
void DListClear(DList *dlist);
void DListDestory(DList *dlist);
DListNode *BuyDListNode(DLDataType val);
void DListPushBack(DList *dlist, DLDataType val);
void DListPopBack(DList *dlist);
void DListPushFront(DList *dlist, DLDataType val);
void DListPopFront(DList *dlist);
DListNode *DListFind(DList *dlist, DLDataType val);
