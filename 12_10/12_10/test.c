#include "DList.h"

void TestDList1() {
	DList dlist;

	DListInit(&dlist);

	DListPushFront(&dlist, 3);
	DListPushFront(&dlist, 2);
	DListPushFront(&dlist, 1);
	// 1 -> 2 -> 3

	DListPushBack(&dlist, 14);
	DListPushBack(&dlist, 15);
	DListPushBack(&dlist, 16);
	// 1 -> 2 -> 3 -> 14 -> 15 -> 16

	DListNode *pos = DListFind(&dlist, 14);
	DListInsert(pos, 107);
	// 1 -> 2 -> 3 -> 107 -> 14 -> 15 -> 16


	DListErase(pos);
	DListPrintByDList(&dlist);
	// 1 -> 2 -> 3 -> 107 -> 15 -> 16

	DListPopFront(&dlist);
	DListPrintByDList(&dlist);
	// 2 -> 3 -> 107 -> 15 -> 16

	DListPopBack(&dlist);
	DListPrintByDList(&dlist);
	// 2 -> 3 -> 107 -> 15

	DListDestroy(&dlist);
}

int main() {
	TestDList1();
}