#include <iostream>
#include <algorithm>
using namespace std;

//2,5,7Ӳ��
int main()
{
	int A[] = { 2,5,7 };
	int M = 27;
	int f[28] = { 0 };
	for (int i = 1; i < 28; i++)
	{
		f[i] = INT_MAX;
		for (int j = 0; j < 3; j++)
		{
			if (i >= A[j] && f[i - A[j]] != INT_MAX)
			{
				f[i] = min(f[i - A[j]] + 1, f[i]);
			}
		}
	}

	cout << f[27] << endl;

	return 0;
}

//int main()
//{
//	int A[] = { 2,5,7 };
//	int M = 27;
//	int f[28] = { 0 };
//	f[0] = 0;
//	int i, j;
//	//f[1] f[2] ....
//	for (i = 1; i <= M; i++)
//	{
//		f[i] = INT_MAX;
//		for (j = 0; j < 3; j++)
//		{         //2>=2              // f[2-2] 
//			if (i >= A[j] && f[i - A[j]] != INT_MAX)
//			{
//				f[i] = min(f[i - A[j]] + 1, f[i]);
//			}
//		}
//	}
//	if (f[27] == INT_MAX)
//	{
//		f[27] = -1;
//	}
//	cout << f[27] << endl;
//	return 0;
//}










//int f(int n)
//{
//	if (n < 2)
//	{
//		return 1;
//	}
//	return f(n - 1) + f(n - 2);
//}
//
//int main()
//{
//	cout << f(20) << endl;
//	return 0;
//}

//���⣺��������Ӳ�ң��ֱ���ֵ2Ԫ��5Ԫ��7Ԫ��ÿ��Ӳ�Ҷ����㹻�࣬��һ������Ҫ27Ԫ�����ʹ�����ٵ�Ӳ��������ø��壬����Ҫ�Է���Ǯ��
//
//int f(int x)
//{
//	if (x == 0)
//	{
//		return 0;
//	}
//	int res = 100;
//	if (x >= 2)
//	{
//		res = min(f(x - 2) + 1, res);
//	}
//	if (x >= 5)
//	{
//		res = min(f(x - 5) + 1, res);
//	}
//	if (x >= 7)
//	{
//		res = min(f(x - 7) + 1, res);
//	}
//	return res;
//}
//
//int main()
//{
//	int x = 27;
//	cout << f(x) << endl;
//	return 0;
//}