#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

int  Is_Leftshift_string(char *str1, char *str2)
{
	assert(str1);
	assert(str2);
	int len = strlen(str1);

	int i = 0;
	int j = 0;
	for (i = 0; i<len-1; i++)
	{
		char tmp = *str1;
		for (j = 0; j < len - 1; j++)
		{
			str1[j] = str1[j + 1];
		}
		str1[j] = tmp;
		if (strcmp(str1,str2)== 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char str1[] = "AABCD";
	char str2[] = "BCDAA";
	printf("%s %s\n", str1,str2);
	//printf("k:");
	//int k = 0;
	//scanf("%d", &k);
	printf("%d",Is_Leftshift_string(str1,str2));
	system("pause");
	return 0;
}