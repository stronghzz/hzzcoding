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
//����
//����������NN��1��500֮����������������ɾȥ�����ظ������֣�����ͬ������ֻ����һ������������ͬ����ȥ����Ȼ���ٰ���Щ����С�������򣬰����źõ�˳�������
//
//���ݷ�Χ�� 1 \le n \le 1000 \1��n��1000  ����������ִ�С���� 1 \le val \le 500 \1��val��500
//����������
//��һ����������������ĸ��� N �� �������� N ��ÿ������һ�������������������ɵ�������� �����ʽ���Բο������"ʾ��"��
//���������
//������У���ʾ�������ݴ����Ľ��
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



//д��һ�����򣬽���һ������ĸ�����ֺͿո���ɵ��ַ�������һ���ַ���Ȼ����������ַ����и��ַ��ĳ��ִ������������ִ�Сд��ĸ��

//���ݷ�Χ�� 1 \le n \le 1000 \1��n��1000

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






//!!!�����ִ�Сд�����Խ���ascll��+32һ��Ҳ++
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



