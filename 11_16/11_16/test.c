#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>

//int Is_pow(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	return count == 1;
//}
//int Is_pow(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//		{
//			if (count)
//			{
//				return 0;
//			}
//			else
//			{
//				count++;
//			}
//		}
//
//	}
//	return count;
//}



//int Is_pal(int n)
//{
//	int div = 1;
//	while ((n / div) >= 10)//使div与n在同一个数量级别
//	{
//		div *= 10;
//	}
//	//判断数字是否为回文数
//	while (n > 9)
//	{
//		//判断当前最高位和最低位是否相同
//		if (n / div != n % 10)
//		{
//			return 0;
//		}
//		n %= div;
//		n /= 10;
//		div /= 100;
//	}
//	return 1;
//}
//
//int main()
//{
//	int a = 12321;
//	printf("%d",Is_pal(a));
//
//
//	system("pause");
//	return 0;
//}




//
//
//int Is_Hw(char *str)
//{
//	assert(str);
//	char *left = str;
//	char *right = str + strlen(str) - 1;
//	while(left<right)
//	{
//		if (*right != *left)
//		{
//			return 0;
//		}
//		left++;
//		right--;
//	}
//	return 1;
//}
//
//int main()
//{
//	char arr[] = "abcdcba";
//	printf("%d",Is_Hw(arr));
//	system("pause");
//	return 0;
//}



int Reverse_Integer(int x)
{
	int max = 0x7fffffff;
	int min = -max - 1;
	//防止逆转之后的整数溢出
	long long res = 0;
	while (x!=0)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}
	//判断是否溢出
	if (res > max || res < min)
	{
		return 0;
	}
	return res;

}
int main()
{
	int x = 123;
	scanf("请输入一个整数:%d\n", &x);
	printf("%d", Reverse_Integer(x));

	system("pause");
	return 0;
}