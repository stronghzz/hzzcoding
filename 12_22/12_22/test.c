#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


long long c[105][105];
const int mod = 1000000007;
void init()   //计算组合数
{
	c[0][0] = 1;
	for (int i = 1; i <= 100; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= 100; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
}
int main()
{
	int k;                //歌单总长度
	int a;                //长度为a的歌 
	int b;                //长度为b的歌 
	int x;                //长度为a的歌有x首
	int y;                //长度为b的歌有y首
	long long ans = 0;    //组成歌单的种类数
	init();
	scanf("%d", &k);
	scanf("%d%d%d%d", &a, &x, &b, &y);
	for (int i = 0; i <= x; i++)
	{
		if (i * a <= k && (k - i * a) % b == 0 && (k - i * a) / b <= y) //满足题目的判断条件
		{
			ans = (ans + (c[x][i] * c[y][(k - i * a) / b]) % mod) % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}