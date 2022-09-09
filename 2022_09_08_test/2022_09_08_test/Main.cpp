#include <stdio.h>
#include <iostream>
using namespace std;



int main()
{
	int n = 0;
	cin >> n;
	int m = 0;
	while (n)
	{
		m += n % 2;
		n /= 2;
	}
	cout << m;
	


	//int count = 0;
	//int num = 0;
	//cin >> num;
	//if (num % 2 == 1)
	//{
	//	count++;
	//	num /= 2;
	//}
	//cout << count << endl;

	return 0;
}



//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	for (auto &i : arr)
//	{
//		cout << i << endl;
//	}
//
//	return 0;
//}










//class test
//{
//public:
//	void funtest()
//	{
//		cout << "funtest():" << this << endl;
//	}
//};
//
//
//
//
//int main()
//{
//	test* pt = NULL;
//	pt->funtest();
//
//
//	return 0;
//}
