#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int tatol, obj_num;
    while (cin >> tatol >> obj_num)
    {
        int va[61][3] = { 0 };
        int weight[61][3] = { 0 };
        for (int i = 1; i <= obj_num; i++)
        {
            int v, p, q;
            cin >> v >> p >> q;
            if (q)//表示附件
            {
                if (!va[q][1])//表示第一件附件
                {
                    va[q][1] = v;
                    weight[q][1] = v * p;
                }
                else
                {
                    va[q][2] = v;
                    weight[q][2] = v * p;
                }
            }
            else
            {
                va[i][0] = v;
                weight[i][0] = v * p;
            }
        }
        int n = tatol / 10;
        int total_max[3200] = { 0 };
        for (int i = 1; i <= obj_num; i++)
        {
            for (int j = n; j >= va[i][0] / 10; j--)
            {
                int value_total, weight_total;
                total_max[j] = max(total_max[j], total_max[j - va[i][0] / 10] + weight[i][0]);//不带附件
                value_total = va[i][0] / 10 + va[i][1] / 10;
                weight_total = weight[i][0] + weight[i][1];
                if (value_total <= j && va[i][1])//带第一个附件
                {
                    total_max[j] = max(total_max[j], total_max[j - value_total] + weight_total);
                }
                value_total = va[i][0] / 10 + va[i][2] / 10;
                weight_total = weight[i][0] + weight[i][2];
                if (va[i][2] && j >= value_total)//带第二个附件
                {
                    total_max[j] = max(total_max[j], total_max[j - value_total] + weight_total);
                }
                value_total = va[i][0] / 10 + va[i][2] / 10 + va[i][1] / 10;
                weight_total = weight[i][0] + weight[i][2] + weight[i][1];
                if (va[i][1] && va[i][2] && j >= value_total)//带1、2附件
                {
                    total_max[j] = max(total_max[j], total_max[j - value_total] + weight_total);
                }
            }
        }
        cout << total_max[n] << endl;
    }
    return 0;
}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	
//	//int maxint = INT_MAX;
//	//cout << maxint << endl;
//	//cout << sizeof(int) << endl;
//	//cout << sizeof(long) << endl;
//	//cout << sizeof(long long) << endl;
//	//string *str =  new string("hello,world");
//	//cout << *str << endl;
//	//delete str;
//	return 0;
//}