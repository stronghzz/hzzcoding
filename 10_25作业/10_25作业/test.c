#define    _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
//
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	printf("%d\n", b + ((a - b) >> 1));
//	system("pause");
//	return 0;
//}
unsigned int reverse_bit(unsigned int value)
{
	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int i = 32;

	for (i = 32; i > 0; i--)
	{
		b = 1 & value;
		
		value = value >> 1;
		b = b <<( i - 1);
		a += b;
	}
	return a;
}
int main()
{
	int value = 0;
	scanf("%d", &value);
	printf("%u",reverse_bit(value));
	system("pause");
	return 0;
}