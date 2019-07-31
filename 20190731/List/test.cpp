#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


//template <class T,class C>
//class List
//{
//public:
//	void Push(const T& val)
//	{
//		_con.push_back(val);
//	}
//
//	T& Front()
//	{
//		return _con.front();
//	}
//	T& Back()
//	{
//		return _con.back();
//	}
//	size_t Size()
//	{
//		return _con.size();
//	}
//	bool Empty()
//	{
//		return _con.empty();
//	}
//private:
//	C _con;
//};
//template <class T>
//class test
//{
//public:
//	void print(T& p = vector<int>())
//	{
//		cout << "helo,world" << endl;
//	}
//};
//int main()
//{
	//list<int,vector<int>> l1;
	//l1.push_back(1);
	//list<int>::iterator it = l1.begin();
	//List<int, vector<int>> l3;
	//l3.Push(1);
	//l3.Push(2);
	//l3.Push(3);
	//l3.Push(4);
	//while (!l3.Empty())
	//{
	//	cout << l3.Front() << endl;

	//}

	//cout << *it << endl;
	//list<int> l1;

	//const vector<int>& v1 = vector<int>();
//
//	return 0;
//}
int main()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> a;
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
	return 0;
}