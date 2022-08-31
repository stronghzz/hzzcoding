#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;








//int test(int* p)
//{
//	for (int i = 0; i < 499; i++)
//	{
//		for (int j = i+1; j < 500; j++)
//		{
//			if (p[i] == p[j])
//			{
//				
//			}
//			
//		}
//	}
//}
//int main()
//{
//	int arr[500] = { 0 };
//	int N = 0;
//	int i = 0;
//	do
//	{	
//		cin >> N;
//		arr[i] = N;
//		i++;
//	} while (getchar() != '\n');
//	
//	test(arr);
//	//for (int j = 0; j < i; j++)
//	//{
//	//	cout << arr[j] << endl;
//	//}
//	
//	
//
//	
//
//
//
//
//
//	return 0;
//}
//









//两数之和
//int main()
//{
//	vector<int> numbers = { 3,2,4 };
//	int target = 6;
//	vector<int> res;
//	for (int i = 0; i < numbers.size() - 1; i++)
//	{
//		for (int j = i + 1; j < numbers.size(); j++)
//		{
//			if ((numbers[i] + numbers[j]) == target)
//			{
//				res.push_back(i + 1);
//				res.push_back(j + 1);
//				
//			}
//		}
//		
//	}
//	vector<int>::iterator it;
//	for (it = res.begin(); it != res.end(); it++)
//		cout << *it << " ";
//
//	return 0;
//}










//进制转换
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int ans = 0;
//		int bit = 0;
//		for (int i = str.length() - 1; i >= 0; i--)
//		{
//			if (str[i] >= '1' && str[i] <= '9')
//			{
//				ans += (str[i] - '0') * pow(16, bit++);
//			}
//			else if (str[i] >= 'A' && str[i] <= 'F')
//			{
//				ans += (str[i] - 'A' + 10) * pow(16, bit++);
//			}
//		}
//		cout << ans << endl;
//	}
//
//	return 0;
//}
