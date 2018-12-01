#include "SList.h"


void SListInit(SList* list)
{
	assert(list);
	list->first = NULL;
}
void SListDestory(SList* list)
{

}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}
void SListPushFront(SList* list, SLTDataType x)
{
	assert(list);
	SListNode* node = BuySListNode(x);
	node->next = list->first;
	list->first = node;
}
void SListPopFront(SList* list)
{
	assert(list);
	assert(list->first);
	SListNode* oldfirst = list->first;
	list->first = list->first->next;
	free(oldfirst);
}
void SListPushBack(SList* list,SLTDataType data)
{
	assert(list);
	if (list->first == NULL)
	{
		// 1 个
		SListPushFront(list,data);
		return;
	}
	SListNode *lastone = list->first;
	while (lastone->next)
	{
		lastone = lastone->next;
	}
	SListNode* node = BuySListNode(data);
	lastone->next = node;
	
}
void SListPopBack(SList* list)
{
	assert(list);
	assert(list->first);
	if (list->first->next == NULL)
	{
		SListPopFront(list);
		return;
	}
	SListNode *cur;
	for (cur = list->first; cur->next->next != NULL; cur = cur->next)
	{
	}
	free(cur->next);
	cur->next = NULL;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* node = BuySListNode(x);
	SListNode* cur = pos->next;
	pos->next = node;
	node->next = cur;
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);
	SListNode* cur = pos->next->next;
	free(pos->next);
	pos->next = cur;
}
void SListPrint(SList* list)
{
	
	//while (list->first !=NULL)
	//{
	//	printf("%d--->", list->first->data);
	//	list->first = list->first->next;
	//}
	//if (list->first == NULL)
	//{
	//	printf("NULL\n");
	//}
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		printf("%d --> ", cur->data);
	}
	printf("NULL\n");
}
void SListRemove(SList *list, SLTDataType data)
{
	// 重点是找到 data 这个结点的前一个结点
	// previous	prev

	SListNode *prev = NULL;
	SListNode *cur = list->first;

	while (cur != NULL && cur->data != data) {
		prev = cur;
		cur = cur->next;
	}

	// cur == NULL 表示没找到
	// cur != NULL && prev != NULL
	// cur 就是要删的结点，同时 prev 就是要删的前一个结点
	// cur != NULL && prev == NULL 头删
	if (cur == NULL) {
		return;
	}

	if (prev == NULL) {
		SListPopFront(list);
		return;
	}

	prev->next = cur->next;
	free(cur);
}