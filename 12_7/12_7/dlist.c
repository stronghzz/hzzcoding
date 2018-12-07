#include "dlist.h"


/**
*带头双向链表
*/

void ListInit(List* plist)
{
	ListNode* pHead = plist->_head;
	head->_next;
	head->_prev = NULL;
}
LTDataType* BuyDListNewNode(LTDataType data)
{
	ListNode* pNewNode = (LTDataType*)malloc(sizeof(LTDataType));
	pNewNode->_next = NULL;
	pNewNode->_prev = NULL;
}
void ListDestory(List* plist)
{
	//销毁有效节点

}
void ListPushBack(List* plist, LTDataType x);
void ListPushBack(List* plist);
void ListPushFront(List* plist, LTDataType x)
{
	DListNode* pNewNode = BuyDListNewNode(x);
	pNewNode->_pNext = plist->_pHead->_Next;
	pNewNode->_pPre = plist->;

	plist->pHead->pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;
}
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	DListNode* pCur = plist->_pHead->_pNext;
	while (pCur != plist->_pHead)
}
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 删除pos位置的节点
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);
void ListPrint(List* plist);