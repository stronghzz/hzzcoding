#pragma once
// Sequence List

#include <stddef.h>

typedef int SLDataType;

struct SeqList {
	SLDataType *array;	// 指针，指向存放数据的空间，真正的空间在堆上
	int capacity;		// 顺序表整体的容量
	int size;			// 顺序表中真正有效的个数
						// 初始值为 0，同时也表示下一个有效位置的下标
};

typedef struct SeqList	SeqList;

// 封装的接口

// 初始化/销毁
void SeqListInit(SeqList *sl, size_t capacity);
void SeqListDestroy(SeqList *sl);

// 增删查改
// 尾插，插入在顺序表的尾部
void SeqListPushBack(SeqList *sl, SLDataType data);

// 头插，插入在顺序表的头部 ([0])
void SeqListPushFront(SeqList *sl, SLDataType data);

// 尾删，删除顺序表尾部的数据
void SeqListPopBack(SeqList *sl);

// 头删，删除顺序表头部的数据
void SeqListPopFront(SeqList *sl);

// 在 pos 所在的下标做数据插入
void SeqListInsert(SeqList *sl, size_t pos, SLDataType data);

// 删除 pos 所在的下标数据
void SeqListErase(SeqList *sl, size_t pos);

// 查找
// 找从 0 开始的第一个，如果知道了，返回数据所在的下标
// 如果没找到返回 -1
int SeqListFind(SeqList *sl, SLDataType data);

// 删除第一个遇到的 data
void SeqListRemove(SeqList *sl, SLDataType data);

// 删除所有遇到的 data
void SeqListRemoveAll(SeqList *sl, SLDataType data);

// 修改，pos 所在的下标
void SeqListModify(SeqList *sl, size_t pos, SLDataType data);


// 打印
void SeqListPrint(SeqList *sl);

// 内部接口
void CheckCapacity(SeqList *sl);

// 冒泡排序
void SeqListBubbleSort(SeqList *sl);

// 二分查找（前提是数据有序）
// 如果找到，返回数据所在下标，如果没找到，返回 -1
int SeqListBinarySearch(SeqList *sl, SLDataType data);