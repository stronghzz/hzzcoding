
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
int main()
{
	int  ch;
	int count = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch == '{')
		{
			count++;
		}

	

		if (ch == '}' )
		{
			count--;
		}

	}

	if (count == 0)
	{
		printf("∆•≈‰!\n");
	}
	else
	{
		printf("≤ª∆•≈‰!\n");
	}

	system("pause");
	return 0;
}


//	int right = 0;
//	int left = 0;
//	char arr1[13] = { "*************" };
//	for (left = 0; left < 13; left+=2)
//	{
//		int i = 0;
//		for (i = 0; i <=left; i ++)
//		{
//			printf("%c", arr1[left]);
//		}
//		printf("\n");
//
//	}
//	for (left = 12; left >= 0; left -= 2)
//	{
//		int i = 0;
//		for (i = 0; i <= left; i++)
//		{
//			printf("%c", arr1[left]);
//		}
//		printf("\n");
////	}
//	system("pause");
//	return 0;
//
//}