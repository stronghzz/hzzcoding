#include <stdio.h>
#include <windows.h>
#include<stdlib.h>
#include<assert.h>
//模拟实现strcat


char *Strcat(char *str1, char *str2)
{
	assert(str1);
	assert(str2);
	char *str3 = str1;
	while (*str1)
	{
		str1++;
	}
	while (*str2)
	{
		*str1 = *str2;
		str2++;
		str1++;
	}
	return str3;
}



int main()
{
	char str1[50] = "I love chen";
	char str2[20] = "chen love me";
	printf("%s", Strcat(str1, str2));
	system("pause");
	return 0;
}



//模拟实现strcpy 
//void Strcpy(char *str2, char *str1)
//{
//	assert(str1);
//	assert(str2);
//	while (*str1)
//	{
//		*str2 = *str1;
//		str2++;
//		str1++;
//	}
//}
//int main()
//{
//	char str1[20] = "i am a student";
//	char str2[20] = "0";
//	printf("拷贝前=%s", str2);
//	Strcpy(str2, str1);
//	printf("拷贝后=%s", str2);
//	system("pause");
//	return 0;
//}





//
//void Drink_Num(int money)
//{
//	int price = 1;
//	int bottle = 0;
//	int drink_num = 0;
//	bottle = money / price;
//	drink_num = bottle;
//	while (bottle !=1)
//	{
//		
//		drink_num += bottle / 2;
//		if (bottle % 2 == 0)
//		{
//			bottle = bottle / 2;
//		}
//		else
//		{
//			bottle = bottle / 2 + bottle % 2;
//		}
//	}
//	printf("%d", drink_num);
//}
//
//int main()
//{
//	int money = 20;
//	Drink_Num(money);
//	system("pause");
//	return 0;
//}