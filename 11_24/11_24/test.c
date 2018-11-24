
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>








//char MyStrcmp(const char *str1,const char *str2)
//{
//	assert(NULL != str1 && NULL != str2);
//
//	while ('\0' != *str1 || '\0' != *str2)
//	{
//		if (*str1 > *str2)
//		{
//			return 1;
//		}
//		if (*str1 < *str2)
//		{
//			return -1;
//		}
//		str1++;
//		str2++;
//	}
//	if ('\0' == *str1 && '\0' == *str2)
//	{
//			return 0;
//	}
//}
//int main()
//{
//	char str1[] = "i love chen";
//	char str2[] = "i love chan";
//	printf("%d",MyStrcmp(str1, str2));
//	system("pause");
//	return 0;
//}




//
//char *MyStrChr(char *str1, char ch)
//{
//	assert(str1);
//	while (*str1)
//	{
//		if (*str1 == ch)
//		{
//			return str1;
//		}
//		str1++;
//	}
//	return NULL;
//}
//int main()
//{
//	char str[] = "i love chenchen";
//	char ch = 'c';
//	printf(MyStrChr(str, ch));
//	system("pause");
//	return 0;
//}





//char *MyStrstr(char *str1, char *str2)//判断str2是不是str1的子串
//{
//	assert(str1);
//	assert(str2);
//	while (*str1)
//	{
//		char *ret1 = str1;
//		char *ret2 = str2;
//		while (*ret1 == *ret2)
//		{
//			ret1++;
//			ret2++;
//		}
//		if (*ret2 == 0)
//		{
//			return str1;
//		}
//		
//		str1++;
//	}
//	return NULL;
//
//
//}
//int main()
//{
//	char str1[] = "abbcdef";
//	char str2[] = "bcd";
//	printf("%s",MyStrstr(str1, str2));
//	system("pause");
//	return 0;
//}
//



//char *Strcat(char *str1, char *str2)
//{
//	assert(str1);
//	assert(str2);
//	char *ret = str1;
//	while (*str1)
//	{
//		str1++;
//	}
//	while (*str1++ = *str2++);
//	return ret;
//}
//int main()
//{
//	char str1[50] = "I love chen";
//	char str2[20] = "chen love me";
//	printf("%s", Strcat(str1, str2));
//	system("pause");
//	return 0;
//}
//int main()
//{
//	
//
//
//	system("pause");
//
//	return 0;
//}