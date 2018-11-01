#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
int main()
{
	unsigned int m = 0;
	unsigned int n = 0;
	int a = 0;
	int b = 0;
	int count = 0;
	scanf("%d%d", &m, &n);
	while (m&&n >= 0)
	{
		a = m & 1;
		m = m >> 1;
		b = n & 1;
		n = n >> 1;
		if (a != b)
		{
			count++;
		}
	}
	printf("%d", count);//011111001111  
	system("pause");    //100011111011
	return 0;
}
//int main()
//{
//	int a = 0 ;
//	int b = 0;
//	int i = 0;
//	scanf("%d", &a);
//	while (a !=0)
//	{
//		b = a % 10;
//		printf("%d ", b);
//		a = a / 10;
//	}
//	
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int odd = 0;
//	int even = 0;
//	int value = 0;
//	scanf("%d", &value);
//	while (value != 0)
//	{
//		odd = odd*10 + (value & 1);
//		value = value >> 1;
//		even = even*10 +(value & 1);
//		value = value >> 1;
//	}
//	printf("奇数=%d ,偶数=%d", odd, even);
//	system("pause");
//	return 0;
//}
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	while (value != 0)
//	{
//		if ((value & 1) == 1)
//		{
//			count++;
//		}
//		value = value >> 1;
//	}
//	return count;// 返回 1的位数 
//}
//
//int main()
//{
//	unsigned int value = 0;
//	scanf("%d", &value);
//	int ret = count_one_bits(value);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}