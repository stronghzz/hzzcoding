#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
int main()
{


		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		int e = 0;

		for (a = 1; a <= 5; a++)
		{
			for (b = 1; b <= 5; b++)
			{
				for (c = 1; c <= 5; c++)
				{
					for (d = 1; d <= 5; d++)
					{
						for (e = 1; e <= 5; e++)
						{
							if (((b == 2) + (a == 3) == 1)
								&& ((b == 2) + (e == 4) == 1)
								&& ((c == 1) + (d == 2) == 1)
								&& ((c == 5) + (d == 3) == 1)
								&& ((e == 4) + (a == 1) == 1))
							{
								//flag = 0;  
			/*					n |= (1 << (a - 1));
								n |= (1 << (b - 1));
								n |= (1 << (c - 1));
								n |= (1 << (d - 1));
								n |= (1 << (e - 1));*/
								if( a * b * c * d * e == 120)
								{
									printf("a = %d b = %d c = %d d = %d e = %d\n", a, b, c, d, e);
								}
							}

						}

					}
				}
			}
		}
		
	
	//int m = 0;
	//int n = 0;
	//int ret = 0;
	//int count = 0;
	//int i = 0;
	//scanf("%d%d", &m, &n);
	//ret = m ^ n;
	//for (i = 0; i < 32;i++)
	//{
	//	if ((ret >> i) & 1 == 1)
	//	{
	//		count++;
	//	}
	//}
	//	printf("%d", count);//011111001111  
	system("pause");    //100011111011
	return 0;
}
//#define  _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <windows.h>
//
//int Digit(n)
//{
//
//	if (n < 10)
//	{
//		printf("%d ", n);
//		return n;
//	}
//	else
//	{
//		Digit(n / 10);
//		printf("%d ", n%10);
//		return n;
//	}
//}
//
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	 Digit(n);
//	system("pause");
//	return 0;
//}