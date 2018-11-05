
#include <stdio.h>
#include <windows.h>


void Find_num(int arr[], int  len)
{

	int ret = 0;
	int i = 0;
	int j = 0;
	for (j = 0; j < len; j++)
	{
		for (i = j + 1; i < len; i++)
		{
			ret = arr[j] ^ arr[i];
			if (ret == 0)
			{
				arr[i] = 0;//当数组中有相同的数字时，把它们置零
				arr[j] = 0;
			}
		}
	}

	for (i = 0; i < len; i++)
	{
		if (arr[i] != 0)
		{
			printf("%d ", arr[i]);//这时数组中只有单个出现的数字和零，打印非零数字即可
		}
	}
}
int main()
{
	int arr[] = { 1,2,3,1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Find_num(arr, len);
	system("pause");
	return 0;
}
//#include <stdio.h>
//#include <windows.h>
//
//void Find_num(int arr[],int  len)
//{
//
//	int ret = 0;
//	int i = 0;
//	int j = 0;
//	int num[2] = { 0 };
//	int k = 0;
//	for (j = 0; j < len; j++)
//	{
//		for (i = j+1; i < len; i++)
//		{
//			ret = arr[j] ^ arr[i];
//			if (ret == 0)
//			{
//				arr[i] = 0;
//				arr[j] = 0;
//			}
//		}
//		if (ret != 0 && arr[j] !=0)
//		{
//			num[k] = arr[j];
//			k++;
//		}
//	}	
//	
//	for (i = 0; i < 2; i++)
//	{
//		printf("%d ", num[i]);
//	}	
//}
//int main()
//{
//	int arr[] = { 1,2,3,1,2,3,4,5 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Find_num(arr, len);
//	system("pause");
//	return 0;
//}