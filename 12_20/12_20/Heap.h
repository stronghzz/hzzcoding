#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void AdjustDown(int array[], int size, int root)
{
	while (1) {
		int left = 2 * root + 1;
		int right = 2 * root + 2;
		int min;

		if (left >= size) {
			return;
		}
		if (right < size && array[right] < array[left]) {
			min = right;
		}
		else {
			min = left;
		}

		if (array[root] <= array[min]) {
			return;
		}

		int t = array[root];
		array[root] = array[min];
		array[min] = t;

		//AdjustDown(array, size, min);
		root = min;
	}
}

void CreateHeap(int array[], int size)
{
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
	heap->capacity = size * 2;
	heap->size = size;
	heap->array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		heap->array[i] = array[i];
	}

	CreateHeap(heap->array, heap->size);
}
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
void HeapInsert(Heap *heap, int val) {
	heap->array[heap->size] = val;
	heap->size++;

	AdjustUp(heap->array, heap->size, heap->size - 1);
}
void HeapPop(Heap *heap) {
	assert(heap->size > 0);

	heap->array[0] = heap->array[heap->size - 1];
	heap->size--;

	AdjustDown(heap->array, heap->size, 0);
}
HPDataType HeapTop(Heap *heap) {
	assert(heap->size > 0);

	return heap->array[0];
}