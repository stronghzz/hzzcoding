#include <string>
#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	int b = 1;
	a = a + b++;
	string* str = new string();
	cout << str << endl;
	cout << "He thrusts his fists\n\tagainst";
	cout <<" the post\nand still insists\n\the sees the \"ghost\"";
	return 0;
}


//int main()
//{
//	string str;
//	string str1;
//	getline(cin, str);
//	string::reverse_iterator it;
//	for (it = str.rbegin(); it != str.rend(); it++)
//	{
//		cout << *it;
//	}
//	cout << endl;
//	str1 = str + "a";
//	cout << str1 << endl;
//	
//	return 0;
//}

//template <class T>
//class myString
//{
//public:
//	myString()
//	{
//	}
//	~myString()
//	{}
//	void myprint()
//	{
//		cout << str << endl;
//		
//	}
//private:
//	 T str = 'h';
//};
//
//
//int main()
//{
//	myString<char> str;
//	str.myprint();
//	return 0;
//}

//int main()
//{
//	string str;
//	getline(cin, str);
//	string::reverse_iterator it;
//	string::iterator it_2;
//	it_2 = str.end()-1;
//	cout << *it_2 << endl;
//	for (it = str.rbegin(); it < str.rend(); it++)
//	{
//		cout << *it;
//	}
//	return 0;
//}