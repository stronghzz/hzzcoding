#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0


typedef struct
{
	int* elem;
	int length;
	int listsize;
}Sqlist;


int InitList(SqList* L); //��ʼ��
int ListInsert(SqList* L, int i, int e);//����
int ListDelete(SqList* L, int i, int* e);//ɾ��
void ListPrint(SqList L);//�����ӡ
void DeleteMin(SqList* L);//ɾ����С

int InitList(Sqlist* L)
{
	L->elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L->elem)
	{
		return ERROR;
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

int ListInsert(Sqlist* L, int i, int e)
{
	int j;
	int* newbase;
	if (i < 1 || i > L->length + 1)
	{
		return ERROR;
	}
	if (L->length >= L->listsize)
	{
		newbase = (int*)realloc(L->elem,(L->listsize+LISTINCREMENT))
	}
}


//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a = 5;
//	int b = a;
//	cout << &a << endl;
//	cout << &b << endl;
//	return 0;
//}