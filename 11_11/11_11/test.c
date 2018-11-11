#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>  
#include <stdio.h>
#include <windows.h>
int cmp(const void*n1, const void*n2)      //判断n1,n2元素大小，n1比n2大返回正数；小返回负数，相同返回0  
{
	return *(char*)n1 - *(char*)n2;        //升序  
}

void Swap(char *buf1, char* buf2, int width)  //交换每个字节  
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void *base, int sz, int width, int(*cmp)(const void* n1, const void*n2))   //模拟实现qsort  
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			int ret = cmp(((char*)base + (j*width)), ((char*)base + (j + 1)*width));
			if (ret>0)
			{
				Swap(((char*)base + (j*width)), ((char*)base + (j + 1)*width), width);
			}
		}
	}
}

int main()
{
	int arr[] = { 5, 4, 3, 2, 1 };
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp);
	int i = 0;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	char arr1[] = { 'z', 'l', 's', 'x', 'm' };
	bubble_sort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), cmp);
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		printf("%c ", arr1[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}