#include <stdio.h>






int my_strcmp(const char *s1, const char *s2)//两个字符串不能被改变
{
	assert(s1&&s2);//指针不能为空
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;//如果相等继续向后比较
		s2++;
	}
	return *s1 - *s2;//返回差值
}
int my_strcmp(const char *s1, const char *s2)//两个字符串不能被改变
{
	assert(s1&&s2);//指针不能为空
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;//如果相等继续向后比较
		s2++;
	}
	return *s1 - *s2;//返回差值
}

int main()
{
	char str1[] = "hello";
	char str2[] = "world";

	my_strcmp(str1, str2);
	my_strcmp(str1, str2);
	system("pause");
	return 0;
}