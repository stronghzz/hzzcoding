#include <cmath>
#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include <map>
using namespace std;




//HJ9 ��ȡ���ظ�������
//int main(void)
//{
//    int n, m = 0;
//    scanf("%d", &n);
//    int a[10] = { 0 };
//    while (n)
//    {
//        if (a[n % 10] == 0)
//        {
//            a[n % 10]++;
//            m = m * 10 + n % 10;
//        }
//        n /= 10;
//    }
//    printf("%d\n", m);
//    return 0;
//}






//int main() {
//    int n;
//    cin >> n;    //�����ֵ�Եĸ���
//    map<int, int> m;    //ʹ��map�������Դ���ֵ�����ݽṹ
//    map<int, int>::iterator it;    //map���͵ĵ�����
//    for (int i = 0; i < n; i++) 
//    {
//        int a, b;
//        cin >> a >> b;        //ÿ������һ����ֵ��
//        it = m.find(a);    //���Ҽ�a�Ƿ����
//        if (it != m.end()) 
//        {    //������ڣ��Լ���ͬ�ĵ�Ԫ��ֵ���ֽ�����ͣ�
//            m[a] = it->second + b;
//        }
//        else 
//        {        //��������������µļ�ֵ��
//            m[a] = b;
//        }
//    }
//    for (it = m.begin(); it != m.end(); it++) 
//    {    //������ӡ
//        cout << it->first << " " << it->second << endl;
//    }
//    return 0;
//}


//
//int cmp(const void* str1, const void* str2)
//{
//    return (*(int(*)[2])str1)[0] - (*(int(*)[2])str2)[0];
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[n][2];
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i][0]);
//        scanf("%d", &arr[i][1]);
//    }
//    qsort(arr, n, sizeof(int(*)[2]), cmp);
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i][0] == arr[i + 1][0] && i < n - 1)
//        {
//            arr[i + 1][1] += arr[i][1];
//        }
//        else {
//            printf("%d %d\n", arr[i][0], arr[i][1]);
//        }
//    }
//    return 0;
//}
//
//








//�ϲ����¼
//int main()
//{
//    int n, a, b, i = 0, num[1000] = { 0 };
//    while (scanf_s("%d", &n) != EOF)
//    {
//        for (i = 0; i < n; i++)
//        {
//            scanf_s("%d %d", &a, &b);
//            num[a] += b;
//        }
//        for (i = 0; i < n; i++)
//        {
//            if (num[i] == 0)
//                continue;
//            else
//                printf("%d %d\n", i, num[i]);
//        }
//    }
//    return 0;
//}





//ȡ����ֵ
//int main()
//{
//    float x;
//    cin >> x;
//    cout << (int)(x + 0.5) << endl;
//    
//    return 0;
//}


//��ָ������
//int main()
//{
//	long n;
//	cin >> n;
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		while (n % i == 0)
//		{
//			cout << i << endl;
//			n /= i;
//		}
//	}
//	if (n != 1)
//		cout << n << " ";
//	return 0;
//
//}
