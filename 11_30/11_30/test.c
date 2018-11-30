#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int SLTDataType;


typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head->_data = 0;
	plist->_head->_next = NULL;
}
void SListDestory(SList* plist)
{
	assert(plist);
	plist->_head = NULL;

}
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->_data = x;
	node->_next = plist->_head;
	plist->_head = node;

}
void SListPopFront(SList* plist)
{
	assert(plist);
	plist->_head = plist->_head->_next;

}

int main()
{

	return 0;
}