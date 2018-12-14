#pragma once

#include <stdlib.h>
#include <assert.h>


// array[size] 表示数组及大小
// root 表示要调整的结点的下标
// 前提是 [root] 所在的结点左右子树已经满足堆的性质了
void AdjustDown(int array[], int size, int root)
{
	while (1) {
		int left = 2 * root + 1;
		int right = 2 * root + 2;
		int min;

		if (left >= size) {
			// 越界
			return;
		}

		// 确定哪个是最小的孩子
		if (right < size && array[right] < array[left]) {
			min = right;
		}
		else {
			min = left;
		}

		if (array[root] <= array[min]) {
			return;
		}

		// 交换值
		int t = array[root];
		array[root] = array[min];
		array[min] = t;

		//AdjustDown(array, size, min);
		root = min;
	}
}

// 建堆
// O(n * logN)	--> O(n)
void CreateHeap(int array[], int size)
{
	// 从最后一个非叶子结点开始，调整到 0 结束
	// 最后一个非叶子结点就是最后一个结点的双亲结点
	for (int i = (size - 2) / 2; i >= 0; i--) {
		AdjustDown(array, size, i);	// O(log(n))
	}
}


typedef int	HPDataType;

typedef struct Heap {
	HPDataType	*array;
	int			size;
	int			capacity;
}	Heap;


void HeapCreateHeap(Heap *heap, int array[], int size)
{
	// 暂时不考虑扩容问题
	heap->capacity = size * 2;
	heap->size = size;
	heap->array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		heap->array[i] = array[i];
	}

	CreateHeap(heap->array, heap->size);
}

// 小堆
void AdjustUp(int array[], int size, int child)
{
	while (child != 0) {
		int parent = (child - 1) / 2;
		if (array[child] >= array[parent]) {
			return;
		}

		int t = array[parent];
		array[parent] = array[child];
		array[child] = t;

		child = parent;
	}
}

// 增加
void HeapInsert(Heap *heap, int val) {
	heap->array[heap->size] = val;
	heap->size++;

	AdjustUp(heap->array, heap->size, heap->size - 1);
}

// 删除（只能删除堆顶元素）
// O(Log(n))
void HeapPop(Heap *heap) {
	assert(heap->size > 0);

	heap->array[0] = heap->array[heap->size - 1];
	heap->size--;

	AdjustDown(heap->array, heap->size, 0);
}

// 返回堆顶元素，返回最值
HPDataType HeapTop(Heap *heap) {
	assert(heap->size > 0);

	return heap->array[0];
}