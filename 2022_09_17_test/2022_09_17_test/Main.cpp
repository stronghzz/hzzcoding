#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	vector<string> a;
	a.push_back("hello,world");
	cout << a[0] << endl;


	return 0;
}


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