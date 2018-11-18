#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *my_strstr(char *str1, char *str2)
{
	int size = strlen(str2);
	char *temp = NULL;
	while (1)
	{
		int i = 0;
		int count = 0;
		if ( *str1 == *str2 )
		{
			temp = str1 + i;
			for (i = 0; i < size; i++)
			{
				if (*(str1 + i) == *(str2 + i))
				{
					count++;
				}
			}
		}
		else
		{
			str1++;
		}

		
		if (count == size)
		{
			return temp;
		}

	}

}
int main()
{
	char str1[] = "abcdef";
	char str2[] = "def";
	char *p = my_strstr(str1, str2);//在str1中查找str2，并返回首地址
	puts(p);
	//char *p = strstr(str, str1);
	//puts(p);

	system("pause");
	return 0;
}
//int main()
//{
//	char str[] = "This is a simple string";
//	char * pch;
//	pch = strstr(str, "simple");
//	strncpy(pch, "sample", 6);
//	puts(str);
//	system("pause");
//	return 0;
//}

