#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <stdlib.h>

void yhtp(int k)
{
	//定义一个二维数组；
	int arr[100][100] = { 0 };
	int i = 0;
	int j = 0;
	//将数组的第一列全部赋为1，对角线上也全部赋为1；
	for (i = 0; i<k; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	//从第三行第二列开始赋值，
	for (i = 2; i<k; i++)
	{
		for (j = 1; j<k; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	//打印格式；
	for (i = 0; i<k; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%3d", arr[i][j]);
		}
		putchar('\n');
	}
}
int main()
{
	int n = 0;
	printf("请输入n的值:>");
	scanf("%d", &n);
	yhtp(n);

	system("pause");
	return 0;
}
