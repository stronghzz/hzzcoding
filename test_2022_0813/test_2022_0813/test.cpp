#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
		  
	cout << '8' - '0' << endl;
	printf("%c\n", 98);
	printf("%c\n", 97);
	printf("%d\n", '8' - '0');
	printf("%c\n", 'A');
	//printf("%d\n", '10' );
	
	return 0;
}














//const int maxn = 100 + 10;
//int A[maxn];
//int main()
//{
//	
////	std::cout << "hello,world" << std::endl;
//	long long a, b;
//	//scanf_s("%lld", &a);
//	while (cin >> a >> b)
//	{
//		cout << min(a, b) << "\n";
//	}
//
//
//
//	return 0;
//}




//int main()
//{
//	int a = pow(3, 2);
//
//	cout << a << endl;
//
//
//	return 0;
//}












//
//int main()
//{
//	string str;
//	getline(cin, str);
//	cout << stoi(str, 0, 16) << endl;
//
//
//	return 0;
//


//int main()
//{
//	string str;
//	char ch;
//	getline(cin, str);
//	cin >> ch;
//	int count = 0;
//	for (int i = 0; i < str.length(); i++)
//	{
//		if ('A' < ch < 'Z')
//		{
//			if (ch == str[i] || ch == str[i] + 32)
//			{
//
//			}
//		}
//		if ('a' < ch < 'z')
//		{
//			if (ch == str[i] || ch == str[i] - 32)
//			{
//				count++;
//			}
//		}
//		if (ch == str[i])
//		{
//			count++;
//		}	
//	}
//
//	cout << count << endl;
//
//	return 0;
//}







//int main()
//{
//    string str;
//    cin >> str;
//    size_t count = 0;
//    int flage = 0;
//    getline(cin, str);
//    string::iterator it = str.end() - 1;
//    for (;it != str.begin();it--)
//    {
//        if (*it == ' ')
//        {
//            flage = 1;
//            
//            break;
//        }
//    }
//    it = str.end() - 1;
//    if (flage == 1)
//    {
//        while (!(*it == ' '))
//        {
//            count++;
//            it--;
//        }
//    }
//    else
//    {
//        count = str.size();
//    }
//    cout << count << endl;
//    return 0;
//}
//描述
//明明生成了NN个1到500之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，按照排好的顺序输出。
//
//数据范围： 1 \le n \le 1000 \1≤n≤1000  ，输入的数字大小满足 1 \le val \le 500 \1≤val≤500
//输入描述：
//第一行先输入随机整数的个数 N 。 接下来的 N 行每行输入一个整数，代表明明生成的随机数。 具体格式可以参考下面的"示例"。
//输出描述：
//输出多行，表示输入数据处理后的结果
//int main()
//{
//	int arr[1001] = { 0 };
//	int a = 0;
//	cin >> a;
//	for (int i = 0; i < a; i++)
//	{
//		
//	}
//
//
//
//
//
//	return 0;
//}



//写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）

//数据范围： 1 \le n \le 1000 \1≤n≤1000

//int main()
//{
//	string str;
//	char ch;
//	int count = 0;
//	getline(cin, str);
//	cin >> ch;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == ch)
//		{
//			count++;
//		}
//		else if (str[i] + 32 == ch)
//		{
//			count++;
//		}
//		else if (str[i] - 32 == ch)
//		{
//			count++;
//		}
//	}
//	cout << count << endl;
//
//	return 0;
//}






//!!!不区分大小写，所以进行ascll码+32一样也++
//int main()
//{
//    string str;
//    char s;
//    int count = 0;
//    getline(cin, str);
//    cin >> s;
//    for (int i = 0; i < str.size(); i++)
//    {
//        if (str[i] == s)
//        {
//            count++;
//        }
//        else if (str[i] + 32 == s)
//        {
//            count++;
//        }
//    }
//    cout << count << endl;
//    return 0;
//
//}




//int main()
//{
//	string str;
//	char ch;
//	int count = 0;
//	getline(cin, str);
//	cin >> ch;
////	string::iterator it = str.begin();
//	//while (*it != *str.end())
//	//{
//	//	if (*it == ch)
//	//	{
//	//		count++;
//	//	}
//	//	it++;
//	//}
//	cout << count << endl;
//	return 0;
//}
//





















//void PrintN(int N)
//{
//	if (N)
//	{
//		PrintN(N - 1);
//		printf("%d\n", N);
//	}
//	return;
//}

//void PrintN(int N)
//{
//	int i;
//	for (i = 0; i <= N;i++)
//	{
//		printf("%d\n", i);
//	}
//	return;
//}

//double f(int n, double a[], double x)
//{
//	int i;
//	double p = a[0];
//	for (i = 1; i < n; i++)
//	{
//		p += (a[i] * pow(x, i));
//	}
//	return p;
//}
//
//
//int main()
//{
////	PrintN(100000);
//	double arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	double as = f(5, arr, 5);
//	std::cout << as << std::endl;
//	return 0;
//}

//
//int main() {
//    string str;
//    while (cin >> str)
//    {
//        cout << str << endl;
//        if (cin.get() == '\n') break;
//    }
//    cout << str.size() << endl;
//    cout << str << endl;
//    return 0;
//}
//int main()
//{
//	string str;
//	cin >> str;
//	cout << str << endl;
//
//
//
//	return 0;
//}
//int main()
//{
//	//string str;
//	//while (cin >> str)
//	//{
//	//	cout << str << endl;
//	//	if (cin.get() == '\n') break;
//	//}
//	//cout << str << endl;
//	//cout << "123456\r" << "123";
//	string str;
//	int count = 0;
//	const char* str1 = "hello,world";
//	char str2[] = "lubenweiniubi";
//	strcpy_s(str2, str1);
//	cout << str1 << endl;
//	cout << str2 << endl;
//	//cout << str << endl;
//	//cout << *(str.end()-1);
//	while(getline(cin, str))
//	{
//		//if ((* str.end()) == ' ')
//		//{
//		//	break;
//		//}
//		////(str.end() - 1)--;
//		//count++;
//	}
//	cout << count << endl;
//
//	
//	return 0;
//}



