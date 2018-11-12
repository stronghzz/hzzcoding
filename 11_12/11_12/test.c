#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <string.h>


char *GetMemory(void)
{
	char p[] = "hello world";
	return p;
}
void Test(void)
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}


//void GetMemory(char *p)
//{
//	p = (char *)malloc(100);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	str = (char *)malloc(100);
//	strcpy(str, "hello world");
//	printf(str);
//}
int main()
{
	
	Test();

	//int *p = calloc(10, sizeof(int));
	//if (p != NULL)
	//{
	//	//使用空间
	//}
	//free(p);
	//p = NULL;
	


	//int num = 0;
	//scanf("%d", &num);
	//int *ptr = NULL;
	//ptr = (int*)malloc(num * sizeof(int));
	//if (NULL != ptr)//判断ptr指针是否为空
	//{
	//	int i = 0;
	//	for (i = 0; i < num; i++)
	//	{
	//		*(ptr + i) = 0;
	//	}
	//}
	//free(ptr);//释放ptr所指向的动态内存
	//ptr = NULL;
	//


	system("pause");
	return 0;
}