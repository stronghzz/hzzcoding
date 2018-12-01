#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;


typedef struct SList
{
	SListNode* first;
}SList;
//初始化
void SListInit(SList* list);
//链表销毁
void SListDestory(SList* list);
//增加一个节点
SListNode* BuySListNode(SLTDataType x);
//头插
void SListPushFront(SList* list, SLTDataType x);
//头删
void SListPopFront(SList* list);
//尾插
void SListPushBack(SList* list,SLTDataType data);
void SListPopBack(SList* list);
//查找
SListNode* SListFind(SList* list, SLTDataType x);
//在pos后进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
//删除pos后的节点
void SListEraseAfter(SListNode* pos);
//打印链表
void SListPrint(SList* list);
void SListRemove(SList *list, SLTDataType data);
