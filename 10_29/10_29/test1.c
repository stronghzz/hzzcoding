#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <windows.h>
int m_strlen(char* str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

void reverse_str(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void reverse(char *str)
{
	char *start = str;
	char *end = str + m_strlen(str) - 1;
	//子串的起始指针
	char *cur_start = str;
	//整体逆转一遍
	reverse_str(start, end);
		//局部子串逆转
	while (*cur_start)
	{
			
		char *start = cur_start;
			
		while ((*cur_start != ' ') && (*cur_start != '\0'))
		{
			cur_start++;
		}
			//逆转子串
		reverse_str(start, cur_start - 1);
		if (*cur_start == ' ')
		{
			cur_start++;
		}
	}

}
int main()
{
	char str[] = "student a am i";
	printf("%s\n", str);
	reverse(str);
	printf("%s\n", str);
	system("pause");
	return 0;

}





int find(int a[],int len)
{
	int ret = 0;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		ret ^= a[i];
	}
	return ret;
}
int main()
{
	int a[] = { 1,2,2,3,3,1,5 };
	int len = 0;
	len = sizeof(a) / sizeof(a[0]);
	printf("%d",find(a, len));
	system("pause");
	return 0;
}
int average(int a, int b)
{
	return (a & b) + (a ^ b) >> 1;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	printf("%d", average(a, b));
	system("pause");
	return 0;
}

unsigned int reverse_bit(unsigned int value)
{
	unsigned int sum = 0;
	int i = 0;

	for (i = 0; i<32; i++)
	{
		sum += ((value >> i) & 1) * pow(2, 31 - i);
		//ret <<= 1;
		////当前的值与ret或运算
		////ret最后一位保存当前位的值
		//ret |= (value >> i) & 1;
	}
	return sum;
}
int main()
{
	unsigned int value = 0;
	scanf("%d", &value);
	printf("%u",reverse_bit(value));
	system("pause");
	return 0;
}