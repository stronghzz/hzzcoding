#include <iostream>
#include <algorithm>

using namespace std;





//int main()
//{
//	int A[] = { 2,5,7 };
//	int f[28] = { 0 };
//	int i, j;
//	for (i = 1; i <= 27; i++)
//	{
//		f[i] = INT_MAX;
//		//f[i] = INT_MAX;//ƴ������������
//		for (j = 0; j < 3; j++)
//		{
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
//int main()
//{
//	//int* f = (int*)malloc(sizeof(int) * 28);
//	int f[28] = { 0 };
//	int A[] = { 2,5,7 };
//	//f[0] = 0;
//	int i, j;
//	for ( i = 1; i <= 27; i++)
//	{
//		f[i] = INT_MAX;//ƴ������������
//		for (j = 0; j < 3; j++)
//		{
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
//	cout << f[27];
//	return 0;
//}




//����m��n��
// ���һ�������һ�����
// ���½�������Ϊ��m-1��n-1��
// 
//�ӷ�ԭ�����ظ�������©
//��ʼ����f[0][0] = 1,
//�߽�������i = 0��j = 0,��ǰһ��ֻ����һ���������-��f[i][j] = 1
//����˳�򣬼���0��
//����1��
//2��
//int main()
//{
//	int f[10][10];
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			if (i == 0 || j == 0)
//			{
//				f[i][j] = 1;
//			}
//			else
//			{
//				f[i][j] = f[i - 1][j] + f[i][j - 1];
//			}
//		}
//	}
//	cout << f[9][9];
//
//	return 0;
//}
//int main()
//{
//	int f[10][10];
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			if (i == 0 || j == 0)
//			{
//				f[i][j] = 1;
//			}
//			else
//			{
//				f[i][j] = f[i - 1][j] + f[i][j - 1];
//
//			}
//		}
//	}
//	cout << f[ 9 ][ 9 ];
//	return 0;
//}