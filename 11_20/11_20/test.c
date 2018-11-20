#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char GetMemory(char *p)
{
	char p[] = "hello world";
	return p;
}
void Test(void)
{
	char *str = NULL;
	str = GetMemory(str);
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
//	strcpy(str, "hello world");
//	printf(str);
//}


int main()
{

	/*Test();*/
	//int *ptr = malloc(100);
	//if (ptr != NULL)
	//{

	//}
	//else
	//{
	//	exit(EXIT_FAILURE);
	//}
	//ptr = realloc(ptr, 1000);
	//int *p = NULL;
	//p = realloc(ptr, 1000);
	//if (p != NULL)
	//{
	//	ptr = p;
	//}
	//free(ptr);

	system("pause");
	return 0;
}




//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int *ptr = NULL;
//	ptr = (int*)malloc(num * sizeof(int));
//	if (NULL != ptr)
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);//释放ptr所指向的动态内存空间
//	ptr = NULL;
//	system("pause");
//	return 0;
//}