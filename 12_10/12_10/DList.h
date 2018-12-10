#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 数据类型
typedef int DLDataType;

// 结点类型
typedef struct DListNode {
	DLDataType val;
	struct DListNode *next;	// 后继结点
	struct DListNode *prev;	// 前驱结点
}	DListNode;

// 双向链表类型
typedef struct {
	DListNode *head;		// 指向头结点
}	DList;

// 内部接口
DListNode * BuyNode(DLDataType val) {
	DListNode *node = (DListNode *)malloc(sizeof(DListNode));
	assert(node);
	node->val = val;
	node->next = node->prev = NULL;

	return node;
}

// 接口
// 初始化/销毁
void DListInit(DList * dlist) {
	// 创建头结点
	DListNode *head = BuyNode(0); // 头结点中的 val 没有实际意义
								  // 通常会存链表的长度
								  // 我这里没存
	head->next = head;
	head->prev = head;

	// 将头结点放置到链表中
	dlist->head = head;
}

// 清空
void DListClear(DList *dlist) {
	DListNode *cur, *next;

	// 和单链表有区别
	for (cur = dlist->head->next; cur != dlist->head; cur = next) {
		next = cur->next;
		free(cur);
	}

	dlist->head->next = dlist->head;
	dlist->head->prev = dlist->head;
}

// 销毁
// 头结点都没有了，是个无效链表
void DListDestroy(DList *dlist) {
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}


// 增删改查
// 在 pos 结点前面做插入
void DListInsert(DListNode *pos, DLDataType val) {
	// 申请结点
	DListNode *node = BuyNode(val);

	node->next = pos;
	node->prev = pos->prev;
	pos->prev->next = node;
	pos->prev = node;
}


// 头插
void DListPushFront(DList *dlist, DLDataType val) {
	DListInsert(dlist->head->next, val);
#if 0
	// 申请结点
	DListNode *node = BuyNode(val);

	// 处理 next / prev
	// 有 4 个指针
	node->prev = dlist->head;
	node->next = dlist->head->next;
	dlist->head->next->prev = node;
	dlist->head->next = node;
#endif
}

// 尾插
void DListPushBack(DList *dlist, DLDataType val) {
	DListInsert(dlist->head, val);
#if 0
	// 申请结点
	DListNode *node = BuyNode(val);

	node->prev = dlist->head->prev;
	node->next = dlist->head;
	dlist->head->prev->next = node;
	dlist->head->prev = node;
#endif
}

// 打印
void DListPrintByHead(DListNode *head) {
	for (DListNode *cur = head->next; cur != head; cur = cur->next) {
		printf("%d --> ", cur->val);
	}
	printf("\n");
}

void DListPrintByDList(DList *dlist) {
	DListPrintByHead(dlist->head);
}

// 查找
// 找到第一个 val 的结点，返回结点地址
// 如果没找到，返回 NULL
DListNode * DListFind(DList *dlist, DLDataType val) {
	for (DListNode *cur = dlist->head->next; cur != dlist->head; cur = cur->next) {
		if (cur->val == val) {
			return cur;
		}
	}

	return NULL;
}

// 删除 pos 结点，pos 不是头结点
void DListErase(DListNode *pos) {
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

void DListPopFront(DList *dlist) {
	assert(dlist->head->next != dlist->head);	// 链表不为空
	DListErase(dlist->head->next);
}

void DListPopBack(DList *dlist) {
	assert(dlist->head->next != dlist->head);	// 链表不为空
	DListErase(dlist->head->prev);
}