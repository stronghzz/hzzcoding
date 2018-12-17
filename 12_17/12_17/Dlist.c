#include "Dlist.h"





DListNode *BuyDListNode(DLDataType val)
{
	DListNode *node = (DListNode *)malloc(sizeof(DListNode));
	assert(node);
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void DListInit(DList *dlist)
{
	assert(dlist);
	DListNode *head = BuyDListNode(0);
	head->next = head;
	head->prev = head;
	dlist->head = head;
}
void DListClear(DList *dlist)
{
	assert(dlist);
	DListNode *cur, *next;
	for (cur = dlist->head->next; cur != dlist->head; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	dlist->head->next = dlist->head;
	dlist->head->prev = dlist->head;
}
void DListDestory(DList *dlist)
{
	assert(dlist);
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}
void DListPushBack(DList *dlist, DLDataType val)
{
	assert(dlist);
	DListNode *node = BuyDListNode(val);
	node->next = dlist->head;
	node->prev = dlist->head->prev;
	dlist->head->prev->next = node;
	dlist->head->prev = node;
}
void DListPopBack(DList *dlist)
{
	assert(dlist);
	DListNode *cur = dlist->head->prev;
	cur->prev->next = dlist->head;
	dlist->head->prev = cur->prev;
	free(cur);
}
DListNode *DListFind(DList *dlist, DLDataType val)
{
	for (DListNode *cur = dlist->head->next; cur != dlist->head; cur = cur->next) {
		if (cur->val == val) {
			return cur;
		}
	}

	return NULL;
}