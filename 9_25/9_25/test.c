#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int fun(int a)
{	
	if (a / 10 == 0)
	{
		printf("%d ", a);
		return a;
	}
	else
	{
		fun(a / 10);
		printf("%d ",a%10 );
		return 0;
	}
		
}
int main()
{
	int a = 1234;
	fun(a);
	system("pause");
	return 0;
}
int main()
{
	int n = 0;
	int i = 1;
	int sum = 1;
	scanf("%d", &n);
	
	
	while (i <= n)
	{
		sum *= i;
		i++;
	}
	printf("%d", sum);
	system("pause");
	return 0;
}
int factorial(int n)
{
	if (n == 1||n==0)
	{
		return 1;
	}
	else
	{
		return factorial(n - 1)*n ;
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d",factorial(n));
	system("pause");
	return 0;
}
int main()
{
	char arr[] = "abcdef";
	int sum = 0;
	sum = sizeof(arr) / sizeof(arr[0])-1;
	printf("%d", sum);
	system("pause");
	return 0;
}
int Strlen(char *p,int sz)
{
	if (*p == 0)
	{
		return sz=0;
	}
	else
	{
		return sz=1+Strlen(p + 1, sz + 1);
	}
}
int main()
{
	int sz = 0;
	char arr[] = "abcdef";
	printf("%d", Strlen(arr, sz));
	system("pause");
	return 0;
}
reverse_string(char * arr)
{
	int letf = 0;
	int rigth = strlen(arr)-1;
	while(left<right)
	{
		char temp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
}
int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
	system("pause");
	return 0;
}
DigitSum(int n)
{
	if (n / 10 == 0)
	{
		return n;
	}
	else
	{
		return  DigitSum(n / 10) +n%10;
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d",DigitSum(n));
	system("pause");
	return 0;

int sqr(int k,int n)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k >= 1)
	{
		return n*sqr(k-1,n);

}
int main()
{
	int k = 0;
	int n = 0;
	scanf("%d%d", &n, &k);
	printf("%d",sqr(k,n));
	system("pause");
	return 0;
}
int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	int i = 0;
	for (i = 0; i <n-2; i++)
	{
			c = a + b;
			a = b;
			b = c;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d", fib(n));
	system("pause");
	return 0;
}
int fab(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return fab(n - 1) + fab(n - 2);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d",fab(n));
	system("pause");
	return 0;
}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int temp = 0;
//	scanf("%d%d", &a, &b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 1000; i++)
//	{
//		int j = 0;
//		for (j = 2; j <=sqrt(i); j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (j >sqrt(i) )
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("%d", count);
//	system("pause");
//	return 0;
//}
//int is_prime(int a)
//{
//	int i = 0;
//	for (i=2; i < a / 2; i++)
//	{
//		if (i % 2 == 0)
//		{
//			return -1;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%d",is_prime(a));
//	system("pasuse");
//	return 0;
//}
//void init(int a[], int sz,int  b)
//{
//	int i = 0;
//	for (i = 0; i <=sz; i++)
//	{
//		a[i] = b;
//	}
//}
//void print(int a[], int sz)
//{
//	int i = 0;
//	for (i = 0; i <= sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//void empty(int a[],int  sz)
//{
//	int i = 0;
//	for (i = 0; i <= sz; i++)
//	{
//		a[i] = 0;
//	}
//}
//void reverse(int a[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int temp = 0;
//	while (left < right)
//	{
//		temp = a[left];
//		a[left] = a[right];
//		a[right] = temp;
//		right--;
//		left--;
//
//
//	}
//}
//int main()
//{
//
//	int arr[] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	/*init(arr,sz,1);
//	print(arr,sz);
//	empty(arr, sz);
//	print(arr, sz);*/
//	reverse(arr, sz);
//	print(arr, sz);
//	system("pause");
//}
//void leapyear(year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		printf("是闰年");
//	}
//	else {
//		printf("不是闰年");
//	}
//}
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	leapyear(year);
//	system("pause");
//}
//void swap(int *p1, int *p2)
//{
//	int temp = 0;
//	temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//int main()
//{
//	int a = 0;
//	int b = 1;
////	printf("%d %d\n", a, b);
////	swap(&a, &b);
////	printf("%d %d", a, b);
////	system("pause");
////	return 0;
////}
//void table(a)
//{	
//	int i = 0;
//	int j = 0;
//	for (i=1; i <= a; i++)
//	{
//		for (j=1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	table(i);
//	system("pause");
//	return 0;
//
//
//
//
//
//
//}
//int main()
//{
//	char a, b;
//	scanf("%c", &a);
//	if (a >= 'A' && a <= 'Z')
//	{
//		b = a + 32;
//	}
//	else if ('a' <= a && a <= 'z')   //这里没写对哦
//	{
//		b = a - 32;
//	}
//
//	printf("%c", b);
//	system("pause");
//	return 0;
//}
//  int binary_search(int arr[], int key, int left, int right) 
//  { 
//  	while(left<=right) 
//  	{ 
//  		int mid = left+(right-left)/2; 
//  		if(arr[mid]>key) 
//  		{ 
//  			right = mid-1; 
//  		} 
//  		else if(arr[mid]<key) 
//  		{ 
//  			left = mid+1; 
//  		} 
//  		else 
//  		{ 
//  			return mid; 
//  		} 
//  	} 
//  	return -1; 
//  } 
//   
//  int main() 
// { 
//  	int arr[] = {1,2,3,4,5,6,7,8,9,10}; 
//  	int key = 3; 
//  	int left = 0; 
//  	int right = sizeof(arr)/sizeof(arr[0])-1; 
//   
//  	int ret= binary_search(arr, key, left, right); 
//  	if(ret == -1) 
// 		printf("找不到\n"); 
//  	else 
//  		printf("找到了:%d\n", ret); 
//	system("pause");
// 	return 0; 
//  } 

 // int main() 
 // { 
 // 	int i = 0;  
 // 	
	//char password[20] = { 0 };
	//for(i=0; i<3; i++)
 // 	{ 
 // 		printf("请输入密码:>"); 
 // 		scanf("%s", password); 
 // 		if(0 == strcmp(password, "123456")) 
 // 		{ 
 // 			break; 
 // 		} 
 // 		else 
 // 		{ 
 // 			printf("密码错误,请重新输入！\n"); 
 // 		} 
 // 	} 
 // 	if(i<3) 
 // 	{ 
 // 		printf("登录成功\n"); 
 // 	} 
 // 	else 
 // 	{ 
 //// 		printf("退出程序\n"); 
 //// 	} 

	//system("pause");
 // 	return 0; 
 // } 


