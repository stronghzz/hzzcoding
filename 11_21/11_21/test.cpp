#include <iostream>
using namespace std;


int Add(int left, int right)
{
	return left + right;
}
double  Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add(10L, 20L);
	system("pause");
	return 0;
}



//void Test(int a = 0, int b = 0, int c = 0)
//{
//	cout << "a = " << a <<endl;
//	cout << "b = " << b <<endl;
//	cout << "c = " << c <<endl;
//}
//
//
//void Test1(int a , int b = 0, int c = 0)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}



//void Test(int a = 0)
//{
//	cout << a << endl;
//}



//int main()
//{
//	
//	//cout << "change world!!!" << endl;
//	Test();
//	Test1(10);
//
//	system("pause");
//	return 0;
//}





//void Drink_Num(int money)
//{
//	int price = 1;//饮料的价格
//	int bottle = 0; // 空瓶数量
//	int drink_num = 0;//喝了多少瓶
//	bottle = money / price;
//	drink_num = bottle;
//	while (bottle != 1)//当空瓶剩下一个时，循环结束
//	{
//
//		drink_num += bottle / 2;//喝汽水数量
//		bottle = bottle / 2 + bottle % 2;//当空瓶的数量不能被2整除时，我们把余数保存到空瓶数量中，为了下次换饮料。
//
//	}
//	printf("%d", drink_num);
//}
//
//int main()
//{
//	int money = 20;
//	Drink_Num(money);
//	system("pause");
//	return 0;
//}