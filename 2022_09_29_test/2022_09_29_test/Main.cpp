#include <iostream>

class A
{
public:
	int a;
};
//
//class B :protected A
//{
//
//};
int main()
{
	//int i = 10;
	//int* p = &i;
	//int& r = i;
	//int b = 10;
	//int& c = b;
	//std::cout << "sizeofo(p) = " << sizeof(p) << std::endl;
	//std::cout << "sizeofo(r) = " << sizeof(r) << std::endl;
	//return 0;
	//B b;
	//int *a = new int(1);
	//std::cout << *a << std::endl;
	A a;
	A* aa = &a;
	std::cout << &aa << std::endl;
	int b = 2;
	int* d = &b;
	int& c = b;
	c = b + 10;
	std::cout << b << std::endl;
	std::cout << *d << std::endl;
	std::cout << c << std::endl;

	//return 0;
}