#include <cmath>
#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include <map>
using namespace std;




//HJ9 提取不重复的整数
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
//    cin >> n;    //输入键值对的个数
//    map<int, int> m;    //使用map容器，自带键值对数据结构
//    map<int, int>::iterator it;    //map类型的迭代器
//    for (int i = 0; i < n; i++) 
//    {
//        int a, b;
//        cin >> a >> b;        //每行输入一个键值对
//        it = m.find(a);    //查找键a是否存在
//        if (it != m.end()) 
//        {    //如果存在，对键相同的单元的值部分进行求和；
//            m[a] = it->second + b;
//        }
//        else 
//        {        //如果不存在生成新的键值对
//            m[a] = b;
//        }
//    }
//    for (it = m.begin(); it != m.end(); it++) 
//    {    //遍历打印
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








//合并表记录
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





//取近似值
//int main()
//{
//    float x;
//    cin >> x;
//    cout << (int)(x + 0.5) << endl;
//    
//    return 0;
//}


//求指数因子
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
