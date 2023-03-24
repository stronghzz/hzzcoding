#include <stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct List* next;
};

typedef struct node ListNode;

struct List
{
	ListNode* head;
};
typedef struct List MyList;  

MyList* CreatList()
{
	MyList* ptr = (MyList*)malloc(sizeof(MyList));
	if(ptr == NULL)
	{
		printf("建表失败");
		return NULL;
	}
	ptr->head == NULL;
	return ptr;
}

void pop(int* p,int length)
{
	int temp = 0;
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - 1 - i; j++ )
		{
			if(p[j] > p[j+1])
			{
				temp = p[j+1];
				p[j+1] = p[j];
				p[j] = temp;
			}	
		}
	}
}

int main()
{
	MyList* L = CreatList();
	// int arr[5] = { 5, 2, 3, 4, 6 };
	// pop(arr,5);
	// for(int i = 0; i < 5; i++ )
	// {
	// 	printf("%d\t",arr[i]);
	// }
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = NULL;
	head->val = 0;
	ListNode** l = &head;
	printf("%d", (*l)-> val);
	printf("\n%d\n",sizeof(MyList*));
	printf("%d\n",sizeof(int*));
	printf("%d\n",35);
	printf("%c\n",10);
	printf("%c\n",97);
	printf("%c\n",32);
	printf("%c\n",357);
	printf("hello,world\n");
	//printf("%d\n",L->val);
	return 0;		
}
