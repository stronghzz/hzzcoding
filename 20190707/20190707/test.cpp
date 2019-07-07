//跳台阶，一次跳一阶或N阶，共有N阶台阶，有多少种方法？
//跳一阶的时候f(1) = 1; 有2阶的时候有f(2) = 1 + f(1) = 2;有三阶的时候有f(3)=1+f(1)+f(2)=4
//总跳法：f(n) = 1+f(n-1)+f(n-2)+...+f(1) (第一个1是跳N阶只有一种方法）
class Solution
{
public:
	int jumpFloor(int number)
	{
		//2^(n-1) == 1<<(n-1)
		return 1 << (number - 1);
	}
};

