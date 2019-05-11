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
#if 0
//模板的特化
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}
//模板特化
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
}
#endif
#if 0
//类模板
template <class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 d1;
	T2 d2;
};
//全特化
template<>
class Data<int,char>
{
public:
	Data()
	{
		cout << "Data<int,char>" << endl;
	}
	void print()
	{
		
	}
private:
	int d1;
	char d2;
};
//偏特化
//1.部分特化
template<class T>
class Data<T,char>
{
public:
	Data()
	{
		cout << "Data<T,char>" << endl;
	}
};
//2.对模板参数进一步限制
template<class T3,class T4>
class Data<T3*, T4*>
{
public:
	Data()
	{
		cout << "Data<T3*,T4*>" << endl;
	}
};
#endif
#if 0
template <size_t N>
class sum
{
public:
	enum { ret = sum<N - 1>::ret + N };
};
template<>
class sum<1>
{
public:
	enum{ ret = 1 };
};

int main()
{
	//Array<int,10> arr;
	//cout << arr.Size() << endl;
	//Test();
	/*Data<int,int> v1;
	Data<int, char>v2;
	Data<char, char>v3;
	Data<char*, int*>v4;*/
	/*cout<< sum<100>::ret << endl;*/
	return 0;
}
#endif

struct FalseType
{
};

struct TrueType
{
};

template<class T>
struct TypeTraits
{
	typedef FalseType IsPodType;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType IsPodType;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType IsPodType;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType IsPodType;
};

template<>
struct TypeTraits<float>
{
	typedef TrueType IsPodType;
};

// .....

template <class T>
void Copy(T* dst, const T* src, size_t size, TrueType)
{
	memcpy(dst, src, sizeof(T)*size);
	cout << "memcpy" << endl;
}

template <class T>
void Copy(T* dst, const T* src, size_t size, FalseType)
{

	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
	cout << "for copy" << endl;
}

template <class T>
void _Copy(T* dst, const T* src, size_t size)
{
	Copy(dst, src, size, TypeTraits<T>::IsPodType());
}

void fun(int a, int)
{}
int main()
{
	/*fun(3, 4);*/
	int arr[5] = { 1, 2, 3, 4, 6 };
	int arrcopy[5];
	_Copy(arrcopy, arr, 5);
	string str1[5] = { "1", "2", "3", "4", "5" };
	string strcopy[5];
	_Copy(str1, strcopy, 5);
	return 0;
}






