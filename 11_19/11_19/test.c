#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  MyStrcmp(const char *src, const char *dst)
{
	int ret = 0;
	while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
		++src, ++dst;
	if (ret<0)
		ret = -1;
	else if (ret>0)
		ret = 1;
	return(ret);
}

int main()
{
	char str[] = "hello world";
	char str1[] = "hello new world";
	printf("%d",MyStrcmp(str, str1));
	system("pause");
	return 0;
}



////strchr
//char *MyStrchr(char *str,char c)
//{
//	while (str)
//	{
//		if (*str == c)
//		{
//			return str;
//		}
//		else
//		{
//			str++;
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	char *str = "hello world";
//	char c = 'o';
//	/*puts(strchr(str, c));*/
//	puts(MyStrchr(str, c));
//	system("pause");
//	return 0;
//}