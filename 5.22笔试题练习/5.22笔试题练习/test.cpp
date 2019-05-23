//#include <iostream>
//#include <fstream>
//#include <cmath>
//using namespace std;
//
//
//int isInt(double x)
//{
//	//long int y = (long int)x;
//	////if ((x-y)!=0)//这段代码可能会丢失精度
//	//if ((x - y) <= 0.0000001 && (x - y) >= -0.0000001) {
//	//return 0;
//	//}
//	//return 1;
//	if (abs(round(x) - x) < 0.000000000000001) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//
//
//
//int main()
//{
//	char arr[4];
//	cin.getline(arr, 4);
//	double A = (arr[0] + arr[2]) / 2;
//	double B = (arr[1] + arr[3]) / 2;
//	double C = (arr[3] - arr[1]) / 2;
//	if (isInt(A) && isInt(B) && isInt(C))
//	{
//		cout << A << ' ' << B << ' ' << C<<endl;
//	}
//	else {
//		cout << "No" << endl;
//	}
//
//	return 0;
//}
//int main()
//{
//
//	char a = 1;
//	char b = -2;
//	char c = a + b;
//	cout << c;
//
//
//	return 0;
//}
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int arr[10];
	int i = 0;
	int m = 0;
	vector<int> sum;
	cin >> arr[i++];

	while ((getchar()) != '\n')
	{
		cin >> arr[i];
	}
	while (arr[0] / arr[1])
	{
		if (m>sum.capacity())
		{

		}
		sum[m] = arr[0] % arr[1];
		arr[0] = arr[0] / arr[1];
		m++;
	}
	for (int j = 0; j < sum.size(); j++)
	{
		cout << sum[i] << endl;
	}
	return 0;
}