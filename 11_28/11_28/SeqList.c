#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


void SeqListInit(SeqList *sl, size_t capacity)
{
	assert(sl != NULL);

	// 给容量赋值 为 capacity
	// 给size赋值为 0
	// 给array 开辟空间（堆上），空间大小为 capacity

	sl->capacity = capacity;
	sl->size = 0;
	sl->array = (SLDataType *)malloc(capacity * sizeof(SLDataType));
	// 没有做错误检查
	assert(sl->array != NULL);
}

void SeqListDestroy(SeqList *sl)
{
	assert(sl != NULL);
	// 推荐按进门的顺序出门

	free(sl->array);
	sl->array = NULL;	// 防御性代码
	sl->capacity = sl->size = 0;
}

// 平均 O(1)
void SeqListPushBack(SeqList *sl, SLDataType data)
{
	assert(sl != NULL);

	CheckCapacity(sl);	// 封装的思想

	sl->array[sl->size] = data;
	sl->size++;
}

// O(n)
void SeqListPushFront(SeqList *sl, SLDataType data)
{
	SeqListInsert(sl, 0, data);

#if 0
	assert(sl != NULL);

	CheckCapacity(sl);	// 封装的思想

						// 从尾到头进行数据搬移
						// i 的含义是空间的下标
	int i;
	for (i = sl->size; i >= 1; i--) {
		sl->array[i] = sl->array[i - 1];
	}

	sl->array[0] = data;
	sl->size++;
#endif
}


// O(1)
void SeqListPopBack(SeqList *sl)
{
	assert(sl);
	assert(sl->size > 0);

	sl->size--;
}


// O(n)
void SeqListPopFront(SeqList *sl)
{
	assert(sl);
	assert(sl->size > 0);

	// i 数据所在的下标
	for (int i = 1; i < sl->size; i++) {	// 1. 区间范围错误
		sl->array[i - 1] = sl->array[i];	// 2. i 的含义变了
	}

	sl->size--;
}

void SeqListPrint(SeqList *sl)
{
	for (int i = 0; i < sl->size; i++) {
		printf("%d ", sl->array[i]);
	}

	printf("\n");
}

void CheckCapacity(SeqList *sl)
{
	// size 和 capacity
	// 等于需不需要扩容
	if (sl->size < sl->capacity) {
		return;
	}

	// 1. 申请新空间
	int newCapacity = sl->capacity * 2;
	SLDataType *newArray = (SLDataType *)malloc(
		sizeof(SLDataType)* newCapacity);
	assert(newArray);
	// 2. 搬家
	for (int i = 0; i < sl->size; i++) {
		newArray[i] = sl->array[i];
	}

	// 3. 释放老的
	free(sl->array);		// 内存泄漏
							// 4. 保存新的
	sl->array = newArray;

	sl->capacity = newCapacity;
}

int SeqListFind(SeqList *sl, SLDataType data) {
	for (int i = 0; i < sl->size; i++) {
		if (sl->array[i] == data) {
			return i;
		}
	}

	// 没有找到
	return -1;
}

void SeqListInsert(SeqList *sl, size_t pos, SLDataType data)
{
	assert(sl);
	CheckCapacity(sl);

	// pos 有效范围 [0, size]
	assert(pos >= 0 && (int)pos <= sl->size);

	// i 表示的是数据下标
	for (int i = sl->size - 1; i >= (int)pos; i--) {
		sl->array[i + 1] = sl->array[i];
	}

	sl->array[pos] = data;
	sl->size++;
}

void SeqListErase(SeqList *sl, size_t pos)
{
	assert(sl);
	assert(sl->size > 0);
	assert(pos >= 0 && (int)pos < sl->size);

	// i 表示的是数据下标
	for (int i = pos + 1; i < sl->size; i++) {
		sl->array[i - 1] = sl->array[i];
	}
	sl->size--;
}

void SeqListRemove(SeqList *sl, SLDataType data)
{
	assert(sl != NULL);
	int pos = SeqListFind(sl, data);
	if (pos != -1) {
		SeqListErase(sl, pos);
	}
}

void SeqListModify(SeqList *sl, size_t pos, SLDataType data)
{
	assert(sl != NULL);
	assert(pos >= 0 && (int)pos < sl->size);

	sl->array[pos] = data;
}

// 3 个作用
static void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void SeqListBubbleSort(SeqList *sl)
{
	assert(sl);

	// i 计数器，从 0 开始
	for (int i = 0; i < sl->size - 1; i++) {

		int isSort = 1;

		// 表示要比较的两个数是 [j], [j+1]; j 是下标
		for (int j = 0; j <= sl->size - 2 - i; j++) {
			if (sl->array[j] > sl->array[j + 1]) {
				Swap(sl->array + j, sl->array + j + 1);
				isSort = 0;	// 一旦发生交换
			}
		}

		if (isSort == 1) {
			return;
		}
	}
}


int SeqListBinarySearch(SeqList *sl, SLDataType data)
{
	// 数据和下标不能弄混
	// left, right	代表下标
	// [left, right)
	int left = 0;
	int right = sl->size;

	// 只有 0 个数不需要找
	while (left < right) {
		// mid 也是下标
		int mid = left + (right - left) / 2;

		if (data == sl->array[mid]) {
			return mid;
		}
		else if (data < sl->array[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}

// 删除所有遇到的 data
// 5 5 5 5 1 1 1 1	删掉 1
void SeqListRemoveAll(SeqList *sl, SLDataType data)
{
#if 0	// 时间复杂度 O(n^2)
	int pos;
	while ((pos = SeqListFind(sl, data)) != -1) {	// O(n)
		SeqListErase(sl, pos);	// O(n)
	}
#endif

#if 0	// 时间复杂度 O(n)，空间复杂度 O(n)
	SLDataType *tempArray = (SLDataType *)malloc(
		sizeof(SLDataType)* sl->size);
	assert(tempArray);
	int j = 0;

	for (int i = 0; i < sl->size; i++) {
		if (sl->array[i] != data) {
			tempArray[j++] = sl->array[i];
		}
	}

	for (int k = 0; k < j; j++) {
		sl->array[k] = tempArray[k];
	}

	sl->size = j;
#endif

	int j = 0;
	for (int i = 0; i < sl->size; i++) {
		if (sl->array[i] != data) {
			sl->array[j++] = sl->array[i];
		}
	}

	sl->size = j;
}


void BubbleSort(SLDataType array[], int size)
{
	// i 计数器，从 0 开始
	for (int i = 0; i < size - 1; i++) {

		int isSort = 1;

		// 表示要比较的两个数是 [j], [j+1]; j 是下标
		for (int j = 0; j <= size - 2 - i; j++) {
			if (array[j] > array[j + 1]) {
				Swap(array + j, array + j + 1);
				isSort = 0;	// 一旦发生交换
			}
		}

		if (isSort == 1) {
			return;
		}
	}
}

void SeqListBubbleSort1(SeqList *sl)
{
	assert(sl != NULL);

	BubbleSort(sl->array, sl->size);
}

void SeqListBubbleSort2(SeqList *sl)
{
	assert(sl != NULL);

	// i 计数器，从 0 开始
	for (int i = 0; i < sl->size - 1; i++) {

		int isSort = 1;

		// 表示要比较的两个数是 [j], [j+1]; j 是下标
		for (int j = 0; j <= sl->size - 2 - i; j++) {
			if (sl->array[j] > sl->array[j + 1]) {
				Swap(sl->array + j, sl->array + j + 1);
				isSort = 0;	// 一旦发生交换
			}
		}

		if (isSort == 1) {
			return;
		}
	}
}