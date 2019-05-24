//#include <iostream>
//#include <string>
//using namespace std;
//bool IsNumberOrLetter(char c)
//{
//	if (c >= '0' && c <= '9' ||
//		c >= 'a' && c <= 'z' ||
//		c >= 'A' && c <= 'Z')
//	{
//		return true;
//	}
//	return false;
//}
//bool isPalindrome(string s) {
//	if (s.empty())
//		return true;
//	int begin = 0;
//	int end = s.size() - 1;
//	char* p = (char*)s.c_str();
//	while (begin < end)
//	{
//
//		// 从前往后找一个数字字符或者字母
//		while (begin != end)
//		{
//			if (IsNumberOrLetter(s[begin]))
//				break;
//			++begin;
//		}
//		// 从后往前找一个数字字符或者字母
//		while (begin < end)
//		{
//			if (IsNumberOrLetter(s[end]))
//				break;
//			--end;
//		}
//		if (begin < end)
//		{
//			// 检测start和end位置字符是否相等 或者是否不区分大小的相等
//			if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
//				return false;
//			++begin;
//			--end;
//		}
//	}
//	return true;
//}
//
//
//
//int main()
//{
//	string A;
//	string B;
//	cin >> A;
//	cin >> B;
//	string C = A;
//	int count = 0;
//	A.resize(sizeof(A) + sizeof(B));
//	for (size_t pos = 0; pos <= A.size(); pos++)
//	{
//		A.insert(pos, B);
//		if (isPalindrome(A))
//		{
//			count++;
//		}
//		A = C;
//	}
//	cout << count << endl;
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> arr;
	int n;
	cin >> n;
	arr.reserve(n);
	int temp;
	while (cin>>temp)
	{
		arr.push_back(temp);
	}
	int newmax = 0;
	int oldmax = 0;
	for (size_t i = 0; i <= arr.size(); i++)
	{
		for (size_t j = i; j < arr.size(); j++)
		{
			newmax += arr[j];
			if (newmax >= oldmax)
			{
				oldmax = newmax;
			}
			else
			{
				break;
			}
		}
	}
	cout << oldmax << endl;
	return 0;
}