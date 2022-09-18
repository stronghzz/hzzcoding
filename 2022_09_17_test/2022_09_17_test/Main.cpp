#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;


int main()
{
	array<int, 3> arr = { 1,2,3 };
	array<char, 3> str = { 'a','b','c' };
	array<int, 3> arr1{ 1,2,3 };
	array<char, 3> str1{ 'a','b','c' };
	return 0;
}



//int main()
//{
//	vector<string> a;
//	a.push_back("hello,world");
//	cout << a[0] << endl;
//	return 0;
//}


//int main()
//{
//    string str;
//    getline(cin, str);
//    string::reverse_iterator it = str.rbegin();
//    for (it; it != str.rend(); it++)
//    {
//        cout << *it;
//    }
//
//}