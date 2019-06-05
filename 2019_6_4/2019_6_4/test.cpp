#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

//class B
//{
//public:
//	B()
//	{
//		cout << "asdasdadasd-" ;
//	}
//	B(int i) :data(i)
//	{
//		cout << "aaaaaa";
//	}
//	~B()
//	{
//		cout << "bbbbbb";
//	}
//private:
//	int data;
//
//};
//B A(B b)
//{
//	return b;
//}
//
//
//
//int main()
//{
//	B temp = A(5);
//
//
//	return 0;
//}
class A
{
public:
	int GetValue() 
	{
		vv = 1;
		return vv;
	}
private:
	int vv;
};

int main(int arc, int argv[])
{
	//char dog[] = "wang\0miao";
	//int temp = sizeof(dog);
	//int temp1 = strlen(dog);
	char ccstring1[] = "Is Page Fault??";
	char ccstring2[] = "No Page Fault??";
	strcpy(ccstring1, "No");
	if (strcmp(ccstring1, ccstring2) == 0)
		cout << ccstring2;
	else
		cout << ccstring1;
	return 0;
}