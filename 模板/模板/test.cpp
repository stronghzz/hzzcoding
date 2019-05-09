#include <iostream>
using namespace std;

//模板参数分为类型形参和非类型形参
//类型形参：出现在模板参数列表中，是一个类型，如 int double
//非类型形参：模板参数列表中的参数是一个常量，而不是类型
//定义一个模板类型的静态数组
//template<class T,size_t N = 10>
//class Array
//{
//public:
//	T& operator[](size_t index)
//	{
//		return _array[index];
//	}
//	const T& operator[](size_t index)const
//	{
//		return _array[index];
//	}
//	size_t Size()const
//	{
//		return _size;
//	}
//	bool Empty()const
//	{
//		return 0 == _size;
//	}
//private:
//	T _array[N];
//	size_t _size;
//};

//模板的特化
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}
template<>
bool IsEqual<char*>(char*&left,char*& right)
{
	if (strcmp(left, right) > 0)
		return true;
	return false;
}
void Test()
{
	const char* p1 = "hello";
	const char* p2 = "world";
	if (IsEqual(p1, p2))//比较的是指针的大小，也就是地址，谁再前，谁小。
		cout << p1 << endl;
	else
		cout << p2 << endl;
}//此时，需要对模板进行特化

int main()
{
	//Array<int,10> arr;
	//cout << arr.Size() << endl;
	Test();
	return 0;
}




