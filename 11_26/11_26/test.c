#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define  N 5



int main()
{
	int min = 0;
	int arr[N];
	int temp = 0;
	printf("ÇëÊäÈë5¸öÊı");
	for (int i = 0; i<N; i++) {
		scanf("%d", &arr[i]);

	}
	for (int j = 0; j<N; j++)
	{
		min = j;
		for (int z = 0; z<N; z++)
		{
			if (arr[min]>arr[z])

			{
				temp = arr[min];
				arr[min] = arr[z];
				arr[z] = temp;

			}
		}
	}

	for (int i = 0; i<N; i++)
	{
		printf("%d", arr[i]);

	}
	system("pause");
	return 0;
}
