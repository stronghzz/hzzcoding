#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
//class String
//{
//public:
//	String(const char* pData = nullptr)
//	{
//		delete[] m_pData;
//		m_pData = nullptr;
//		m_pData = new char[strlen(pData) + 1];
//		strcpy(m_pData, pData);
//	}
//	String(const String& str)
//	{
//
//	}
//	~String(void)
//	{
//		delete[] m_pData;
//	}
//	String& operator =(const String &str)
//	{
//		if (this == &str)
//		{
//			return *this;
//		}
//		delete[] m_pData;
//		m_pData = nullptr;
//		m_pData = new char[strlen(str.m_pData) + 1];
//		strcpy(m_pData, str.m_pData);
//		return *this;
//
//	}
//	void print()
//	{
//		cout << m_pData << endl;
//	}
//
//private:
//	char* m_pData;
//};
//
//int main()
//{
//	String str("hello,world");
//	str.print();
//	string str1("hello,world");
//	cout << str1 << endl;
//	char str2[] = "hello,world";
//	const char* str3 ="hello,world3";
//	cout << *str3 << endl;
//	cout << str2 << endl;
//	
//	return 0;
//
//}


//
//class
//{
//	public sealed class Singletonl
//	{
//
//	};
//}
//class Singleton
//{
//private: 
//	Singleton(){}
//	static Singleton* intance;
//	Singleton& operator=(const Singleton&) = delete;
//public:
//	static Singleton* getInstance()
//	{
//		if (intance == nullptr)
//		{ 
//			intance = new Singleton;
//		}
//		return intance;
//	}
//};

//class Singleton {
//private:
//	Singleton() {
//		std::cout << "constructor called!" << std::endl;
//	}
////	Singleton(Singleton&) = delete;
////	Singleton& operator=(const Singleton&) = delete;
//	static Singleton* m_instance_ptr;
//public:
//	~Singleton() {
//		std::cout << "destructor called!" << std::endl;
//	}
//	static Singleton* get_instance() {
//		if (m_instance_ptr == nullptr) {
//			m_instance_ptr = new Singleton;
//		}
//		return m_instance_ptr;
//	}
//	void use() const { std::cout << "in use" << std::endl; }
//};
//
//Singleton* Singleton::m_instance_ptr = nullptr;
//
//int main() {
//	Singleton* instance = Singleton::get_instance();
//	Singleton* instance_2 = Singleton::get_instance();
//	return 0;
//}
//

//class Singleton
//{
//private:
//	Singleton()
//	{
//		cout << "construction" << endl;
//	}
//	static Singleton* instance;
//public:
//	static Singleton* get()
//	{
//		if (instance == nullptr)
//		{
//			instance = new Singleton;
//			return instance;
//		}
//		return instance;
//	}
//};
//Singleton* Singleton::instance = nullptr;
//
//int main()
//{
//	Singleton* instance1 = Singleton::get();
//
//
//	return 0;
//}

//bool duplicate(int numbers[], int length, int* duplication)
//{
//	if (numbers == nullptr || length <= 0)
//	{
//		return false;
//	}
//	for (int i = 0; i < length; ++i)
//	{
//		if (numbers[i] <0 || numbers[i] > length - 1)
//		{
//			return false;
//		}
//	}
//
//	for (int i = 0; i < length; ++i)
//	{
//		while (numbers[i] != i)
//		{
//			*duplication = numbers[i];
//			return true;
//		}
//		int temp = numbers[i];
//		numbers[i] = numbers[temp];
//		numbers[temp] = temp;
//	}
//	return false;
//}
//
//int main()
//{
//	int arr[] = { 2,3,1,0,2,5,3 };
//	int duplication = 0;
//	bool result = duplicate(arr, sizeof(arr) / sizeof(arr[0]) - 1, &duplication);
//
//	cout << result << endl;
//	cout << duplication << endl;
//
//	return 0;
//}
//
//int getDuplication(const int* numbers, int length)
//{
//	if (numbers == nullptr || length <= 0)
//		return -1;
//	int start = 1;
//	int end = length - 1;
//	while (end >= start)
//	{
//		int middle = ((end - start) >> 1) + start;
//		int count = countRange(numbers, length, start, middle);
//		if (end == start)
//		{
//			
//
//		}
//	}
//}
//
//
//
//
//
//int main()
//{
//
//	int a = 3 / 2;
//	cout << a << endl;
//	return 0;
//}


//
//enum egg_old
//{
//	a,
//	b,
//	c
//};
//
//int main()
//{
//	egg_old egg = egg_old::c;
//
//	cout << egg << endl;
//
//
//
//	return 0;
//}
