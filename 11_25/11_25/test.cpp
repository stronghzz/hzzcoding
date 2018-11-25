#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Test
{
public:
	Test * operator&()
	{
		return this;
	}
	const Test* operator&()const
	{
		return this;
	}
};
int main()
{
	Test t1;
	const Test t2;
	cout << &t1 << endl;
	cout << &t2 << endl;
	system("pause");
	return 0;
}


//
//class Person
//{
//
//public:
//
//	void SetPersonInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void PrintPersonInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//
//
//
//private:
//	char _name[20];
//	char _gender[3];
//	int _age;
//
//};
//
//
//
//
//
//int main()
//{
//	Person p1;
//	p1.SetPersonInfo("ÐÜ´ó", "¹«", 5);
//	p1.PrintPersonInfo();
//	system("pause");
//	return 0;
//}
//class Student
//{
//public:
//	char _name[20];
//	char _gender[3];
//	int _age;
//	void SetStudentInfo(const char *name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//};
//
//int main()
//{
//
//	Student s;
//	s.SetStudentInfo("Peter", "ÄÐ", 18);
//
//
//	system("pause");
//	return 0;
//}
//void ss(char *s, char t)
//{
//	while (*s)
//	{
//		if (*s == t)
//		{
//			*s = t - 'a' + 'A';
//		}
//		s++;
//	}
//}
//int main()
//{
//	char  str1[100] = "abcddfefdbd", c = 'd';
//	ss(str1, c);
//	printf("%s", str1);
//	
//	system("pause");
//	return 0;
//}