#include "SList.h"

void ListTest()
{
	SList list;
	SListInit(&list);	
	SListPrint(&list);
	SListPushFront(&list, 3);
	SListPushFront(&list, 2);
	SListPushFront(&list, 1);
	SListPrint(&list);
	//SListPopFront(&list);
	//SListPopFront(&list);
	//SListPrint(&list);
	//SListPopFront(&list);
	//SListPrint(&list);
	//SListPushBack(&list, 1);
	//SListPrint(&list);
	//SListPushBack(&list, 2);
	//SListPrint(&list);
	//SListPushBack(&list, 3);
	//SListPrint(&list);
	//SListPopBack(&list);
	//SListPrint(&list);
	//SListPopBack(&list);
	//SListPrint(&list);
	//SListPopBack(&list);
	//SListPrint(&list);
	SListNode *n3 = SListFind(&list, 3);
	SListInsertAfter(n3, 10);
	SListPrint(&list);

}






int main()
{
	ListTest();


	system("pause");
	return 0;
}



