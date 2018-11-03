#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>
void Leftshift_string(char *str, int k)
{
	assert(str);
	int len = strlen(str);
	k %= len;
	int i = 0;
	int j = 0;
	for (i = 0; i<k; i++)
	{
		char tmp = *str;
		for (j = 0; j < len - 1; j++)
		{
			str[j] = str[j + 1];
		}
		str[j] = tmp;
	}
}
int main()
{
	char str[] = "ABCD";
	printf("%s\n", str);
	printf("k:");
	int k = 0;
	scanf("%d", &k);
	Leftshift_string(str, k);
	printf("%s\n", str);
	system("pause");
	return 0;

}