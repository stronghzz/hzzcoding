#include "Heap.h"
#include <stdio.h>

void Test()
{
	int array[] = {
		3, 9, 1, 7, 5, 8, 14, 13, 2, 6, 9
	};
	int size = sizeof(array) / sizeof(int);

	Heap heap;
	HeapCreateHeap(&heap, array, size);
	HeapInsert(&heap, 0);
	printf("%d\n", HeapTop(&heap));
	HeapPop(&heap);
	printf("%d\n", HeapTop(&heap));

	printf("½¨¶Ñ³É¹¦\n");
}



int main() {
	Test();
}