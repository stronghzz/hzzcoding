#pragma once
#define MAX_SIZE 10 
#include <stdio.h>

typedef int DataType;
typedef struct SeqList
{
	DataType _array[MAX_SIZE];
	int _size; // 表示顺序表中有效元素的个数 
}SeqList, *PSeqList;



//初始化
void SeqListInit(PSeqList ps)
{
	ps->_size = 0;

}//有效值为零

 //尾插
void SeqListPushBack(PSeqList ps, DataType data)
{
	if (NULL == ps)
	{
		return;
	}
	if (ps->_size == MAX_SIZE)
	{
		printf("装满了，不能插了");
		return;
	}
	ps->_array[ps->_size] = data;
	ps->_size++;
}
//尾删
void SeqListPopBack(PSeqList ps)
{
	if (NULL == ps)
	{
		return;
	}
	if (0 == ps->_size)
	{
		printf("删完了，不需要删了");
		return;
	}
	ps->_size--;
}
//头插
void SeqListPushFront(PSeqList ps, DataType data)
{
	if (NULL == ps)
	{
		return;
	}
	if (ps->_size == MAX_SIZE)
	{
		printf("装满了");
		return;
	}
	DataType i = ps->_size;
	for (i; i >0; i--)
	{
		ps->_array[i] = ps->_array[i-1];
	}
	ps->_array[i] = data;
	ps->_size++;
}
//头删
void SeqListPopFront(PSeqList ps)
{
	if (NULL == ps)
	{
		return;
	}
	if (ps->_size == 0)
	{
		printf("没东西了，不需要删了");
		return;
	}
	DataType i = 0;

	for (i; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}
//pos位置插入元素
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	if (ps == NULL || !(pos <= 0 && pos >= ps->_size))
	{
		return;
	}
	if (ps->_size == MAX_SIZE)
	{
		printf("满了，装不下了\n");
		return;
	}
	DataType i = ps->_size;


	for (i; i >= pos; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = data;
	ps->_size++;

}
//删除pos位置元素
void SeqListErase(PSeqList ps, int pos)
{
	if (ps == NULL || !(pos >= 0 && pos <= ps->_size))
	{
		return;
	}
	if (0 == ps->_size)
	{
		printf("顺序表已空");
		return;
	}
	DataType i = pos;
	for (i; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}
//移除顺序表中第一个值为data的元素
void Remove(PSeqList ps, DataType data)
{
	if (ps == NULL)
	{
		return;
	}
	DataType i = 0;
	for (i; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			DataType j = i;
			for (j; j < ps->_size; j++)
			{
				ps->_array[j] = ps->_array[j + 1];
			}
			ps->_size--;
			return;
		}
	}
}
// 移除顺序表中所有值为data的元素 
void RemoveAll(PSeqList ps, DataType data)
{
	if (ps == NULL)
	{
		return;
	}
	DataType i = 0;
	for (i; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			DataType j = i;
			for (j; j < ps->_size; j++)
			{
				ps->_array[j] = ps->_array[j + 1];
			}
			ps->_size--;

		}
	}

}
// 在顺序表中查找值为data的元素，找到返回该元素在顺序表中的位置，否则返回-1 
int SeqListFind(PSeqList ps, DataType data)
{
	if (ps == NULL)
	{
		return 0;
	}
	DataType i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			return i;
		}
	}
	return -1;
}
// 获取顺序表中元素的个数 
int SeqListSize(PSeqList ps)
{
	if (ps == NULL)
	{
		return 0;
	}
	DataType i = 0;

}
void TestSeqListInsertorErase()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	printf("size = %d\n", SeqListSize(&s));

}


