#include <iostream>
using namespace std;
int main()
{
	double a;
	double b;
	double temp;
	cin >> a;
	cin >> b;
	if (a > b)
	{
		temp = b;
	}
	else
	{
		temp = a;
	}
	while (1)
	{
		if (((temp / a) - (int)(temp / a) < 0.00001) && (((temp / b) - (int)(temp / b) < 0.00001)))
		{
			cout << (int)temp << endl;

			break;
		}
		temp++;
	}

	return 0;
}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a;
//	int b;
//	int temp;
//	cin >> a;
//	cin >> b;
//	if (a > b)
//	{
//		temp = b;
//	}
//	else
//	{
//		temp = a;
//	}
//	while (1)
//	{
//		if (((double)(temp / a) - (temp / a) < 0.00001) && (((double)(temp / b) - (temp / b) < 0.00001)))
//		{
//			cout << temp << endl;
//
//			break;
//		}
//		temp++;
//	}
//
//	return 0;
//}